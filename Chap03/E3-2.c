#include <stdio.h>

#define MAX 100

int main(int argc, char *argv[]);
void expand(char s1[], char s2[]);


int main(int argc, char *argv[]) {
  char s1[MAX] = "0-9a-zA-B-F";
  char s2[MAX];
  expand(s1, s2);
  printf(";;%s\n;;%s\n",s1, s2);
  return 0;
}

void expand(char s1[], char s2[]) {
  char c;
  int i ,j;
  i = j = 0;
    while((c = s1[i++]) != '\0') {
      if (s1[i] == '-' && s1[i+1] >= c) {
	i++;
	while (c < s1[i])
	  s2[j++] = c++;
      } else {
	s2[j++] = c;
      }
      s2[j] = '\0';
    }
}
