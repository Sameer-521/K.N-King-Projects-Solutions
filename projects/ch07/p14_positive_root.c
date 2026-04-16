#include <math.h>
#include <stdio.h>

int main(void) {
  int x;
  double y = 1, old_y;
  double quotient, average;

  printf("Enter a positive number: ");
  scanf("%d", &x);

  while (1) {
    old_y = y;
    quotient = x / y;
    average = (y + quotient) / 2;
    y = average;
    if (fabs(y - old_y) < (y * 0.001))
      break;
  }

  printf("Square root: %lf\n", y);

  return 0;
}
