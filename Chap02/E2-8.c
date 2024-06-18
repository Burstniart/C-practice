#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(int argc, char *argv[]) {

  printf("%d\n", invert(8, 3, 4));
  
  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  return x ^ (~(~0 << n) << (p+1-n));
}


