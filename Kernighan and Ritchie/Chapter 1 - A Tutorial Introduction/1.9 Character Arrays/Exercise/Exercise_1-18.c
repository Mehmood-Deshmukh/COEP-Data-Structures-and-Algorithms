#include <stdio.h>

#define MAXLINE 1000

int remove_trailing_blanks(char line[], int length); 
int get_line(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE];

    while((len = get_line(line , MAXLINE)) > 0){
        len = remove_trailing_blanks(line, len);
        if(len > 1){
            printf("line = %s", line);    
        }
    }
    return 0;
}

int get_line(char line[], int maxline){
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n' ; ++i) {
        if(c == ' ' || c == '\t'){
            --i;
            continue;
        }
        line[i] = c;
    }
    
    if (c == '\n'){
        line[i++] = c; 
    }

    line[i] = '\0';
    return i;
}

int remove_trailing_blanks(char line[], int length) {
  int i;

  for (i = length - 2; line[i] == ' ' || line[i] == '\t'; --i)
    ;

  line[i + 1] = '\n';
  line[i + 2] = '\0';

  return i + 1;
}