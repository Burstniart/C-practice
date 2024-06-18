#include <stdio.h>

main()
{
  int c, nextChar;
  for(nextChar = 0; (c = getchar()) != EOF; nextChar = c) {
    if (nextChar == ' ' && c == ' ')
      ;
    else if(c == ' ' || c == '\t')
	putchar('\n');
    else
      putchar(c);
  }
}
