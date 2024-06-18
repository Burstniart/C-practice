#include <stdio.h>
int getbits(unsigned x,unsigned p,unsigned n);

int main(int argc, char *argv[]) {

  unsigned int x = 171;
  //  printf("%d\n",getbits(x, 4, 3));
  unsigned int y = ~2;
  
  printf("%d\n",y);
  return 0;
}

int getbits(unsigned x,unsigned p ,unsigned n) /* get n bits from position p */
{
    return((x >> (p+1-n)) &  ~(~0 << n));
}
