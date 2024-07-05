//LIBRARIES
#include <stdio.h>
#include <string.h>
//MACROS

//FUNCTIONS
int get_line(char [], int);
int atoi(char []);
void reverse (char []);
void itoa(int, char []);
int Index(char [], char []);
int getop(char [], int);
int getch(void);
void ungetch(int);
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
  /*
  printf("%s\n", Hello);
  reverse(Hello);
  printf("%s\n", Hello);
  */
  /*
  int Number = 100;
  itoa(Number, Text);
  printf("%s\n", Text);
  */
  /*
  char Find[5] = "d!";
  int NumIndex = Index(Hello, ", ");
  printf("Index of !: %d\n", NumIndex);
  */
  Result = getop(Text, Lim);
  printf("Signal: %d - Operand: %s\n", Result, Text);
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


void itoa(int n, char s[])    /* convert n to characters in s */
{
  char *ps = s;
    int i, sign;

    if ((sign = n) < 0)    /* record sign */
        n = -n;              /* make n positive */
    i = 0;
    do {    /* generate digits in reverse order */
        *ps++ = n % 10 + '0';     /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        *ps++ = '-';
    *ps = '\0';
    reverse(s);
}

int Index(char s[], char t[]) /* return index of t in s, -1 if none */
{
  int i, j, k;
  char *ps = s;
  char *pt = t;
  
  for (i = 0; *ps != '\0'; *ps++, i++) {
    for (j=i, k=0; *pt!='\0' && *ps==*pt; *ps++, *pt++)
      ;
    if (*pt == '\0')
      return(i);
  }
  return (-1) ;
}

int getop(char s[], int lim) /* get next operator or operand */
{
  char *ps = s;
  int i, c;

  while ((c = getch()) == ' ' || c == '\t' || c == '\n')
  if (c != '.' && (c < '0' || c > '9'))
    return(c);
  *ps++ = c;
  for (i = 1; (c = getchar()) >= '0' && c <= '9'; i++)
    if (i < lim)
      *ps++ = c;
  if (c == '.') {  /* collect fraction */
    if (i < lim)
      *ps++ = c;
    for (i++; (c=getchar()) >= '0' && c <= '9'; i++)
      if (i < lim)
        *ps++ = c;
  }
  if (i < lim) {  /* number is ok */
    ungetch(c);
    *ps = '\0';
    return (0);
  } else { /* it's too big; skip rest of line */
    while (c != '\n' && c != EOF)
      c = getchar();
    s[lim-1] = '\0';
    return(9);
  }
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch() /* get a (possibly pushed back) character */
{
  return((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch (int c) /* push character back on input */
{
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
