//LIBRARIES
#include <stdio.h>

//FUNCTIONS
void strcato(char *, char *);

//VARIABLES

//MAIN
int main(int argc, char *argv[]){

  char text[20] = "beggining";
  char addThis[5]= "end";
  
  printf("%s\n", text);

  strcato(text, addThis);
  
  printf("%s\n", text);
  
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
