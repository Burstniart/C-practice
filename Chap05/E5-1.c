//LIBRARIES
#include <stdio.h>
#define BUFSIZE 100

//VARIABLES
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

//FUNCTIONS
int get_int (int *);
int get_float (float *);
int getch( void );
void ungetch(int);

//MAIN
int main(int argc, char *rgv[]){
  int x,y;
  void func();

  x = 43;
  y = 43;
  printf("main x = %d y=%d\n", x,y);
  func(x, &y);
  printf("main x = %d y=%d\n", x,y);

  int n,v, array[BUFSIZE], m;
  float anotherArray[BUFSIZE],b;

  //INT array
  /*
  for (n = 0; n < BUFSIZE && get_int(&v) != EOF; n++)
    array[n] = v;
  for (int i = 0; i <= n; i++)
    printf("%d", array[i]);
  putchar('\n');
  */
  //FLOAT ARRAY
  for (m = 0; m < BUFSIZE && get_float(&b) != EOF; m++)
    anotherArray[m] = b;
  for (int j = 0; j <= m; j++)
    printf("%f ", anotherArray[j]);
  putchar('\n');
  
  char yes = '6';
  yes += 1;
  printf("%d\n", yes);
    /*  
  int point;
  int result = get_int(&point);
  printf("%d\n", result);
  */ 
  return 0;
}

void func(a , pb)
  int a, *pb;
{
  a =1;
  *pb = 2;
}

int get_int(pn) /* get next integer from input */
int *pn;
{
  int c, sign;

  while ((c = getch()) == ' ' || c == '\n' || c == '\t')
  ;   /* skip white space */
  sign = 1;
  if (c == '+' || c == '-') { /* record sign */
    sign = (c=='+') ? 1 : -1;
    c = getch();
  }
  for (*pn = 0; c >= '0' && c <= '9'; c = getch())
    *pn = 10 * *pn + c - '0';
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return(c);
}

int get_float(pn) /* get next integer from input */
float *pn;
{
  int c, sign;
  float power;
  
  while ((c = getch()) == ' ' || c == '\n' || c == '\t')
  ;   /* skip white space */
  sign = 1;
  if (c == '+' || c == '-') { /* record sign */
    sign = (c=='+') ? 1 : -1;
    c = getch();
  }
  for (*pn = 0.0; c >= '0' && c <= '9'; c = getch())
    *pn = 10.0 * *pn + (c - '0');
  printf("looking a point\n");
  if (c == '.') {
    printf("found a point\n");
    c = getch();
  }
  for (power = 1.0; c >= '0' && c <= '9'; c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    power *= 10.0;
  }
  *pn *= sign / power;
  if (c != EOF)
    ungetch(c);
  return(c);
}

int getch(void) /* get a (possibly pushed back) character */
{
  return((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch (c) /* push character back on input */
int c;
{
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
