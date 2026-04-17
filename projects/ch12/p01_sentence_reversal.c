#include <stdio.h>

#define MAX 1024

int main(void) {
  char sentence[MAX], *ptr;
  int ch, length;

  ptr = sentence;
  printf("Enter sentence (%d char max): ", MAX);
  while ((ch = getchar()) != EOF && ch != '\n' &&
         (ptr - &sentence[0] < MAX - 1)) {
    *ptr = ch;
    ptr++;
  }

  length = ptr - &sentence[0];
  for (ptr = &sentence[0] + length - 1; ptr >= &sentence[0]; ptr--)
    printf("%c", *ptr);

  printf("\n");

  return 0;
}
