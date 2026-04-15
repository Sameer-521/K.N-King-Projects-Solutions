#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int i, ch, start, end;
  bool in_word = false;
  char terminating_char;
  char sentence[1024];

  printf("Enter a sentence (max 1024 chars): ");
  i = 0;
  while ((ch = getchar()) != EOF && ch != '\n') {
    if (ch == '.' || ch == '?' || ch == '!') {
      terminating_char = ch;
      break;
    } else {
      sentence[i] = ch;
      i++;
    }
  }

  // check if the sentence was actually stored
  // for (int j = 0; j < i; j++)
  //   printf("%c", sentence[j]);

  printf("Reversal of sentence: ");
  for (i = i - 1; i >= 0; i--) {
    if (sentence[i] == ' ' || i == 0) {
      if (in_word) {
        start = i == 0 ? i : ++i;
        // printf("Start: %d, End: %d, i: %d ::", start, end, i);
        for (; start <= end; start++)
          printf("%c", sentence[start]);

        in_word = false;
        if (i != 0)
          printf(" ");
      }
    } else {
      if (!in_word) {
        end = i;
        in_word = true;
      }
    }
  }
  printf("%c\n", terminating_char);
  return 0;
}
