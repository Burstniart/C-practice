#include <stdio.h>
void show(char *);

int main(int argc, char *argv) {
  char text[20] = "this a text";
  show(text);
  return 0;
}

void show(char *a) {

  while ( *a != '\0')
    putchar(*a++);
  putchar('\n');
  
}
