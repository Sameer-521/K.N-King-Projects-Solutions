#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int readline(char str[], int n);
void build_str(int n1, int n2, char *dest, const char *delimeter);
void clear_input_buffer(void);

int main(void) {
  char reminders[MAX_REMIND][MSG_LEN + 3];
  char date_str[6], time_str[10], buff[20], msg_str[MSG_LEN + 1];
  int month, day, hrs, mins, i, j, num_remind = 0;

  printf("Date format: MM/dd --- Time format: 24h\n");
  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --");
      break;
    }

    printf("Enter date, time and reminder: ");
    if (scanf("%2d/%2d", &month, &day) < 2) {
      if (month == 0)
        break;
      printf("Invalid date!\n");
      clear_input_buffer();
      continue;
    }

    if (month < 0 || month > 12) {
      printf("Invalid month!\n");
      clear_input_buffer();
      continue;
    }

    if (day < 0 || day > 31) {
      printf("Invalid day!\n");
      clear_input_buffer();
      continue;
    }

    if (scanf("%2d:%2d ", &hrs, &mins) < 2) {
      printf("Invalid time. Time should be in 24h format!\n");
      clear_input_buffer();
      continue;
    }

    build_str(month, day, date_str, "/");

    build_str(hrs, mins, time_str, ":");

    readline(msg_str, MSG_LEN);

    // compare by date and time
    strncpy(buff, date_str, sizeof(buff));
    strncat(buff, time_str, sizeof(buff) - strlen(date_str));
    for (i = 0; i < num_remind; i++)
      if (strcmp(buff, reminders[i]) < 0)
        break;

    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j - 1]);

    strcpy(reminders[i], date_str);
    strcat(reminders[i], time_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDate  ");
  printf("%-5s", "Time");
  printf("%10s", "Reminder\n");

  for (i = 0; i < num_remind; i++)
    printf("%s\n", reminders[i]);

  return 0;
}

int readline(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;

  str[i] = '\0';

  return i;
}

void build_str(int n1, int n2, char *dest, const char *delimeter) {
  char buff[10];

  sprintf(buff, "%02d", n1);
  strcpy(dest, buff);
  strcat(dest, delimeter);

  sprintf(buff, "%02d ", n2);
  strcat(dest, buff);
}

void clear_input_buffer(void) {
  int ch;

  while ((ch = getchar()) != EOF && ch != '\n')
    ;
}
