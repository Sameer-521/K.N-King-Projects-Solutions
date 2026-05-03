#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9
#define BUFF_SIZE 16

void casefold(char *s);

int main(int argc, char *argv[]) {
  char *planets[] = {"Mercury", "Venus",  "Earth",   "Mars", "Jupiter",
                     "Saturn",  "Uranus", "Neptune", "Pluto"};
  char buff_1[BUFF_SIZE], buff_2[BUFF_SIZE];
  int i, j;

  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++) {
      strncpy(buff_1, argv[i], BUFF_SIZE - 1);
      strncpy(buff_2, planets[j], BUFF_SIZE - 1);
      casefold(buff_1);
      casefold(buff_2);
      if (strcmp(buff_1, buff_2) == 0) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    }
    if (j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }

  return 0;
}

void casefold(char *s) {
  while (*s) {
    *s = tolower(*s);
    s++;
  }
}
