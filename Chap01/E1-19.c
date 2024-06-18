#include <stdio.h>
#define TABS 4


main() {
  int c;
  unsigned int nSpace;

  while((c=getchar()) != EOF) {
    if(c=='\t') {
      nSpace = TABS;

      while(nSpace) {
	putchar(' ');
	--nSpace;
      }
    }
    else
      putchar(c);
  }
}
