#include <stdio.h>
#define MAXLINE 100

double atof(char s[]);
int get_line(char s[], int lim);
  
int main(int argc, char *argv[]) {
  double sum = 0;
  char line[MAXLINE];

  while(get_line(line, MAXLINE) > 0)
    printf("\t%.2f\n", sum += atof(line));
  
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
