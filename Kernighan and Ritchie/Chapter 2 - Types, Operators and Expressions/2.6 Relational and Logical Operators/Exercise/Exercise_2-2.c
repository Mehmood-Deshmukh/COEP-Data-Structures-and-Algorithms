#include <stdio.h>

#define MAXLINE 1000

int main(void) {
  char s[MAXLINE];

  int i = 0;
  int loop = 1;
  while (loop) {
    char c = getchar();

    if (i >= (MAXLINE - 1)){
      loop = 0;
    }
    else if (c == '\n'){
      loop = 0;
    }
    else if (c == EOF){
      loop = 0;
    }

    s[i++] = c;
  }

  s[i] = '\0';
  printf("%s", s);
  return 0;
}