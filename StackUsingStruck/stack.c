#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct stack {
  int data[MAX_SIZE];
  int top;
};

// Function to check if the stack is empty
int isEmpty(struct stack *s) { return s->top == -1; }

// Function to check if the stack is full
int isFull(struct stack *s) { return s->top == MAX_SIZE - 1; }

// Function to push an element onto the stack
void push(struct stack *s, int value) {
  if (isFull(s)) {
    printf("Stack Overflow!\n");
    return;
  }
  s->top++;
  s->data[s->top] = value;
}

// Function to pop an element from the stack
int pop(struct stack *s) {
  if (isEmpty(s)) {
    printf("Stack Underflow!\n");
    return -1;
  }
  int popped = s->data[s->top];
  s->top--;
  return popped;
}

// Function to display the elements in the stack
void display(struct stack *s) {
  if (isEmpty(s)) {
    printf("Stack is empty!\n");
    return;
  }
  printf("Stack: ");
  for (int i = s->top; i >= 0; i--) {
    printf("%d ", s->data[i]);
  }
  printf("\n");
}

int main() {
  // Create a stack object
  struct stack s;
  s.top = -1;

  // Push some elements onto the stack
  push(&s, 10);
  push(&s, 20);
  push(&s, 30);

  // Display the elements in the stack
  display(&s);

  // Pop an element from the stack
  int popped = pop(&s);
  printf("Popped element: %d\n", popped);

  // Display the elements in the stack
  display(&s);

  return 0;
}
