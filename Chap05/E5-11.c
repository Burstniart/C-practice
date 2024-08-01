/* This file combines three successive sample code segments
   for ease of viewing, editing, and executing */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINES 100 /* max lines to be sorted */
#define MAXLEN 1000
#define FLAGREVERSE "-r"
#define FLAGLINES "-n"

int reverse = 0; // reverse flag

int get_line(char *, int);
int readlines(char *[], char *, int);
void sort( char *[], int, int);
void writelines(char *[], int, int);
 
int main(int argc, char *argv[]) /* sort input lines */
{
  char *lineptr[LINES]; /* pointers to text lines */
  int nlines; /* number of input lines read */
  char store[LINES];
  int args; // counter to read arguments passed on call
  int outlines = 0; //  number of lines passed by -n flag
  argv = 1;
  printf("%s\n",*argv);
  /*
  if (argc > 1 && *++argv == "-r")
    reverse = 1;
  if (argc > 1 && argv[2][0] == '-' && argv[2][1] == 'n')
    outlines = atoi(argv[3]);
  */

  if ((nlines = readlines(lineptr, store, LINES)) >= 0) {
    sort(lineptr, nlines, reverse);
    writelines(lineptr, nlines, outlines);
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

/* The second example code from page 107 of the text book */

void writelines(char *lineptr[], int nlines, int outlines) /* write output lines */
{
  int i;
  printf("%d\n", outlines);
  if (outlines > 0) nlines = outlines;
  
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

void sort( char *v[], int n, int reverse) /* sort strings v[0] v[n-1] */
/* into increasing order */
{
  int gap, i, j;
  char *temp;

  for (gap = n/2; gap > 0; gap /= 2) {
    //printf("gap(half of lines): %d\n",gap);
    for (i = gap; i < n; i++) {
      //printf("i(= gap): %d\n",i);
      for (j = i-gap; j >= 0; j -= gap) {
	//printf("j(i - gap): %d\n",j);
	if (reverse) {
	  if (strcmp(v[j], v[j+gap]) >= 0)
	    //printf("comparing positions %d & %d\n",j,j+gap);
	    break;
	} else {
	  if (strcmp(v[j], v[j+gap]) <= 0) {
	    //printf("comparing positions %d & %d\n",j,j+gap);
	    break;
	  }
	}
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
	//	printf("comparing positions %d & %d\n",j,j+gap);
	//	writelines(v, n, n);
      }
    }
  }
}
