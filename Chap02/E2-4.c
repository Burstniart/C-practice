#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main(int argc, char *argv[]) {
  char say[] = "asada adasrax";
  char that[] = "y";
  printf("%d\n", any(say, that));
  
  return 0;
}

/* returns first location in the string s1 where any character from the string s2 occurs, -1 if s1 contains no characters from s2.*/
int any(char s1[], char s2[]) {
  int i,j;
  j = 0;
  while(j < strlen(s2) && s2[j] != '\0') {
    for(i = 0; s1[i] != '\0'; i++)
      if(s1[i] == s2[j])
	return i;      
      j++;
    }
  // no match was found
  return -1;
}
