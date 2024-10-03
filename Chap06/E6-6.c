#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100
#define NDISTINCT 1000
#define LETTER 'a'
#define DIGIT '0'

// VARIABLES
char buf[BUFSIZE];
int bufp = 0;
struct tnode * list[NDISTINCT]; /*pointers to tree nodes*/
int ntn = 0; /* number of tree nodes*/

// STRUCTURES
struct tnode {    /* tree node*/
  char *word;     /* points to text*/
  int count;      /* number of occurrences*/
  struct tnode *left;   /* left child*/
  struct tnode *right;  /* right child*/
};

// FUNCTIONS
struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void sortlist(void);
void treestore(struct tnode *);
int type(int);
int getch(void);
void ungetch(int);
struct tnode *talloc(void);

/* print distinct words sorted in decreasing order of freq*/
int main(int argc, char* argv[]) {
  struct tnode *root;
  char word[MAXWORD];
  int i, t;

  root = NULL;
  while(getword(word, MAXWORD) != EOF)
    if(isalpha(word[0]))
      root = addtree(root, word);
  treestore(root);
  sortlist();
  for (i = 0; i < ntn; i++)
    printf("%2d:%20s\n", list[i]->count, list[i]->word);
  return 0;
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

int getword(char *w, int lim){
  //rebuild this piece on top of 6.5 and see if it works
  printf("%c \n"),w;
  int c, t;
  if(type(c = *w++ = getch()) != LETTER) {
    printf("hello \n"),c;
    printf("%s \n"),c;
    *w = '\0';
    return(c);
  }
  printf("%s \n", *w);
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

struct tnode *addtree(struct tnode *p, char *w) {
  struct tnode *talloc();
  char *strsave();
  int cond;
  
  if(p == NULL) {
    p = talloc();
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if((cond = strcmp(w,p->word)) == 0)
    p->count++;
  else if(cond < 0)
    p->left = addtree(p->left, w);
  else 
    p->right = addtree(p->right, w);  
  return p;
}

struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
}
