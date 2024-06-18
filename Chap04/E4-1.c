#include <stdio.h>
#define MAXLINE 1000

rindex (char s[], char t[]);
index(char s[], char t[]);
int get_line(char s[], int lim);

int main (int argc, char *argv[]) {
  char line[MAXLINE];
  int point;
  while(get_line(line, MAXLINE) > 0)
    ( point = rindex(line, "the") ) >=0 ? printf("%s\n%d", line, point) : 0;
  return 0;
}

int get_line(char s[], int lim) /* get line into s, return length */
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return(i);
}

index(char s[], char t[]) /* return index of t in s, -1 if none */
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (t[k] == '\0')
      return(i);
  }
  return (-1) ;
}

rindex (char s[], char t[])
{
  int i, j, k, last;
  int found = 0;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (t[k] == '\0') {
      found++;
      last = i;
    }
  }
  if (found)
    return last;
  else
    return (-1) ;
}
