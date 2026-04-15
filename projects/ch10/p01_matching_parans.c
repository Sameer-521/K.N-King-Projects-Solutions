#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int top = 0;
char contents[STACK_SIZE];

int pop(void);
void push(char ch);

bool is_full(void);
bool is_empty(void);
void make_empty(void);
void stack_overflow(void);
void stack_underflow(void);

bool is_opening(char ch);
bool matches(char open, char close);

int main(void) {
  int ch;
  char open, close;

  printf("Enter paranthesis and/or braces: ");
  while ((ch = getchar()) != EOF && ch != '\n') {
    if (is_opening(ch)) {
      push(ch);
    } else {
      open = pop();
      close = ch; // just for clarity, could've used the value directly
      if (!matches(open, close)) {
        printf("Unmatched parans:\n");
        printf("Open: '%c'  Close: '%c'\n", open, close);
        break;
      }
    }
  }

  if (is_empty())
    printf("Paranthesis/braces are nested properly.\n");

  return 0;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return -1; // this won't be reached
  } else
    return contents[--top];
}

void push(char ch) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = ch;
}

void stack_underflow(void) {
  printf("Stack-underflow. Exiting...\n");
  exit(EXIT_FAILURE);
}

void stack_overflow(void) {
  printf("Stack-overflow. Exiting...\n");
  exit(EXIT_FAILURE);
}

void make_empty(void) { top = 0; }

bool is_full(void) { return top == STACK_SIZE; }

bool is_empty(void) { return top == 0; }

bool is_opening(char ch) {
  return ch == '(' || ch == '[' || ch == '{' ? true : false;
}

bool matches(char open, char close) {
  if ((open == '(' && close == ')') || (open == '{' && close == '}') ||
      (open == '[' && close == ']'))
    return true;
  else
    return false;
}
