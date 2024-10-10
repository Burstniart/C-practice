#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 100

static struct nlist *hashtab[HASHSIZE]; /* pointer table*/

struct nlist { /*basic table entry*/
  char *name;
  char *def;
  struct nlist *next; /* next entry in chain*/
};

int hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);

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
      return (np); /*fouund it*/
}

struct nlist *install(char *name, char *def) {
  struct nlist *np, *lookup();
  int hashval;
  if ((np = lookup(name)) == NULL) { /*not found*/
    np = (struct nlist *) malloc(sizeof(*np));
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
