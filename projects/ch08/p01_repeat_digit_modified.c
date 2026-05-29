#include <stdbool.h>
#include <stdio.h>

#define EMPTY_SLOT -1

/* C99 only */
int main(void) {
  bool has_repeated = false, digit_seen[10] = {false};
  int i, digit, repeated_digits[10];
  long n;

  for (i = 0; i < 10; i++)
    repeated_digits[i] = EMPTY_SLOT;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit]) {
      repeated_digits[digit] = digit;
      has_repeated = true;
    } else
      digit_seen[digit] = true;
    n /= 10;
  }

  if (has_repeated) {
    printf("Repeated digit(s): ");
    for (i = 0; i < 10; i++)
      if (repeated_digits[i] != EMPTY_SLOT)
        printf("%d ", repeated_digits[i]);
    printf("\n");
  } else
    printf("No repeated digit\n");

  return 0;
}
