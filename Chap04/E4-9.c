//LIBRARIES
#include <stdio.h>

//DEFINES
//int C;
#define swap(A, B) {int C; C = B, B = A, A = C;}

//MAIN
int main(int argc, char *argv[]){

  int x = 1;
  int y = 2;

  printf("%d & %d\n",x,y);
  swap(x,y);
  printf("%d & %d\n",x,y);
  
  return 0;
}
