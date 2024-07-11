/* This file combines three successive sample code segments
   for ease of viewing, editing, and executing */

#include <stdio.h>
#include <string.h>

#define LINES 100 /* max lines to be sorted */
#define MAXLEN 1000

int get_line(char *, int);
int readlines(char *[], int);

int main() /* sort input lines */
{
  char *lineptr[LINES]; /* pointers to text lines */
  int nlines; /* number of input lines read */

  if ((nlines = readlines(lineptr, LINES)) >= 0) {
    sort(lineptr, nlines);
    writelines(lineptr, nlines);
  }
  else
    printf("input too big to sort\n");
  
  return 0;
}

int readlines(char *lineptr[], char *linestor, int maxlines) /* read input lines for sorting*/
{
  int len, nlines;
  char *p, *alloc(), line[MAXLEN];
  *p = linestor;
  char *linestop = linestor + 500;

  nlines = 0;
  while ((len = get_line(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
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

/* The second example code from page 107 of the text book */

writelines(lineptr, nlines) /* write output lines */
char *lineptr[];
int nlines;
{
  int i;

  for (i = 0; i < nlines; i++)
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
