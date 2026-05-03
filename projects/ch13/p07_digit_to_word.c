#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 32

void build_number(int ten, int unit, char *number);

const char *units[] = {"One", "Two",   "Three", "Four", "Five",
                       "Six", "Seven", "Eight", "Nine"};

const char *tens[] = {"Twenty", " Thirty", " Forty", " Fifty",
                      "Sixty",  "Seventy", "Eighty", "Ninety"};

int main(void) {
  char number[BUFF_SIZE];
  int ten, unit;

  printf("Enter a two-digit number: ");
  if (scanf("%1d%1d", &ten, &unit) < 2) {
    printf("Invalid number!");
    return 1;
  }

  build_number(ten, unit, number);
  printf("You entered the number: %s\n", number);

  return 0;
}

void build_number(int ten, int unit, char *number) {
  char buff[BUFF_SIZE];
  int num;

  if (ten > 1) {
    strncpy(number, tens[ten - 2], BUFF_SIZE - 1);
    if (unit > 0) {
      strcat(number, "-");
      strncat(number, units[unit - 1], BUFF_SIZE - strlen(buff));
    }
    return;
  }

  num = (ten * 10) + unit;

  switch (num) {
  case 10:
    strcpy(number, "Ten");
    break;
  case 11:
    strcpy(number, "Eleven");
    break;
  case 12:
    strcpy(number, "Twelve");
    break;
  case 13:
    strcpy(number, "Thirteen");
    break;
  case 14:
    strcpy(number, "Fourteen");
    break;
  case 15:
    strcpy(number, "Fifteen");
    break;
  case 16:
    strcpy(number, "Sixteen");
    break;
  case 17:
    strcpy(number, "Seventeen");
    break;
  case 18:
    strcpy(number, "Eighteen");
    break;
  case 19:
    strcpy(number, "Nineteen");
    break;
  default:
    return;
  }
}
