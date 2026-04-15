#include <stdio.h>

int main(void) {
  char ch, previous_ch;
  int in_word = 0;
  int char_count = 0;
  int word_count = 0;
  float average = 0.0f;

  printf("Enter a sentence: ");

  while ((ch = getchar()) != EOF && ch != '\n') {
    if (ch == ' ') {
      if (in_word)
        in_word = 0;
    } else {
      if (!in_word) {
        in_word = 1;
        word_count++;
      }
      char_count++;
    }
  }

  average = (float)char_count / word_count;
  printf("Word count: %d\nTotal non-space char length: %d\n", word_count,
         char_count);
  printf("Average word length: %.2f\n", average);
  return 0;
}
