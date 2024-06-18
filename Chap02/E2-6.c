#include <stdio.h>

int wordlenght();

int main(int argc, char *argv[]) {
  printf("%d\n", wordlenght());
  return 0;
}

int wordlenght() {
  unsigned x = 0;
  int y;
  x = ~((~x) >> 1);
  while (x > 0) {
    x /= 2;
    ++y;
  }
  return y;
}
