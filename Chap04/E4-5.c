// comp gcc E4-3.c -lm -o e4-3

// LIBRARIES
#include <stdio.h>
#include <math.h>
#include <string.h>

// CONSTANTS
#define MAXOP    20 /* max size of operand, operator */
#define NUMBER  '0' /* signal that number found */
#define TOOBIG  '9' /* signal that string is too big */
#define MAXVAL  100 /* maximum depth of val stack */
#define BUFSIZE 100

// VARIABLES
int sp = 0;          /* stack pointer */
double val[MAXVAL];  /* value stack */
char buf;            /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */

// FUNCTIONS
double push(double );     /* push f onto value stack */
double pop();             /* pop top value from stack */
void clear();             /* clear stack */
void erase();             /* erase top stack */
double atof(char[]);      /* convert string s to double */
char getop(char [], int); /* get next operator or operand */
void ungetch (int );      /* push character back on input */
int getch();              /* get a (possibly pushed back) character */
  
int main() /* reverse Polish desk calculator */
{
  int type, i, var = 0;
  char s[MAXOP];
  double op2, atof(), pop(), push(), variable[26];

  for (i = 0; i < 26; i++)
    variable[i] = 0.0;
  while ((type = getop(s, MAXOP)) != EOF) {
    switch (type) {
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
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("zero divisor popped\n");
        break;
    case '=':
      printf("\t%f\n", push(pop()));
      if (type >= 'A'  && type <= 'Z')
	variable[var - 'A'] = push(pop());
        break;
    case 'c':
        clear();
        break;
    case TOOBIG:
        printf("%.20s ... is too long\n", s);
        break;
    /* EXERCISE 4-3 */
    case '%':
        op2 = pop();
	if (op2 != 0.0)
	  push(fmod(op2, pop()));
	else
	  printf("zero divisor popped\n");
        break;
    case 'n':
      push(pop() * -1);
      break;
    case 'e':
      erase();
      break;
    /* END EXERCISE */
    default:
      if (type >= 'A'  && type <= 'Z')
	push(variable[type - 'A']);
      else
	printf("unknown command %c\n", type);
      break;
    }
    var = type;
  }
  return 0;
}

double push(double f) /* push f onto value stack */
{
  if (sp < MAXVAL)
    return(val[sp++] = f);
  else {
    printf("error: stack full\n");
    clear();
    return(0);
  }
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

void clear() /* clear stack */
{
  sp = 0;
}

void erase() /* erase top stack */
{
  val[sp--] = 0;
}

double atof(char s[]) /* convert string s to double */
{
  double val, power;
  int i, sign, e, j, Exp_Value, Exp_Sign;

  for (i=0; s[i]==' ' || s[i]=='\n' || s[i]=='\t'; i++)
    ;     /* skip white space */
  sign = Exp_Sign = 1;
  
  if (s[i] == '+' || s[i] == '-') /* sign */
    sign = (s[i++]=='+') ? 1 : -1;
  for (val = 0; s[i] >= '0' && s[i] <= '9'; i++)
    val = 10 * val + s[i] - '0';
  if (s[i] == '.')
    i++;
  for (power = 1; s[i] >= '0' && s[i] <= '9'; i++) {
    val = 10 * val + s[i] - '0';
    power *= 10;
  }

  if (s[i] == 'e' || s[i] == 'E')
    i++;
  if (s[i] == '+' || s[i] == '-') /* sign */
    Exp_Sign = (s[i++]=='+') ? 1 : -1;
  for (Exp_Value = 0; s[i] >= '0' && s[i] <= '9'; i++)
    Exp_Value = 10 * Exp_Value + s[i] - '0';
  for (j = 0, e = 1; j<Exp_Value; j++)
    e *= 10;
  return((sign * val / power) * (Exp_Sign * e ));	
}

char getop(char s[], int lim) /* get next operator or operand */
{
  int i, c;

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
  int c;
  
  if (buf != 0)
    c = buf;
  else
    c = getchar());
  buf = 0;
  return c;

}

void ungetch (int c) /* push character back on input */
{
  if (buf != 0)
    printf("ungetch: too many characters\n");
  else
    buf = c;
}

void ungets (char s[])
{
  int len = strlen(s);
  int i = 0;
  while (i < len)
    ungetch(s[i++]);
}
