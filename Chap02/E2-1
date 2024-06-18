#include <stdio.h>

/*
//Rewrite the loop without using &&
for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
     s[i] = c;
*/

int main (int argc, char argv[]) {

  int i = 0;
  int c;
  int lim = 100;
  char s[lim];
  while ( i<lim-1 ) {
    c = getchar();
    if (c == EOF || c == '\n')
	break;
    s[i] =c;
    i++;
  }
  s[i] = '\0';
  printf("%s\n",s);
  return 0;
}
