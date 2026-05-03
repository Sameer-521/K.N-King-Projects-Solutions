#include <ctype.h>
#include <stdio.h>

int compute_scrabble_value(const char *word);

int main(void) {
  int value = 0;
  char word[64];

  printf("Enter a word: ");
  scanf("%63s", word);

  value = compute_scrabble_value(word);
  printf("Scrabble value: %d\n", value);

  return 0;
}

int compute_scrabble_value(const char *word) {
  int ch, value = 0;

  while ((ch = *word)) {
    ch = toupper(ch);
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'L' || ch == 'N' ||
        ch == 'O' || ch == 'R' || ch == 'S' || ch == 'T' || ch == 'U')
      value += 1;
    else if (ch == 'D' || ch == 'G')
      value += 2;
    else if (ch == 'B' || ch == 'C' || ch == 'M' || ch == 'P')
      value += 3;
    else if (ch == 'F' || ch == 'H' || ch == 'V' || ch == 'W' || ch == 'Y')
      value += 4;
    else if (ch == 'K')
      value += 5;
    else if (ch == 'J' || ch == 'X')
      value += 8;
    else if (ch == 'Q' || ch == 'Z')
      value += 10;
    else {
      ;
    }

    word++;
  }

  return value;
}
