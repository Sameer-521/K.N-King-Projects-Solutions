#include <stdbool.h>
#include <stdio.h>

int main(void) {
  char first_name_letter;
  int ch;
  bool in_word = false, is_first_name = true, is_last_name = false;

  printf("Enter first and last name: ");
  while ((ch = getchar()) != EOF && ch != '\n') {
    if (ch != ' ') {
      // capture first letter of first name
      if (!in_word && is_first_name) {
        first_name_letter = ch;
        in_word = true;
        is_first_name = false;
      }
      // print first letter of last name
      else if (!in_word && !is_first_name && !is_last_name) {
        printf("%c", ch);
        is_last_name = true;
        in_word = true;
      } else if (in_word && is_last_name)
        printf("%c", ch);
    }

    else {
      if (in_word) {
        in_word = false;

        // stop printing beyond last name
        if (is_last_name)
          break;
      }
    }
  }

  printf(", %c.\n", first_name_letter);

  return 0;
}
