//LIBRARIES
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//CONSTANTS
#define BUFSIZE 100
#define MAXWORD 20
#define LETTER 'a'
#define DIGIT '0'
#define NKEYS (sizeof(keytab) / sizeof(struct key))

//MACROS

//VARIABLES
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int quote_flag = 0; // turns on while inside of quotes
int dquotes_flag = 0; // turns on while inside of double quotes

//STRUCTURES
struct key {
  char *keyword;
  int keycount;
} keytab[] = {
  "break", 0,
  "case", 0,
  "char", 0,
  "continue", 0,
  "default", 0,
  "unsigned", 0,
  "while", 0
};
//alternate declaration
/*
struct key {
  char *keyword;
  int keycount;
};
struct key keytab[NKEYS];
*/

//FUNCTIONS
int getch( void );
void ungetch(int);
int getword(char *, int);
int type(int);
int binary(char *, struct key[], int);

//MAIN
int main(int argc, char *argv[]){
  int n, t;
  char word[MAXWORD];

  while((t = getword(word, MAXWORD)) != EOF)
    //    printf("%s\n", word);
    if(t == LETTER)
      if((n = binary(word, keytab, NKEYS)) >= 0) {
	if (dquotes_flag == 0 && quote_flag == 0 )
	keytab[n].keycount++;
      }

  for(n = 0; n < NKEYS; n++)
    if(keytab[n].keycount > 0)
      printf("%4d %s\n", keytab[n].keycount, keytab[n].keyword);

  return 0;
}

int getword(char *w, int lim){
  int c, t;
  //
  if(type(c = *w++ = getch()) != LETTER) {
    *w = '\0';
     if (c == '\'') {
      if (quote_flag == 0)
	quote_flag = 1;
      else
	quote_flag = 0;
    }
    if (c == '"') {
      if (dquotes_flag == 0)
	dquotes_flag = 1;
      else
	dquotes_flag = 0;
    }
    return(c);
  }
  //  printf("%c\n",c);
  while(--lim > 0) {
    //
    t = type(c = *w++ = getch());

   
    /*
    switch (c) {
    case('\''): 
      if (quote_flag) {
	quote_flag = 0;
	//	  printf("quote off\n");
      }
      else {
	quote_flag = 1;
	//	  printf("quote on\n");
      }
    case('"'): 
      if (dquotes_flag) {
	dquotes_flag = 0;
	//	  printf("double quotes off\n");
      }
      else {
	dquotes_flag = 1;
	//	  printf("double quotes on\n");
      }
      }
    */

    if(t != LETTER && t != DIGIT) {
      ungetch(c);
      break;
    }
  }
  *(w-1) = '\0';
  return (LETTER);
}

int type(int c) {
  //  if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' )
  if(isalpha(c))
    return (LETTER);
    //  else if(c >= '0' && c <= '9' )
  else if(isdigit(c))
    return (DIGIT);  
  else
    return(c);
}

// find word in tab[0]...tab[n-1]
int binary(char *word, struct key tab[], int n) {
  int low, high, mid, cond;

  low = 0;
  high = n - 1;
  while( low <= high) {
    mid = (low+high) / 2;
    if((cond = strcmp(word, tab[mid].keyword)) < 0)
      high = mid-1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

int getch(void) /* get a (possibly pushed back) character */
{
  return((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch (c) /* push character back on input */
int c;
{
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
