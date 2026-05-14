#include <ctype.h>
#include <stdio.h>

#define MAX 1024

int compute_vowel_count(const char *sentence);
int readline(char *str, int n);

int main(void) {
  int vowels_sum = 0;
  char sentence[MAX];

  printf("Enter a sentence (%d char max): ", MAX);
  readline(sentence, MAX);

  vowels_sum = compute_vowel_count(sentence);
  printf("Your sentence contains %d vowels.\n", vowels_sum);

  return 0;
}

int compute_vowel_count(const char *sentence) {
  int ch, vowel_count = 0;

  while (*sentence) {
    ch = *sentence;
    if (isalpha(ch)) {
      ch = tolower(ch);
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        vowel_count++;
    }
    sentence++;
  }

  return vowel_count;
}

int readline(char *str, int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;

  str[i] = '\0';

  return i;
}
