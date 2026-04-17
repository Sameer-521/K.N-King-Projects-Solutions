#include <ctype.h>
#include <stdio.h>

#define MAX 1024

int main(void) {
  char msg[MAX], *p1, *p2;
  int ch, length;

  p1 = msg;
  printf("Enter message (%d char max): ", MAX);
  while ((ch = getchar()) != EOF && ch != '\n' && (p1 - &msg[0] < MAX - 1)) {
    if (isalpha(ch)) {
      *p1 = tolower(ch);
      p1++;
    }
  }

  length = p1 - &msg[0];

  if (length == 0) {
    printf("Dude your message must contain atleast one letter!\n");
    return 0;
  }
  // printf("Length: %d\n", length);

  for (p1 = msg, p2 = &msg[length - 1]; p1 < p2; p1++, p2--) {
    if (*p1 != *p2) {
      printf("Not a palindrome.\n");
      return 0;
    }
  }

  printf("Palindrome.\n");

  return 0;
}
