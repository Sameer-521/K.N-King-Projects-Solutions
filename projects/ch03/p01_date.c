#include <stdio.h>

int main(void) {
  int year, month, day;

  printf("Enter a date: (mm/dd/yyyy): ");
  scanf("%2d/%2d/%4d", &month, &day, &year);

  printf("%d%d%d\n", year, month, day);

  return 0;
}
