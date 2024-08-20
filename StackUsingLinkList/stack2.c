#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *top = NULL;

void push(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = top;
  top = newNode;
}

void pop() {
  if (top == NULL) {
    printf("Stack is empty.\n");
    return;
  }
  struct Node *temp = top;
  top = top->next;
  free(temp);
}

int peek() {
  if (top == NULL) {
    printf("Stack is empty.\n");
    return -1;
  }
  return top->data;
}

void display() {
  if (top == NULL) {
    printf("Stack is empty.\n");
    return;
  }
  struct Node *temp = top;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  display();
  pop();
  pop();
  display();
  printf("Top element is %d.\n", peek());
  return 0;
}
