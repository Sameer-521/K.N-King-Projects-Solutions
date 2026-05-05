#include <stdio.h>

int main(void) {
  int num, a = 0, b = 0, c = 0, d = 0, e = 0;

  printf("Enter a number between 0 and 32767: ");
  scanf("%5d", &num);

  // build the octal representation
  a = num % 8;
  num /= 8;

  b = num % 8;
  num /= 8;

  c = num % 8;
  num /= 8;

  d = num % 8;
  num /= 8;

  e = num % 8;
  num /= 8;

  printf("In octal, your number is: %d%d%d%d%d\n", e, d, c, b, a);

  return 0;
}
