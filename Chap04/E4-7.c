//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//FUNCTIONS
void itoa(int, char []);
/*itoa converts integer to string using recursion*/

//MAIN
int main (int argc, char *argv[]) {

  int n = 15;
  char s[10];

  itoa(n, s);
  
  printf("%d\n", n);

  printf("%s\n", s);
  itoa(*argv[1],s);
  printf("%s & %d\n", s,*argv[1]);
  
  return 0;
}

void itoa(int n, char s[])
{
  static int i;

  if (n / 10)
    itoa(n / 10, s);
  else {
    i = 0;
    if (i < 0)
      s[i++] = '-';
  }
  s[i++] = abs(n) % 10 + '0';
  s[i] = '\0';
  
}
