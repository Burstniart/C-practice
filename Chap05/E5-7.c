// LIBRARIES
#include <stdio.h>
#include <math.h> // for atof
#include <string.h> // for strlen

//CONSTANTS
#define MAXOP 100 // maz size operand
#define NUMBER '0' // signal that number was found
#define TOOBIG  '9' /* signal that string is too big */

//MACROS

// VARIABLES
int sp = 0; // stack pointer
double val[MAXOP]; // value stack
char buf[MAXOP];   /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */

// FUNCTIONS
char getop(char []);
void ungets(char []);
double push(double);
double pop(void);
double atof(char []);
void clear(void);
void ungetch (int);
int getch(void);              /* get a (possibly pushed back) character */

// MAIN
int main(int argc, char *argv[]) {

  char s[MAXOP];
  double op2;
  
  while(--argc > 0) {
    ungets(" ");
    ungets(*++argv);
    switch(getop(s)) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if(op2 != 0.0)
	push(pop() / op2);
      else
	printf("error: zero division\n");
      break;
    default:
      printf("error: unkown command %s\n", s);
      argc = 1;
      break;
    }
  }
  printf("\t%4.2f\n", pop());
   
  return 0;
}

double pop() /* pop top value from stack */
{
  if (sp > 0)
    return(val[--sp]);
  else {
    printf("error: stack empty\n");
    clear();
    return(0);
  }
}

void clear(void) { // clear stack
  sp = 0;
}


double push(double f) /* push f onto value stack */
{
  if (sp < MAXOP)
    return(val[sp++] = f);
  else {
    printf("error: stack full\n");
    clear();
    return(0);
  }
}

void ungets (char s[])
{
  int len = strlen(s);
  int i = 0;
  while (i < len)
    ungetch(s[i++]);
}

void ungetch (int c) /* push character back on input */
{
  if (bufp >= MAXOP)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

char getop(char s[]) /* get next operator or operand */
{
  int i, c;
  int lim = MAXOP;
  while ((c = getch()) == ' ' || c == '\t' || c == '\n')
    ;
  if (c != '.' && (c < '0' || c > '9'))
    return(c);
  s[0] = c;
  for (i = 1; (c = getchar()) >= '0' && c <= '9'; i++)
    if (i < lim)
      s[i] = c;
  if (c == '.') {  /* collect fraction */
    if (i < lim)
      s[i] = c;
      if (i < lim)
    for (i++; (c=getchar()) >= '0' && c <= '9'; i++)
        s[i] = c;
  }
  if (i < lim) {  /* number is ok */
    ungetch(c);
    s[i] = '\0';
    return (NUMBER);
  } else { /* it's too big; skip rest of line */
    while (c != '\n' && c != EOF)
      c = getchar();
    s[lim-1] = '\0';
    return(TOOBIG);
  }
}

int getch() /* get a (possibly pushed back) character */
{
  return((bufp > 0) ? buf[--bufp] : getchar());
}
