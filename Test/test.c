#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
  char arr[10] = "four";
  printf("lenght of four is %ld\n", strlen(arr));
  int i = 0;
  int len = strlen(arr);
  while (i < len)
    printf("%c\n",arr[i++]);
  
  return 0;
}
