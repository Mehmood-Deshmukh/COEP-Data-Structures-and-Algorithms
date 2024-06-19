#include <stdio.h>
#define BUFFER 100

int main(void) {
  int histogram[BUFFER];
  int histogram_length = 0;

  int max_word_count = 0;

  int i;
  for (i = 0; i < BUFFER; ++i) {
    histogram[i] = 0;
  }
  char c;
  int word_count_index = 0;
  while ((c = getchar())) {
    if (c == ' ' || c == '\t' || c == '\n' || c == EOF) {
      if (word_count_index > 0) {
        ++histogram[word_count_index - 1];

        if (histogram[word_count_index - 1] > max_word_count) {
          max_word_count = histogram[word_count_index - 1];
        }

        if (histogram_length < word_count_index - 1) {
          histogram_length = word_count_index - 1;
        }

        word_count_index = 0;
      }
      if (c == EOF) {
        break;
      }
    }
    else{
      ++word_count_index;
    }
  }

  histogram[histogram_length + 1] = '$';

  putchar('\n');

  int column_index = 0;
  int line_index = 0;

  printf("Horizontal Histogram\n--------------------\n");

  while (histogram[column_index] != '$'){
    printf("%3d: \t", column_index + 1);

    for (line_index = 0; line_index < histogram[column_index]; ++line_index){
      putchar('#');
    }

    putchar('\n');

    ++column_index;
  }

  putchar('\n');


  printf("Vertical Histogram\n------------------\n");

  for (line_index = max_word_count; line_index >= 0; --line_index){
    column_index = 0;
    while (histogram[column_index] != '$'){
      if (line_index == 0){
        printf("%2d ", column_index + 1);
      }
      else if (histogram[column_index] >= line_index){
        printf("## ");
      }
      else{
        printf("   ");
      }

      ++column_index;
    }

    putchar('\n');
  }

  return 0;
}