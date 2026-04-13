#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int top = 0;
int contents[STACK_SIZE];

int pop(void);
void push(int num);

bool is_full(void);
bool is_empty(void);
void make_empty(void);
void stack_overflow(void);
void stack_underflow(void);
void display_result(void);
void debug_print_stack(void);

char eval_expr(int x, int y, char operation);
bool is_operation(char ch);

int main(void) {
  char ch;
  int num1, num2, result;

  printf("Enter an RPN expression: ");
  scanf(" %c", &ch);
  while (ch != EOF && ch != '\n') {
    if (!is_operation(ch))
      push(ch - '0'); // convert to int
    else {
      if (ch == '=') {
        // debug_print_stack();
        display_result();
        break;
      } else {
        // debug_print_stack();
        // break;
        num2 = pop();
        num1 = pop();
        result = eval_expr(num1, num2, ch);
        push(result);
      }
    }

    scanf(" %c", &ch);
  }

  return 0;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return -1; // this won't be reached
  } else
    return contents[--top];
}

void push(int num) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = num;
}

void stack_underflow(void) {
  printf("Not enough operands in expression!\n");
  exit(EXIT_FAILURE);
}

void stack_overflow(void) {
  printf("Expression is too complex!\n");
  exit(EXIT_FAILURE);
}

void make_empty(void) { top = 0; }

void display_result(void) {
  // the last result would be top - 1 because top always point to an empty slot
  printf("%d\n", contents[top - 1]);
}

void debug_print_stack(void) {
  printf("Debug Printing Stack: \n");
  for (int i = 0; i < top; i++)
    printf("%d ", contents[i]);

  printf("\n");
}

bool is_full(void) { return top == STACK_SIZE; }

bool is_empty(void) { return top == 0; }

char eval_expr(int x, int y, char operation) {
  int result;

  switch (operation) {
  case '+':
    result = x + y;
    break;
  case '-':
    result = x - y;
    break;
  case '*':
    result = x * y;
    break;
  case '/':
    result = x / y;
    break;
  default:
    printf("Invalid operation!");
    exit(EXIT_FAILURE);
  }

  return result;
}

bool is_operation(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
             ? true
             : false;
}
