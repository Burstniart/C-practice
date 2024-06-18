//LIBRARIES
#include <stdio.h>
#include <string.h>

//FUNCTIONS
void reverse(char []);
void reverser(char [], int, int);

//MAIN
int main (int argc, char *argv[]){

  char strin[10] = "taco cat";

  printf("%s\n", strin);

  reverse(strin);
  
  printf("%s\n", strin);

  char nums[10] = "123456789";

  printf("%s\n", nums);

  reverse(nums);
  
  printf("%s\n", nums);

  if (argc < 2)
    argv[1] = "0";
  reverse(argv[1]);
  printf("%s\n", argv[1]);
  
  return 0;
}

/*Reverse string in place*/
void reverse(char s[])
{
  void reverser(char s[], int i, int len);

  reverser(s, 0, strlen(s));
}

/*Reverse string recursion*/
void reverser(char s[], int i, int len)
{
  int c, j;
  j = len - (i + 1);
  if (i < j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
    reverser(s, ++i, len);      
  }
}
