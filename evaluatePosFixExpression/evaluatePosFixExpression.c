#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
  if (top >= MAX_SIZE - 1) {
    printf("Stack overflow\n");
    exit(1);
  }
  stack[++top] = value;
}

int pop() {
  if (top < 0) {
    printf("Stack underflow\n");
    exit(1);
  }
  return stack[top--];
}

int evaluatePostfix(char *expression) {
  int i, operand1, operand2, result;
  char ch;

  for (i = 0; expression[i] != '\0'; i++) {
    ch = expression[i];

    if (isdigit(ch)) {
      push(ch - '0');
    } else {
      operand2 = pop();
      operand1 = pop();

      switch (ch) {
      case '+':
        result = operand1 + operand2;
        break;
      case '-':
        result = operand1 - operand2;
        break;
      case '*':
        result = operand1 * operand2;
        break;
      case '/':
        result = operand1 / operand2;
        break;
      case '%':
        result = operand1 % operand2;
        break;
      default:
        printf("Invalid operator\n");
        exit(1);
      }
      push(result);
    }
  }
  return pop();
}

int main() {
  char expression[MAX_SIZE];
  printf("Enter a postfix expression: ");
  scanf("%s", expression);

  int result = evaluatePostfix(expression);
  printf("Result = %d\n", result);

  return 0;
}
