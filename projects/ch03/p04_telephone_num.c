#include <stdio.h>

int main(void) {
  int first_pt, second_pt, third_pt;

  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%3d) %3d-%4d", &first_pt, &second_pt, &third_pt);

  printf("You entered %d.%d.%d\n", first_pt, second_pt, third_pt);

  return 0;
}
