#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 100

// Stack definition
typedef struct {
  char data[MAX_SIZE];
  int top;
} Stack;

// Function to initialize a stack
void init(Stack *s) { s->top = -1; }

// Function to check if stack is empty
int isEmpty(Stack *s) { return s->top == -1; }

// Function to check if stack is full
int isFull(Stack *s) { return s->top == MAX_SIZE - 1; }

// Function to push an item onto the stack
void push(Stack *s, char item) {
  if (isFull(s)) {
    printf("Stack overflow\n");
    exit(1);
  }
  s->data[++(s->top)] = item;
}

// Function to pop an item from the stack
char pop(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack underflow\n");
    exit(1);
  }
  return s->data[(s->top)--];
}

// Function to get the top item from the stack without removing it
char peek(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack underflow\n");
    exit(1);
  }
  return s->data[s->top];
}

// Function to determine the precedence of an operator
int precedence(char op) {
  switch (op) {
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

// Function to convert infix expression to postfix expression
void infixToPostfix(char *infix, char *postfix) {
  Stack s;
  init(&s);
  int i, j;
  char c;
  for (i = 0, j = -1; infix[i]; i++) 
  {
    c = infix[i];
    if (isalnum(c)) {
      postfix[++j] = c;
    } else if (c == '(') {
      push(&s, c);
    } else if (c == ')') {
      while (!isEmpty(&s) && peek(&s) != '(') {
        postfix[++j] = pop(&s);
      }
      if (!isEmpty(&s) && peek(&s) != '(') {
        printf("Invalid infix expression\n");
        exit(1);
      } else {
        pop(&s);
      }
    } else {
      while (!isEmpty(&s) && precedence(c) <= precedence(peek(&s))) {
        postfix[++j] = pop(&s);
      }
      push(&s, c);
    }
  }
  while (!isEmpty(&s)) {
    postfix[++j] = pop(&s);
  }
  postfix[++j] = '\0';
}

int main() {
  char infix[MAX_SIZE], postfix[MAX_SIZE];
  printf("Enter infix expression: ");
  fgets(infix, MAX_SIZE, stdin);
  infixToPostfix(infix, postfix);
  printf("Postfix expression: %s\n", postfix);
  return 0;
}
