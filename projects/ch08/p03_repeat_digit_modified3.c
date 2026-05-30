#include <stdbool.h>
#include <stdio.h>

/* C99 only */
int main(void) {
  int i, digit, repeated_digits[10] = {0};
  long n;

  while (true) {
    printf("Enter a number: ");
    scanf("%ld", &n);

    if (n <= 0)
      break;

    while (n > 0) {
      digit = n % 10;
      repeated_digits[digit]++;
      n /= 10;
    }

    printf("Digit:      0 1 2 3 4 5 6 7 8 9\n");

    printf("Occurences: ");
    for (i = 0; i < 10; i++)
      printf("%d ", repeated_digits[i]);
    printf("\n");
  }
  return 0;
}
