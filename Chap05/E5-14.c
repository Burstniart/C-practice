#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LINES 100 /* max number of lines to be sorted */
#define MAXLEN 1000

void sort(char *[], int, int (*)(), int (*)(), int); //sort strings v[0]...v[n-1]
void writelines(char *[], int); /* write output lines */
int readlines(char *[], char *, int); /* read input lines for sorting*/
int get_line(char *, int); /* get line into s, return length */
int strcmpcase(char *, char *); // string compare case unsensitive
void lowerit(char *);  // lower case the string
int charcmp (char *, char *); // compare in dictionary oder
int isnum(char);
//int atoi(char *);
void error(char *);
void substr(char *, char *);

static char fold = 0;
static char dir = 0;
char option = 0;
int pos1;
int pos2;

int main(int argc, char *argv[])
{
  char *lineptr[LINES]; //pinter to text lines
  int nlines; // number of input lines read
  int strcmp(), numcmp(), strcmpcase(); // comparison functions
  int swap(); // exchange functions
  int numeric = 0; // 1 if numeric sort
  int reverse = 0;
  char store[LINES];
  
  /*
  int i = 0;
  char c = argv[0][i];
  if (argc > 1 && argv[1][0] == '-')
    for (i = 1; i < strlen(argv[1]); i++) {
      c = argv[1][i];
      switch (c) {
      case 'n':
	numeric = 1;
	break;
      case 'r':
	reverse = 1;
	break;
      case 'f':
	fold = 1;
	break;
      case 'd':
	dir = 1;
	break;
      default:
	break;
      }
    } else if (c = '-') {
    pos2 = atoi(argv[0]+1);
  }
  */
  int c;
  //  printf("flag \n");
  while(--argc > 0 && (c=(*++argv)[0]) == '-' || c == '+') {
    //    printf("arg is %c\n",c);
    if (c == '-' && !isdigit(*(argv[0]+1)))
      while (c = *++argv[0]) 
	//		printf(" parameter3\n");
	switch (c) {
	case 'n':
	  numeric = 1;
	  break;
	case 'r':
	  reverse = 1;
	  break;
	case 'f':
	  fold = 1;
	  break;
	case 'd':
	  dir = 1;
	  break;
	default:
	  printf("error syntax parameter\n");
	  break;
	}
    else if (c == '-') {
      //      printf("got pos2\n");
      pos2 = atoi(argv[0]+1);
    }
    else if (c == '+' && (pos1 = atoi(argv[0]+1)) < 0) {
      //      printf("got pos1\n");
      error("Usage: sort -dfnr [+pos1] [-pos2]");
    }
  }
  if (argc || pos1 > pos2)
    error("Usage: sort -dfnr [+pos1] [-pos2]");
  //  printf("pos1 %d\n", pos1);
  //  printf("pos2 %d\n", pos2);

  
  //  printf("pos1 %d\n", pos1);
  if ((nlines = readlines(lineptr, store, LINES)) >= 0) {
    if (numeric)
      sort(lineptr, nlines, numcmp, swap, reverse);
    else if (dir) {
      sort(lineptr, nlines, charcmp, swap, reverse);
    } else
         //  sort(lineptr, nlines, strcmp, swap, reverse);
      //      sort(lineptr, nlines, strcmpcase, swap, reverse);
      sort(lineptr, nlines, charcmp, swap, reverse);
    putchar('\n');
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
	//	printf("%d\n", dif);
	if (reverse == 1 && dif > 0) 
	  break;
	else if (reverse == 0 && dif <= 0)
	  break;
	(*exch)(&v[j], &v[j+gap]);
      }
}

void substr(char *s, char *str){
  int i, j ,len;
  extern int pos1, pos2;
  len - strlen(s);
  if (pos2 > 0 && len > pos2)
    len = pos2;
  else if (pos2 > 0 && len < pos2)
    error("substr: string too short");
  for (j = 0, i = pos1; i < len; i++, j++)
    str[j] = s[i];
  str[j] = '\0';
}

int strcmpcase(char *s, char *t) {

  if (fold) {
    lowerit(s);
    lowerit(t);
  }
  
  for ( ; *s == *t; s++, t++) {
    if (*s == '\0')
      return (0);
  }
  return(*s - *t);
}

// Compare as dictionary
int charcmp (char *s, char *t) {
  //    printf("dir\n");
  char a, b;
  int i, j, endpos;
  //int pos1, pos2;
  //  printf("flag 8\n");
  //  printf("pos1 %d\n", pos1);
  //  printf("pos2 %d\n", pos2);
  
  i = j = pos1;
  if (fold) {
    printf("folding\n");
    lowerit(s);
    lowerit(t);
  }
  //  printf("flag \n");
  if (pos2 > 0)
    endpos = pos2;
  else if ((endpos = strlen(s)) > strlen(t))
    endpos = strlen(t);
  //  printf("flag 2\n");
  do {
    //    printf("flag 3\n");
      while(i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0'){
	//	printf("input \n");
	//	printf("%s \n",s);
	i++;
	//	s++;
    }
      while(j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0'){
	//	printf("%s \n",*t);
	j++;
	//	t++;
	//	printf("flag 4\n");
      }
    if (i < endpos && j < endpos) {
      a = s[i];
      i++;
      b = t[j];
      j++;
      //      printf("flag 5\n");
    if (a == b && a == '\0') 
      return 0;
  }
  } while (a == b && i < endpos && j < endpos);
  //  printf("flag 6\n");
  return a-b;
}

// check for number or letter
int isnum(char s) {
  while(s != '\0')
    if ( (s >= 97 && s <= 122 ) || (s >= 65 && s <= 90 ) || (s >= 48 && s <= 57 ) )
      return 1;
    else
      return 0;
}

void lowerit(char *s) {
  for(int i = 0; i < strlen(s); i++)
    if(s[i] >= 65 && s[i] <= 90)
      s[i] += 32;
}

int numcmp(char *s1, char *s2){
  double atof(), v1, v2;
  char str[100];

  substr(s1, str);
  v1 = atof(str);
  substr(s2, str);
  v2 = atof(str);
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
