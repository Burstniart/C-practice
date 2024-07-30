/* Tail program: Print last n lines */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINES 100 /* max lines to be sorted */
#define MAXLEN 1000
#define FLAG "-n"
int get_line(char *, int);
int readlines(char *[], char *, int);
void sort( char *[], int );
void writelines(char *[], int);
void writetails(char *[], int, int);

int main(int argc, char *argv[]) /* sort input lines */
{
  char *lineptr[LINES]; /* pointers to text lines */
  int nlines; /* number of input lines read */
  char store[LINES];
  int tails = 10;

  if (strcmp(*++argv, FLAG) <= 0)
    {
      tails = atoi(*++argv);
    }
      
  if ((nlines = readlines(lineptr, store, LINES)) >= 0) {
    //    sort(lineptr, nlines);
    //    writelines(lineptr, nlines);
    if (tails > nlines) tails = nlines;
    writetails(lineptr, nlines, tails);
  }
  else
    printf("input too big to sort\n");
  
  return 0;
}

int readlines(char *lineptr[], char *linestor, int maxlines) /* read input lines for sorting*/
{
  int len, nlines;
  char *alloc(), line[MAXLEN];
  char *p = linestor;
  char *linestop = linestor + 500;

  nlines = 0;
  while ((len = get_line(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = malloc(len)) == NULL)
      return(-1);
    else {
      line[len-1] = '\0'; /* zap newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
  return (nlines);
}

/* The newline at the end of each line is deleted so it 
   will not affect the order in which the lines are sorted. */

void writelines(char *lineptr[], int nlines) /* write output lines */
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

void writetails(char *lineptr[], int nlines, int tail) /* write output lines */
{
  int i;
  //  printf("lines: %d & tail:%d\n",nlines, tail);
  for (i = nlines-tail; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

int get_line(char *s, int lim) /* get line into s, return length */
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

void sort( char *v[], int n) /* sort strings v[0] v[n-1] */
/* into increasing order */
{
  int gap, i, j;
  char *temp;

  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i-gap; j >= 0; j -= gap) {
        if (strcmp(v[j], v[j+gap]) <= 0)
          break;
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
      }
}
