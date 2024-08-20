#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 100

// Define the stack structure
typedef struct {
  char data[MAX_SIZE];
  int top;
} Stack;

// Initialize the stack
void init(Stack *s) { s->top = -1; }

// Push an element onto the stack
void push(Stack *s, char c) { s->data[++s->top] = c; }

// Pop an element from the stack
char pop(Stack *s) { return s->data[s->top--]; }

// Peek at the top element of the stack
char peek(Stack *s) { return s->data[s->top]; }

// Check if the stack is empty
int isEmpty(Stack *s) { return s->top == -1; }

// Check if a character is an operator
int isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Get the precedence of an operator
int getPrecedence(char c) {
  switch (c) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return -1;
  }
}

// Convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
  Stack s1, s2;
  int i, j, len;

  init(&s1);
  init(&s2);

  // Reverse the infix expression and push it onto stack s1
  len = strlen(infix);
  for (i = len - 1; i >= 0; i--) {
    push(&s1, infix[i]);
  }

  // Scan the infix expression from left to right
  while (!isEmpty(&s1)) 
  {
    char c = pop(&s1);

    // If the character is an operand, push it onto stack s2
    if (isalnum(c)) {
      push(&s2, c);
    }
    // If the character is an operator
    else if (isOperator(c)) {
      // Pop operators from stack s2 and push them onto stack s1 until the
      // precedence of the top operator on stack s2 is lower than the precedence
      // of the current operator
      while (!isEmpty(&s2) && getPrecedence(peek(&s2)) >= getPrecedence(c)) {
        push(&s1, pop(&s2));
      }
      // Push the current operator onto stack s2
      push(&s2, c);
    }
    // If the character is a left parenthesis, push it onto stack s2
    else if (c == '(') {
      push(&s2, c);
    }
    // If the character is a right parenthesis, pop operators from stack s2 and
    // push them onto stack s1 until a left parenthesis is encountered
    else if (c == ')') {
      while (!isEmpty(&s2) && peek(&s2) != '(') {
        push(&s1, pop(&s2));
      }
      pop(&s2);
    }
  }

  // Pop remaining operators from stack s2 and push them onto stack s1
  while (!isEmpty(&s2)) {
    push(&s1, pop(&s2));
  }

  // Reverse the prefix expression and store it in the prefix array
  j = 0;
  while (!isEmpty(&s1)) {
    prefix[j++] = pop(&s1);
  }
  prefix[j] = '\0';
}

// Driver program to test the infixToPrefix function
int main() {
  char infix[MAX_SIZE], prefix[MAX_SIZE];

  printf("Enter the infix expression: ");
  fgets(infix, MAX_SIZE, stdin);
  infix[strcspn(infix, "\n")] = '\0';

  infixToPrefix(infix, prefix);

  printf("The prefix expression is: %s\n", prefix);

  return 0;
}