#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 20
#define MAX_WORD 4

int get_input(char *s);
void swap(char *s1, char *s2);

int main(void) {
  char smallest[BUFF_SIZE], largest[BUFF_SIZE], buff[BUFF_SIZE];

  smallest[BUFF_SIZE - 1] = '\0';
  largest[BUFF_SIZE - 1] = '\0';
  buff[BUFF_SIZE - 1] = '\0';

  // first word
  get_input(smallest);
  // second word
  get_input(largest);

  swap(smallest, largest);

  while ((get_input(buff) != MAX_WORD)) {
    if (strcmp(buff, smallest) < 0)
      strncpy(smallest, buff, BUFF_SIZE - 1);
    else if (strcmp(buff, largest) > 0)
      strncpy(largest, buff, BUFF_SIZE - 1);
  }

  printf("Smallest word: %s\n", smallest);
  printf("Largest word: %s\n", largest);

  return 0;
}

int get_input(char *s) {
  printf("Enter word: ");
  scanf("%19s", s);
  return strlen(s);
}

void swap(char *s1, char *s2) {
  char buff[BUFF_SIZE];
  buff[BUFF_SIZE - 1] = '\0';

  if (strcmp(s1, s2) > 0) {
    strcpy(buff, s2);
    strcpy(s2, s1);
    strcpy(s1, buff);
  }
}
