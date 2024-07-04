//LIBRARIES
#include <stdio.h>
#include <string.h>
//MACROS

//FUNCTIONS
int get_line(char [], int);
int atoi(char []);
void reverse (char []);
//VARIABLES

//MAIN
int main (int argc, char *argv){
  int Lim = 20;
  char Text[Lim];
  int Result;
  char Hello[20] = "Hello, World!";
  /*
  while((Result = get_line(Text, Lim)) > 0)
    printf("%d\n", Result);
  */

  /*
  char Number[10] = "32";
  Result = atoi(Number);
  printf("%s - %d\n", Number, Result);
  */

  printf("%s\n", Hello);
  reverse(Hello);
  printf("%s\n", Hello);
  
  return 0;
}


int get_line(char s[], int lim) /* get line into s, return length */
{
  char *ps = s;
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        *ps++ = c;
    if (c == '\n') {
        *ps++ = c;
        //++i;
    }
    *ps = '\0';
    return(i);
}

int anti(char s[]) /* convert s to integer */
{
  char *ps = s;
    int i, n;

    n = 0;
    for (i = 0; *ps >= '0' && *ps <= '9'; ++*ps)
        n = 10 * n + *ps - '0';
    return(n);
}

void reverse (char s[]) /* reverse string s in place */
{
  char *ps = s;
  char *pj = &s[strlen(s)-1];
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = *ps;
    *ps++ = *pj;
    *pj-- = c;
  }
}
