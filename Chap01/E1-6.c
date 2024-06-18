#include <stdio.h>

main() /* count lines in input */
{
  int c, nl, blnk, tbs;

    nl = 0;
    while ((c = getchar()) != EOF)
      {
      if (c == '\n')
	++nl;
      else if (c == '\t')
	++tbs;
      else if (c == ' ')
	++blnk;
      }
     printf("Newlines: %d, Blanks: %d, Tabs: %d\n", nl, blnk, tbs);
     
}
