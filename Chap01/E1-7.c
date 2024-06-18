#include <stdio.h>

main() /* copy input to output; 1st version */
{
  int c, nextChar;
  
  for (nextChar = 0; (c = getchar()) != EOF; nextChar = c) {
	  if (c == ' ' && nextChar == ' ') 
	    ;
	  else
	    putchar(c);
    }
}    
