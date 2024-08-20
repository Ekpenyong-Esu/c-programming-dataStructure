#include <ctype.h>
#include <stdio.h>
#include <string.h>


#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch) {
  if (top >= MAX_SIZE - 1) {
    printf("Stack overflow\n");
    return;
  }
  stack[++top] = ch;
}

char pop() {
  if (top < 0) {
    printf("Stack underflow\n");
    return '\0';
  }
  return stack[top--];
}

int precedence(char ch) {
  switch (ch) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

int isOperator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPrefix(char infix[], char prefix[]) {
  int i, j;
  int len = strlen(infix);

  // Reverse the infix expression
  for (i = len - 1, j = 0; i >= 0; i--, j++) {
    prefix[j] = infix[i];
  }
  prefix[j] = '\0';

  // Replace '(' with ')' and vice versa
  for (i = 0; i < len; i++) {
    if (prefix[i] == '(') {
      prefix[i] = ')';
    } else if (prefix[i] == ')') {
      prefix[i] = '(';
    }
  }

  // Convert infix to prefix
  char ch;
  i = 0;
  j = 0;
  while ((ch = prefix[i++]) != '\0') {
    if (isalnum(ch)) {
      prefix[j++] = ch;
    } else if (ch == '(') {
      push(ch);
    } else if (ch == ')') {
      while (stack[top] != '(') {
        prefix[j++] = pop();
      }
      pop(); // Remove '(' from the stack
    } else {
      while (precedence(ch) <= precedence(stack[top])) {
        prefix[j++] = pop();
      }
      push(ch);
    }
  }

  while (top >= 0) {
    prefix[j++] = pop();
  }
  prefix[j] = '\0';

  // Reverse the final prefix expression
  for (i = 0, j = strlen(prefix) - 1; i < j; i++, j--) {
    char temp = prefix[i];
    prefix[i] = prefix[j];
    prefix[j] = temp;
  }
}

int main() {
  char infix[MAX_SIZE];
  char prefix[MAX_SIZE];

  printf("Enter the infix expression: ");
  scanf("%s", infix);

  infixToPrefix(infix, prefix);
  printf("The prefix expression is: %s\n", prefix);

  return 0;
}
