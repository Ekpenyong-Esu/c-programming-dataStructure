#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_EXPR_LEN 100
#define MAX_STACK_SIZE 100

// Stack implementation
char stack[MAX_STACK_SIZE];
int top = -1;

void push(char item) {
  if (top >= MAX_STACK_SIZE - 1) {
    printf("Stack overflow\n");
    exit(1);
  }
  stack[++top] = item;
}

char pop() {
  if (top == -1) {
    printf("Stack underflow\n");
    exit(1);
  }
  return stack[top--];
}

char peek() {
  if (top == -1) {
    printf("Stack underflow\n");
    exit(1);
  }
  return stack[top];
}

bool isMatchingPair(char left, char right) {
  if (left == '(' && right == ')')
    return true;
  else if (left == '{' && right == '}')
    return true;
  else if (left == '[' && right == ']')
    return true;
  else
    return false;
}

bool isBalanced(char expr[]) {
  int len = strlen(expr);
  for (int i = 0; i < len; i++) {
    if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
      // If the current character is an opening bracket, push onto the stack
      push(expr[i]);
    } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
      // If the current character is a closing bracket, pop from the stack
      if (top == -1 || !isMatchingPair(peek(), expr[i])) {
        // If stack is empty or the current closing bracket does not match with
        // the top element, the expression is unbalanced
        return false;
      } else {
        // If the current closing bracket matches with the top element, remove
        // the top element
        pop();
      }
    }
  }
  // If the stack is empty after processing all the characters, the expression
  // is balanced
  return (top == -1);
}

// Main function
int main() {
  char expr[MAX_EXPR_LEN];
  printf("Enter expression: ");
  fgets(expr, MAX_EXPR_LEN, stdin);
  if (isBalanced(expr)) {
    printf("The expression is balanced\n");
  } else {
    printf("The expression is unbalanced\n");
  }
  return 0;
}
