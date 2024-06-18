#include <stdio.h>

main() /* copy input to output; 1st version */
{
  int c;

  while ((c = getchar()) != EOF)
    {
      if (c == '\t')
	printf(">\b-");
      else if (c == '\b')
	printf("<\b-");
      else
	putchar(c);
    }
}    
