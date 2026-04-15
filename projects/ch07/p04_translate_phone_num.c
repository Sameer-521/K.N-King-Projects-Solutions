#include <ctype.h>
#include <stdio.h>

#define MAX 10

int translate(char ch) {
  if (isalpha(ch))
    ch = toupper(ch);

  switch (ch) {
  case 'A':
  case 'B':
  case 'C':
    return 2;
  case 'D':
  case 'E':
  case 'F':
    return 3;
  case 'G':
  case 'H':
  case 'I':
    return 4;
  case 'J':
  case 'K':
  case 'L':
    return 5;
  case 'M':
  case 'N':
  case 'O':
    return 6;
  case 'P':
  case 'Q':
  case 'R':
  case 'S':
    return 7;
  case 'T':
  case 'U':
  case 'V':
    return 8;
  case 'W':
  case 'X':
  case 'Y':
  case 'Z':
    return 9;
  default:
    return -1;
  }
}

int main(void) {
  int ch;
  int numeric_val, i;

  i = 0;
  printf("Enter phone number (%d char MAX): ", MAX);
  while ((ch = getchar()) != EOF && ch != '\n' && i < MAX) {
    numeric_val = translate(ch);
    if (numeric_val == -1)
      printf("%c", ch);
    else {
      printf("%d", numeric_val);
      i++;
    }
  }

  printf("\n");

  return 0;
}
