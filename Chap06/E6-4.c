#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode {            //the tree node 
  char *word;             // points to the text
  struct linklist *lines; // line numbers
  struct tnode *left;     // left child
  struct tnode *right;    // right child
};

struct tnode *addtreex{struct tnode *, char *, int};
int getword(char *, int);
void treexprint(struct tnode*);

//print in alphabetical order each group of variable names identical in the first num characters
int main(int argc, char *argv) {
  struct tnode *root;
  char word[MAXWORD];
  int found = NO; //YES if match was found
  int num;        //number of the first ident, chars

  num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 7;
  root = NULL;
  while (getword(word, MAXWORD) != EOF) {
      if (isalpha(word[0]) && strlen(word) >= num)
	root = addtreex(root, word, num, &found);
    }
  
  treexprint(root);
  
  
  return 0;
}
