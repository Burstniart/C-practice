#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100
#define YES 1
#define NO 0
#define BUFSIZE 100

//VARIABLES
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

struct tnode {            /* the tree node  */
  char* word;             /* points to the text */
  int match;              /* match found */
  struct tnode *left;     /* left child */
  struct tnode *right;    /* right child */
};

struct tnode *addtreex(struct tnode *, char *, int, int *);
struct tnode *talloc(void);

int getch( void );
void ungetch(int);
int compare(char *, struct tnode *, int, int *);
int getword(char *, int);
void treexprint(struct tnode*);
int comment(void);
struct tnode *talloc(void);
struct tnode *addtreex(struct tnode *, char *, int, int *);
  
/* print in alphabetical order each group of variable names identical in the first num characters */
int main(int argc, char *argv[]) {
  struct tnode *root;
  char word[MAXWORD];
  int found = NO; /* YES if match was found*/
  int num;        /* number of the first ident, chars */

  num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 7;
  root = NULL;
  while (getword(word, MAXWORD) != EOF) {
      if (isalpha(word[0]) && strlen(word) >= num)
	root = addtreex(root, word, num, &found);
    }
    
  treexprint(root);
  return 0;
}
/* make a node*/
struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof (struct tnode));
}

/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int num, int *found){
  int cond;
  
  if(p == NULL) {
    p = talloc();
    p->word = strdup(w);
    p->match = *found;
    p->left = p->right = NULL;
  } else if ((cond = compare(w, p, num, found)) < 0)
    p->left = addtreex(p->right, w, num, found);
  else if(cond > 0)
    p->right = addtreex(p->right, w, num, found);
  return p;
}

/* compare word and get p-> match */
int compare(char *s, struct tnode *p, int num, int *found) {
  int i;
  char *t = p->word;

  for(i = 0; *s == *t; i++, s++, t++)
    if(*s == '\0')
      return 0;
  if(i >= num) { /* identical in first num chars ? */
    *found = YES;
    p->match = YES;
  }
  return *s - *t;
}

/* in-order print of tree p if p->match == YES */
void treexprint(struct tnode *p) {
  if(p != NULL) {
    treexprint(p->left);
    if(p->match)
      printf("%s\n", p->word);
    treexprint(p->right);
  }
}


/* get next word or characte from input */
int getword(char *word, int lim){
  int c, d;
  char *w = word;

  while(isspace(c = getch()))
    ;
  if(c != EOF)
    *w++ = c;
  if(isalpha(c) || c == '-' ) {
    for(; --lim > 0 ; w++)
      if(!isalnum(*w = getch()) && *w != '_') {
	ungetch(*w);
	break;
      }
  } else if (c == '\'' || c == '"') {
    for (; --lim > 0; *w++)
      if((*w = getch()) == '\\')
	*++w = getch();
      else if (*w == c) {
	w++;
	break;
      } else if(*w == EOF)
	break;
  } else if (c == '/')
    if((d = getch()) == '*')
      c = comment();
    else
      ungetch(d);
  *w = '\0';
  return c;
}

/* skip over comment and return a character */
int comment(void){
  int c;
  while((c = getch()) != EOF)
    if(c == '*')
      if((c = getch()) == '/')
	break;
      else
	ungetch(c);
  return c;
}

int getch(void) /* get a (possibly pushed back) character */
{
  return((bufp > 0) ? buf[--bufp] : getch());
}

void ungetch (int c) /* push character back on input */
{
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
