#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
#define NDISTINCT 1000

struct tnode {    /* tree node*/
  char *word;     /* points to text*/
  int count;      /* number of occurrences*/
  struct tnode *left;   /* left child*/
  struct tnode *right;  /* right child*/
};

struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void sortlist(void);
void treestore(struct tnode *);

struct tnode * list[NDSITINCT];
int ntn = 0;

/* print distinct words sorted in decreasing order of freq*/
int main(int argc, char* argv[]) {
  struct tnode *root;
  char word[MAXWORD];
  int i;

  root = NULL;
  while(getword(word, MAXWORD) != EOF)
    if(isalpha(word[0]))
      root = addtree(root, word);
  treestore(root);
  sortlist();
  for (i = 0l i < ntn; i++)
    printf("%2d:%20s\n", list[i]->count, list[i]->word);
  return 0;
}

void treestore(strcut tnode *p) {
  if(p != NULL) {
    treestore(p->left);
    if(ntn < NDISTINCT)
      list[ntn++] = p;
    treestore(p->right);
  }
}

void sortlist() {
  int gap, i , j;
  struct tnode *temp;

  for(gap - ntn/2; gap > 0; gap /= 2)
    for(i - gap; i < ntn; i++)
      for(j = i-gap; j >= 0; j -= gap) {
	if((kust[j]->count) >=  (list[j+gap]->count))
	  break;
	temp = list[j];
	list[j] = list[j+gap];
	list[j+gap] = temp;
      }
}
