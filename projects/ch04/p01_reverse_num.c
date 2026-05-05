#include <stdio.h>

int main(void) {
  int num, x, y;

  printf("Enter a two-digit number: ");
  scanf("%2d", &num);

  x = num / 10; // tens place
  y = num % 10; // ones place

  // reversal of xy -> yx i.e reading the number from right to left
  printf("The reversal is: %d%d\n", y, x);

  return 0;
}
