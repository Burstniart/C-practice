#include <stdio.h>
void squeeze (char s[], int c);
void zqueeze (char s[], char c[]);

int main(int argc, char *argv[]) {
  char arr[]= "la verdad es que sa";
  int a = 'a';
  char lol[] = "ad";
  //  squeeze(arr, a);
  printf("%s\n", arr);
  zqueeze(arr, lol);
  printf("%s\n", arr);

  return 0;
}
/*delete c from s*/
void squeeze (char s[] , int c) {
  int i,j;
  for (i = j = 0; s[i] != '\0'; i++) {
    printf("j-man: %d; i-man: %d\n",j,i);
    if (s[i] != c)
      s[j++] = s[i];
  }
  s[j] = '\0';
}

/*delete every character in c from s*/
void zqueeze (char s[], char c[]) {
  int h, i, j;
  h = 0;

  while (c[h] != '\0') {
    //    printf("%d\n",c[h]);
    //  printf("done\n");
    for (i = j = 0; s[i] != '\0'; i++) {
    //    for (h = 0; c[h] != '\0'; h++) {
    //    while (c[h++] != '\0')
      //      printf("j-man: %d; i-man: %d\n",j,i);
      if (s[i] != c[h])
        s[j++] = s[i];
      //    }
    }
    ++h;
    s[j] = '\0';
  }
}
