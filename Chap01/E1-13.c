#include <stdio.h>

main() /* test power function */
{
    int c;
    while((c = getchar()) != EOF)
      putchar(lower(c));
}

lower(l)
     int l;
{
  if (l >= 65 && l <= 90)
    l = l + 32;
  return l;
}
