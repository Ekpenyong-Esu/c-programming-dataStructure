#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_EXPR_LEN 100

// Stack implementation
typedef struct {
  int top;
  int data[MAX_EXPR_LEN];
} Stack;

void init(Stack *stack) { stack->top = -1; }

int isEmpty(Stack *stack) { return stack->top == -1; }

void push(Stack *stack, int item) { stack->data[++stack->top] = item; }

int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow\n");
    exit(1);
  }
  return stack->data[stack->top--];
}

int peek(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow\n");
    exit(1);
  }
  return stack->data[stack->top];
}

// Function to evaluate prefix expression
int evaluatePrefix(char expr[]) {
  Stack stack;
  init(&stack);
  int len = strlen(expr);
  for (int i = len - 1; i >= 0; i--) {
    if (isdigit(expr[i])) {
      // If current character is a digit, convert it to an integer and push onto
      // the stack
      int num = expr[i] - '0';
      while (isdigit(expr[--i])) {
        num = num * 10 + (expr[i] - '0');
      }
      push(&stack, num);
    } else if (isspace(expr[i])) {
      // Ignore whitespace characters
      continue;
    } else {
      // If current character is an operator, pop two operands from the stack,
      // apply the operator, and push the result back onto the stack
      int op1 = pop(&stack);
      int op2 = pop(&stack);
      switch (expr[i]) {
      case '+':
        push(&stack, op1 + op2);
        break;
      case '-':
        push(&stack, op1 - op2);
        break;
      case '*':
        push(&stack, op1 * op2);
        break;
      case '/':
        push(&stack, op1 / op2);
        break;
      }
    }
  }
  // The final result is the top element of the stack
  return pop(&stack);
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
