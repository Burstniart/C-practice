#include <stdio.h>
#define TABS 4


main() {
  int c;
  unsigned int nSpace;
  int mSpaces = 0;

  while((c=getchar()) != EOF) {
    if( c == ' ' && mSpaces < 4) 
      ++mSpaces;
    if (mSpaces == 4) {
      mSpaces = 0;
      putchar('\t');
    }

    else {
      while(mSpaces) {
	putchar(' ');
	--mSpaces;
	}
      if (c != ' ')
	putchar(c);
    }
  }
}
