#include <stdio.h>

int main(void) {
  int num, x, y, z;

  printf("Enter a three-digit number: ");
  scanf("%3d", &num);

  // assuming the num is 3 digit num xyz
  x = num / 100;      // hundreds place
  y = num % 100 / 10; // tens place
  z = num % 10;       // ones place

  // reversal of xyz -> zyx i.e reading the number from right to left
  printf("The reversal is: %d%d%d\n", z, y, x);

  return 0;
}
