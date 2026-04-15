#include <ctype.h>
#include <stdio.h>
#define N 100

int main(void) {
  int i, length, ch;
  char msg[N];

  printf("Enter message (max %d chars): ", N);
  i = 0;
  length = 0;
  ch = getchar();
  while (ch != EOF && ch != '\n') {
    ch = toupper(ch);
    switch (ch) {
    case 'A':
      msg[i] = '4';
      break;
    case 'B':
      msg[i] = '8';
      break;
    case 'E':
      msg[i] = '3';
      break;
    case 'I':
      msg[i] = '1';
      break;
    case 'O':
      msg[i] = '0';
      break;
    case 'S':
      msg[i] = '5';
      break;
    default:
      msg[i] = ch;
      break;
    }
    i++;
    length++;
    ch = getchar();
  }

  printf("In B1FF-speak: ");
  for (i = 0; i < length; i++)
    printf("%c", msg[i]);

  printf("!!!!!!!!!!\n");

  return 0;
}
