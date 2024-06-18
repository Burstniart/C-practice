#include <stdio.h>
int strlen (char s[]);
int htoi(char hex[]);
int power(int base, int sub);

int main(int argc, char argv[]) {
  int c = power(16,2);
  //printf("%d\n",c);
  char s[] = "1a3";
  char sa[] = "5BC";
  //  printf("%d\n", strlen(s));
  printf("%d\n",htoi(s));
  printf("%d\n",htoi(sa));
  return 0;
}

int htoi(char hex[]) {
  char val[] = "0123456789abcdef";
  char vals[] = "0123456789ABCDEF";
  int i,j,h;
  int len = strlen(hex) - 1;
  h = 0;
  for (i = 0; (hex[i] >= '0' && hex[i]<= '9') || (hex[i] >= 'a' && hex[i] <= 'f') || (hex[i] >= 'A' && hex[i] <= 'F');++i) {
    //    printf("hex string value: %c\n", hex[i]);
    for (j = 0; j < 16; ++j){
      if (val[j] == hex[i] || vals[j] == hex[i]) {
	printf("hex string %c equals %d\n", hex[i],j);
	printf("len is %d\n", len);
	h += j * power(16, len--);
      }
    }
  }
  return (h);
}

int strlen (char s[]) {
  int i;
  i = 0;
  while(s[i] != '\0')
    ++i;
  return(i);
}

int power(int base, int sub) {
  int i;
  if (sub == 0)
    return 1;
  else {
    i = base;
    for (; sub > 1; --sub){
      i *= base;
    }
    return (i);
  }
  
}
