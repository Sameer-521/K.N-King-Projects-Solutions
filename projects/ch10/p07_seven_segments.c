#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_DIGITS 10
#define WIDTH 4
#define SEGMENT_MAX 7

int segments[MAX_DIGITS][SEGMENT_MAX] = {
    {1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}};
char digits[WIDTH][MAX_DIGITS * 4];

void clear_digits_arr(void);
void process_digit(int digit, int position);
void print_digits_arr(void);

bool is_vertical(int segment_index);

int main(void) {
  char ch;
  int i = 0;

  clear_digits_arr();

  printf("Enter a number: ");
  while ((ch = getchar()) != EOF && ch != '\n' && i < MAX_DIGITS) {
    if (isdigit(ch)) {
      process_digit(ch - '0', i);
      i++;
    }
  }

  print_digits_arr();

  return 0;
}

void clear_digits_arr(void) {
  int i, j;
  for (i = 0; i < WIDTH; i++)
    for (j = 0; j < MAX_DIGITS * 4; j++)
      digits[i][j] = ' ';
}

void print_digits_arr(void) {
  int i, j;
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < MAX_DIGITS * 4; j++) {
      if (digits[i][j] == '-')
        printf("‾");
      else
        printf("%c", digits[i][j]);
    }
    printf("\n");
  }
}

void process_digit(int digit, int position) {
  int col_base = WIDTH * position;
  int row_base = 0, i;
  char display_ch;

  if (position > 1)
    col_base++;

  for (i = 0; i < SEGMENT_MAX; i++) {
    if (segments[digit][i] == 1) {
      if (is_vertical(i))
        display_ch = '|';
      else if (i == 3)
        display_ch = '-';
      else
        display_ch = '_';

      switch (i) {
      case 0:
        digits[row_base][col_base + 1] = display_ch;
        break;
      case 1:
        digits[row_base + 1][col_base + 2] = display_ch;
        break;
      case 2:
        digits[row_base + 2][col_base + 2] = display_ch;
        break;
      case 3:
        digits[row_base + 3][col_base + 1] = display_ch;
        break;
      case 4:
        digits[row_base + 2][col_base] = display_ch;
        break;
      case 5:
        digits[row_base + 1][col_base] = display_ch;
        break;
      case 6:
        digits[row_base + 1][col_base + 1] = display_ch;
        break;
      default:
        printf("Invalid segment_index!\n");
      }
    }
  }
}

bool is_vertical(int segment_index) {
  if (segment_index == 1 || segment_index == 2 || segment_index == 4 ||
      segment_index == 5)
    return true;

  return false;
}
