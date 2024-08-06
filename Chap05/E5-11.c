#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINES 100 /* max number of lines to be sorted */
#define MAXLEN 1000

void sort(char *[], int, int (*)(), int (*)(), int); //sort strings v[0]...v[n-1]
void writelines(char *[], int); /* write output lines */
int readlines(char *[], char *, int); /* read input lines for sorting*/
int get_line(char *, int); /* get line into s, return length */
  
int main(int argc, char *argv[])
{
  char *lineptr[LINES]; //pinter to text lines
  int nlines; // number of input lines read
  int strcmp(), numcmp(); // comparison functions
  int swap(); // exchange functions
  int numeric = 0; // 1 if numeric sort
  int reverse = 0;
  char store[LINES];

  int i;
  if (argc > 1 && argv[1][0] == '-')
    for (i = 1; i < strlen(argv[1]); i++) {
      char c = argv[1][i];
      switch (c) {
      case 'n':
	numeric = 1;
	break;
      case 'r':
	reverse = 1;
	break;
      default:
	break;
      }
    }

  if ((nlines = readlines(lineptr, store, LINES)) >= 0) {
    if (numeric)
      sort(lineptr, nlines, numcmp, swap, reverse);
    else
      sort(lineptr, nlines, strcmp, swap, reverse);
    writelines(lineptr, nlines);
  } else
    printf("input too big to sort\n");
  return 0;
}

// int(*comp)() means pointer to function that returns int
// int *comp()  means function that returns int opinter

void sort(char *v[], int n, int(*comp)(), int (*exch)(), int reverse) //sort strings v[0]...v[n-1]
{
  int gap, i, j, dif;
  for(gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i-gap; j >= 0; j-= gap) {
	dif = (*comp)(v[j], v[j+gap]);
	if (reverse == 1 && dif > 0) 
	  break;
	else if (reverse == 0 && dif <= 0)
	  break;
		/*
	//if (reverse)
	  if ((*comp)(v[j], v[j+gap]) > 0)
	    break;
	else
//	*/
	
	/*
	  if ((*comp)(v[j], v[j+gap]) <= 0)
	    break;
	    */
	(*exch)(&v[j], &v[j+gap]);
      }
}


int numcmp(char *s1, char *s2){
  double atof(), v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return (0);
}

int swap(char *px[], char *py[]){
  char *temp;

  temp = *px;
  *px = *py;
  *py = temp;
}

void writelines(char *lineptr[], int nlines) /* write output lines */
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
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
