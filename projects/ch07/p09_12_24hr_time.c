#include <ctype.h>
#include <stdio.h>

int main(void) {
  char latin_phrase;
  int hr, mins;

  printf("Enter a 12hr time: ");
  if (scanf(" %d:%d %c", &hr, &mins, &latin_phrase) < 3) {
    printf("Enter a goddamn valid 12hr time!\n");
    return 1;
  }

  if (hr > 12 || hr < 1 || mins > 59 || mins < 0) {
    printf("Enter a goddamn valid 12hr time!\n");
    return 1;
  }

  latin_phrase = tolower(latin_phrase);

  if (hr == 12 && latin_phrase == 'a')
    hr = 0;
  else if (hr >= 1 && hr < 12 && latin_phrase == 'p')
    hr += 12;

  printf("Equivalent 24hr time: %02d:%02d\n", hr, mins);

  return 0;
}
