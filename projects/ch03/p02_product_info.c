#include <stdio.h>

int main(void) {
  int year, month, day, item_num;
  double unit_price;

  printf("Enter item number: ");
  scanf("%6d", &item_num);

  printf("Enter unit price: ");
  scanf("%7lf", &unit_price);

  printf("Enter a date: (mm/dd/yyyy): ");
  scanf("%2d/%2d/%4d", &month, &day, &year);

  // print item info
  printf("Item\t\tUnit\t\tPurchase\n");
  printf("    \t\tPrice\t\tDate\n");
  printf("%-6d \t\t$%6.2lf \t%d/%d/%d\n", item_num, unit_price, month, day,
         year);

  return 0;
}
