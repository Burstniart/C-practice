#include <stdio.h>

unsigned rightrot(unsigned x, int n);
int wordlength();

int main(int argc, char *argv[]) {
  printf("%d\n", wordlength());
  printf("%d\n",rightrot(5, 2));
  return 0;
}

unsigned rightrot(unsigned x, int n) {
  int wordlength();
  int rbit;

  while(n-- > 0) {
    rbit = (x & 1) << (wordlength() -1);
    x = x >> 1;
    x = x | rbit;
  }
  return x;
}

int wordlength() {
  unsigned x = 0;
  int y;
  x = ~((~x) >> 1);
  while (x > 0) {
    x /= 2;
    ++y;
  }
  return y;
}
