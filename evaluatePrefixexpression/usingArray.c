#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_EXPR_LEN 100
#define MAX_STACK_SIZE 100

// Stack implementation
int stack[MAX_STACK_SIZE];
int top = -1;

void push(int item) {
  if (top >= MAX_STACK_SIZE - 1) {
    printf("Stack overflow\n");
    exit(1);
  }
  stack[++top] = item;
}

int pop() {
  if (top == -1) {
    printf("Stack underflow\n");
    exit(1);
  }
  return stack[top--];
}

int peek() {
  if (top == -1) {
    printf("Stack underflow\n");
    exit(1);
  }
  return stack[top];
}

int isEmpty() { return top == -1; }

// Function to evaluate prefix expression
int evaluatePrefix(char expr[]) {
  int len = strlen(expr);
  for (int i = len - 1; i >= 0; i--) {
    if (isdigit(expr[i])) {
      // If current character is a digit, convert it to an integer and push onto
      // the stack
      int num = expr[i] - '0';
      while (isdigit(expr[--i])) {
        num = num * 10 + (expr[i] - '0');
      }
      push(num);
    } else if (isspace(expr[i])) {
      // Ignore whitespace characters
      continue;
    } else {
      // If current character is an operator, pop two operands from the stack,
      // apply the operator, and push the result back onto the stack
      int op1 = pop();
      int op2 = pop();
      switch (expr[i]) {
      case '+':
        push(op1 + op2);
        break;
      case '-':
        push(op1 - op2);
        break;
      case '*':
        push(op1 * op2);
        break;
      case '/':
        push(op1 / op2);
        break;
      }
    }
  }
  // The final result is the top element of the stack
  return pop();
}

// Main function
int main() {
  char expr[MAX_EXPR_LEN];
  printf("Enter prefix expression: ");
  fgets(expr, MAX_EXPR_LEN, stdin);
  int result = evaluatePrefix(expr);
  printf("Result: %d\n", result);
  return 0;
}
