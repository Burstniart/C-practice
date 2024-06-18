#include <stdio.h>

int main(int argc, char *argv[]) {
  int c, n = 0;
  int limit;
  if (argc == 2) {
    sscanf(argv[1], "%d", &limit);
  }
  
  while((c = getchar()) != EOF) {
    ++n;
    if (n > limit && (c != ' ' || c != '\t')) {
      n = 0;
      putchar('\n');
      putchar(c);
      ++n;      
    }
    else
      putchar(c);
  }
  
  return 0;
}
