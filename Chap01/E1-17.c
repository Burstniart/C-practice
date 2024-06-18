#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int limit);
int reverse(char to[], char from[], int l);

int main() {
    int size;
    char line[MAXLINE];
    while ((size = get_line(line, MAXLINE)) > 0) {
        char revline[size];
        int len = reverse(revline, line, size);
        printf("%s\n", revline);
    }

    return 0;
}

int reverse(char to[], char from[], int l) {
    int i;
    int j = l - 2;
    for (i = 0; i < l; i++, j--) {
        to[i] = from[j];
    }
    to[i] = '\0';
    return i;
}

int get_line(char s[], int limit) {
    int c = 0;
    int i = 0;

    for (i = 0; i < limit-1 && (c = getchar()) != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
