#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 100
#define BUFSIZE 100
#define ALLOCSIZE 1000 // size of available space

// VARIABLES
char buf[BUFSIZE];
int bufp = 0;
static struct nlist *hashtab[HASHSIZE]; /* pointer table*/
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

// STRUCTURES
struct nlist { /*basic table entry*/
  char *name;
  char *def;
  struct nlist *next; /* next entry in chain*/
};


// FUNCTIONS
int getch(void);
void ungetch(int);
int hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
char *alloc(int);
void freee(char *);


int main(int argc, char * arg[]) {

  return 1;
}

int hash(char *s) {
  int hashval;

  for(hashval = 0; *s != '\0'; )
    hashval += *s++;
  return (hashval % HASHSIZE);
}

struct nlist *lookup(char *s) {
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s,np->name) == 0)
      return (np); /*found it*/
}

struct nlist *install(char *name, char *def) {
  struct nlist *np, *lookup();
  int hashval;
  if ((np = lookup(name)) == NULL) { /*not found*/
    np = (struct nlist *) alloc(sizeof(*np));
    if(np == NULL)
      return(NULL);
    if((np->def = strdup(name)) == NULL)
      return(NULL);
    hashval = hash(np->name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else /* already there*/
    free(np->def); /*free previous definition*/
  if((np->def = strdup(def)) == NULL)
    return(NULL);
  return(np);
}

struct nlist *uninstall(char *name, char *def) {
  struct nlist *np, *lookup();
  int hashval;
  if ((np = lookup(name)) == NULL) { /*not found*/
    np = (struct nlist *) alloc(sizeof(*np));
    if(np == NULL)
      return(NULL);
    if((np->def = strdup(name)) == NULL)
      return(NULL);
  } else /* already there*/
    free(np->def); /*free previous definition*/
  if((np->def = strdup(def)) == NULL)
    return(NULL);
  return(np);
}

//return pointer to n characters
char *alloc(int n) {
  if(allocp + n <= allocbuf + ALLOCSIZE) {
    allocp += n;
    return(allocp - n); /*old p*/
  } else /*not enough room*/
    return (NULL);
}

// free storage pointed to by p
void freee(char *p) {
  if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

int getch(void) {
  return ((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch(int c) {
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
