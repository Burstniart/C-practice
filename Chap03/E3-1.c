#include <stdio.h>

#define MAXLINE 100

int main (int argc, char argv[]);
void get_s(char s[]);
void expand (char s[], char t[]);

int main (int argc, char argv[]) {
  char s[MAXLINE], t[MAXLINE];
  get_s(s);
  expand(s, t);
  printf("%s\n", t);
  return 0;
}

void get_s(char s[]) {
  int c, i;
  for (i = 0; (c = getchar()) != EOF; i++) {
    s[i] = c;
  }
  s[i] = '\0';
}

void expand (char s[], char t[]) {
  int i, j;
  for (i = j = 0; i < MAXLINE - 1; i++) {
    switch(s[i])  {
    case '\n':
      t[j++] = '\\';
      t[j++] = 'n';
      break;
    case '\t':
      t[j++] = '\\';
      t[j++] = 't';
      break;
    default:
      t[j++] = s[i];
    }
  }
}
