#include <stdio.h>

int main(void) {
  int x, y, z;

  printf("Enter a three-digit number: ");
  scanf("%1d%1d%1d", &x, &y, &z);

  // reversal of xyz -> zyx i.e reading the number from right to left
  printf("The reversal is: %d%d%d\n", z, y, x);

  return 0;
}
