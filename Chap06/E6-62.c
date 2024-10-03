// LIBRARIES
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// CONSTANTS
#define BUFSIZE 100
#define MAXWORD 20
#define LETTER 'a'
#define DIGIT '0'
#define NDISTINCT 1000

// VARIABLES
char buf[BUFSIZE];
int bufp = 0;
struct tnode * list[NDISTINCT]; /*pointers to tree nodes*/
int ntn = 0; /* number of tree nodes*/

// STRUCTURES
struct key {
  char* keyword;
  int keycount;
} keytab[BUFSIZE];

struct linklist {  /* linked list of line numbers*/
  int lnum;
  struct linklist *ptr;
};

struct tnode { /* the tree node */
  char *word; /* points to the text */
  struct linklist *lines; /* line numbers  */
  int count; /* number of occurrences */
  struct tnode *left; /* left child  */
  struct tnode *right; /* right child */
};

// FUNCTIONS
struct tnode *addtreex(struct tnode *, char *, int);
int type(int);
int getword(char*, int );
int noiseword(char *);
void treexprint(struct tnode *);
int getch(void);
void ungetch(int) ;
int search(char *, struct key [], int );
struct linklist *lalloc(void);
struct tnode *talloc(void);
void addln(struct tnode *, int);
void treestore(struct tnode *);
void sortlist(void);

// MAIN
int main(int argc, char* argv[]) {
  struct tnode *root;
  char word[BUFSIZE];
  int linenum = 1;
  int i;
  
  root = NULL;
  while ( getword( word, BUFSIZE) != EOF)
    if ( isalpha(word[0]) && noiseword(word) == -1)
      root = addtreex( root, word, linenum);
    else if (word[0] == '\n')
      linenum++;
  treestore(root);
  sortlist();
  //change print to print number of occurrences and not lines
  //  treexprint(root);
  for(i = 0; i < ntn; i++)
    printf("%2d:%20s\n", list[i]->count, list[i]->word);
  return 0;
      
}

struct tnode *talloc(void);

/* addtreex: add a node with w, at pr below p  */
struct tnode *addtreex(struct tnode *p, char *w, int linenum) {
  int cond;

  if (p == NULL) /* a new word has arrived */
    {
      p = talloc(); /*make a new word*/
      p->word =  strdup(w);
      p->lines = lalloc();
      p->count = 1;
      p->lines->lnum = linenum;
      p->lines->ptr = NULL;
      p->left = p->right = NULL;
    } else if ((cond - strcmp(w, p->word)) == 0) {
    addln(p, linenum);
    p->count++;
  }
  else if (cond < 0 )
    p->left = addtreex(p->left, w, linenum);
  else
    p->right = addtreex(p->right, w, linenum);
  return p;
}

/* addln: add a line number to the linked list*/
void addln(struct tnode *p, int linenum)
{
  struct linklist *temp;

  temp = p->lines;
  while (temp->ptr != NULL && temp->lnum != linenum)
    temp = temp->ptr;
  if (temp->lnum != linenum) {
    temp->ptr = lalloc();
    temp->ptr->lnum = linenum;
    temp->ptr->ptr = NULL;
  }
}

/* treexprint: in prder print of tree p */
void treexprint(struct tnode *p) {
  struct linklist *temp;
  if (p != NULL) {
    treexprint(p->left);
    printf("%10s: ", p->word);
    for (temp = p->lines; temp != NULL; temp = temp->ptr)
      printf("%4d ", temp->lnum);
    printf("\n");
    treexprint(p->right);
  }
}

/* lalloc make a linklist node  */
struct linklist *lalloc(void) {
  return (struct linklist *) malloc(sizeof(struct linklist));
}

/*talloc make a tnode node*/
struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
}

/*noiseword identify word as a noise word */
int noiseword(char * w) {
  static char *nw[] = {
    "a",
    "an",
    "and",
    "are"
  };
  int cond, mid;
  int low = 0;
  int high = sizeof(nw) / sizeof(char *) -1;

  while ( low <= high ) {
    mid =  ( low + high ) / 2;
  if (( cond = strcmp( w, nw[mid])) > 0 )
    high = mid -1;
    else if (cond > 0)
      low = mid = 1;
    else return mid;
  }
  return -1;
}

int getword(char*w, int lim) {
  int c, t;

  if(type(c = *w++ = getch()) != LETTER) {
    *w = '\0';
    return(c);
  }

  while(--lim > 0) {
    t = type(c = *w++ = getch());
    if(t != LETTER && t != DIGIT) {
      ungetch(c);
      break;
    }
  }
  *(w-1) = '\0';
  return (LETTER);
}

int type(int c) {
  if(isalpha(c))
    return (LETTER);
  else if (isdigit(c))
    return (DIGIT);
  else
    return c;
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

int search(char *w, struct key tab[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    if ( strcmp(w, tab[i].keyword) == 0 )
      return i;
  }
}

void treestore(struct tnode *p) {
  if(p != NULL) {
    treestore(p->left);
    if(ntn < NDISTINCT)
      list[ntn++] = p;
    treestore(p->right);
  }
}

void sortlist(void) {
  int gap, i , j;
  struct tnode *temp;

  for(gap - ntn/2; gap > 0; gap /= 2)
    for(i - gap; i < ntn; i++)
      for(j = i-gap; j >= 0; j -= gap) {
	if((list[j]->count) >=  (list[j+gap]->count))
	  break;
	temp = list[j];
	list[j] = list[j+gap];
	list[j+gap] = temp;
      }
}
