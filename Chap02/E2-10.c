#include <stdio.h>

int lower(int l);

int main(int argc, char argv[]) 
{
    int c;
    while((c = getchar()) != EOF)
      putchar(lower(c));

    return 0;
}

int lower(int l) {
  return (l >= 65 && l <= 90) ? l + 32 : l;
}
