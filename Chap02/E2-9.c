#include <stdio.h>

unsigned bitcount(unsigned x);

int main(int argc, char *argv[]) {

  printf("%d\n", bitcount(5));
  
  return 0;
}

unsigned bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x &= (x - 1))
    b++;
  return b;
}


