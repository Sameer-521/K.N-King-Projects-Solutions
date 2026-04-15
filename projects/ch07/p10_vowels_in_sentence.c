#include <ctype.h>
#include <stdio.h>

#define MAX 1024

int main(void) {
  int ch, vowels_sum = 0, i = 0;

  printf("Enter a sentence (%d char max): ", MAX);
  while ((ch = getchar()) != EOF && ch != '\n' && i < MAX) {
    if (isalpha(ch)) {
      ch = tolower(ch);
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        vowels_sum++;
    }
    i++;
  }

  printf("Your sentence contains %d vowels.\n", vowels_sum);

  return 0;
}
