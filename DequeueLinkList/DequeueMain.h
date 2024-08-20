#ifndef E59F55D2_478F_4A0F_8DBC_D96C7E6E5AAD
#define E59F55D2_478F_4A0F_8DBC_D96C7E6E5AAD

#include <stdio.h>
#include <stdlib.h>

// Define the Dequeue node structure
typedef struct node {
  int data;
  struct node *next;
} Node;

// Define the Dequeue structure
typedef struct dequeue {
  Node *front;
  Node *rear;
} Dequeue;

void clrscr(void);
int isEmpty(Dequeue *dequeue);
void addFront(Dequeue *dequeue, int data);
void addRear(Dequeue *dequeue, int data);
int removeFront(Dequeue *dequeue);
int removeRear(Dequeue *dequeue);
void printDeque(Dequeue *dequeue);

Node *createNode(int data);
Dequeue *createDequeue();

#endif /* E59F55D2_478F_4A0F_8DBC_D96C7E6E5AAD */
