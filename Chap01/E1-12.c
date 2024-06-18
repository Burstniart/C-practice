#include <stdio.h>

main() /* count digits, white space, others */
{
  int c, i, ii, nword, nother;
    int inword = 0;
    int ndigit[10];

    nword = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
      ++nother;
    if (c == ' ' || c == '\n' || c == '\t') {
      ndigit[nword++] = nother - 1 ;
      nother = 0;
      inword = 0;
    }
    else if ( inword = 0) {
      inword = 1;
      ++nword;
    }
}

    for (ii = 0; ii < 10; ++ii) {
      /* printf("%d", ndigit[ii]); */
      if (ndigit[ii] == 0)
	break;
      
      printf("\n=|"); 
      
      for (i = 0; i < ndigit[ii]; ++i) {
	printf("*");
      }
      printf("\n");
    }
}
