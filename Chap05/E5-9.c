// LIBRARIES
#include <stdio.h>

//CONSTANTS
#define MAXLINE 100 // maximum line size
#define TABINC 4    // default tab size
#define YES  1
#define NO   0

//MACROS

// VARIABLES

// FUNCTIONS
void esettab(int, char *[], char *);
void entab(char *);
int tabpos(int, char *);
int atoi(char *);
void detab(char *);

// MAIN
// replace strings of blanks with tabs
int main(int argc, char *argv[]) {
  char tab[MAXLINE + 1];

  
  esettab(argc, argv, tab); // initialize tab stops
  entab(tab); // replace w/ tab
  //  detab(tab);
  
  return 0;
}

void entab(char *tab) {
  int c, pos;
  int nb = 0; // # of blanks necessary
  int nt = 0; // # of tabs necessary

  for(pos = 1; (c=getchar()) != EOF; pos++)
    if(c == ' '){
      if(tabpos(pos, tab) == NO)
	++nb; // increment # of blanks
      else {
	nb = 0; // reset # of blanks
	++nt;   // one more tab
      }
    } else {
      for ( ; nt > 0; nt--)
	putchar('\t'); // output tab(s)
      if(c == '\t') // forget the blanks
	nb = 0;
      else // output blanks
	for( ; nb > 0; nb--)
	  putchar(' '); // output blank(s)
      putchar(c);
      if(c =='\n')
	pos = 0;
      else if(c == '\t')
	while(tabpos(pos, tab) != YES)
	  ++pos;
    }
}

// set tab stops in array
void esettab(int argc, char *argv[], char *tab){
  int i, inc, pos;

  if (argc <= 1) // default tab stops
    for (i = 1; i <= MAXLINE; i++)
      if (i % TABINC == 0)
	tab[i] = YES;
      else
  	tab[i] = NO;
  else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+') {
    pos = atoi(&(*++argv)[1]);
    inc = atoi(&(*++argv)[1]);
    for (i = 1; i <= MAXLINE; i++)
      if (i != pos)
	tab[i] = NO;
      else {
	tab[i] = YES;
	pos += inc;
      }
  }
  else {  // user provided tab stops
    for (i = 1; i <= MAXLINE; i++)
      tab[i] = NO; // turn off all tab stops
    while (--argc > 0) // walk through argument list
    { 
      pos = atoi(*++argv);
      if (pos > 0 && pos <= MAXLINE)
	tab[pos] = YES;
    }
  }
}

// determine if pos is at a tab stop
int tabpos(int pos, char *tab)
{
  if (pos > MAXLINE)
    return YES;
  else
    return tab[pos];
}

// replace tab with blanks
void detab(char *tab) {
  int c, pos = 1;

  while ((c=getchar()) != EOF)
    if (c == '\t') // tab character
      {
      do
	putchar(' ');
      while(tabpos(pos++, tab) != YES);
      } else if (c == '\n') { // newline character
      putchar(c);
      pos = 1;
    } else {
      putchar(c);
      ++pos;
    }
}
