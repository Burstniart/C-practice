//LIBRARIES
#include <stdio.h>

//MACROS
//#define Strcpyo( f, a){char *f, char *a;while((f++ = a++);};

#define strcpy(s, t) char *_s=s; char *_t=t; while ((*_s++ = *_t++) != '\0');

//FUNCTIONS
void strcato(char *, char *);

//VARIABLES

//MAIN
int main(int argc, char *argv[]){

  char text[20] = "beggining";
  char addThis[20]= "end";
  
  printf("1%s\n", text);
  printf("2%s\n", addThis);
  strcpy(text, addThis);
  printf("3%s\n", text);
  printf("4%s\n", addThis);
  
  return 0;
}

void strcato(char *s, char *t) /* concatenate t to end of s */
/* s must be big enough */
{
  int i, j;

  i = j = 0;
  while (*s != '\0')  /* find end of s */
    *s++;
  while ((*s++ = *t++) != '\0') /* copy t */
    ;
}
/*
strcpy(s, t) /* copy t to s; pointer version 3 
char *s, *t;
{
  while (*s++ = *t++)
  ;
}
*/
