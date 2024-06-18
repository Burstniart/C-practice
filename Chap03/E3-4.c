#include <stdio.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void iton(int n, char s[], int b);
void reverse(char s[]);


int main(int argc, char *argv[]) {
  int num = 15;
  char strin[100];
  iton(num, strin, 2);
  printf("bin // %d // %s\n", num,strin);
  iton(num, strin, 16);
  printf("bin // %d // %s\n", num,strin);
  return 0;
}

void iton(int n, char s[], int b) {
  int i, j, sign;

  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do{
    j = n % b;
    s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
  } while ((n /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
