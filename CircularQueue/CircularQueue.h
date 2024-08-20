#ifndef E0DA6D2C_DA02_4874_8DF0_04A9097CC19D
#define E0DA6D2C_DA02_4874_8DF0_04A9097CC19D


#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
  int data[MAX_QUEUE_SIZE];
  int front, rear;
} Queue;

Queue *createQueue();
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
void printQueue(Queue *q);
void clrscr();

#endif /* E0DA6D2C_DA02_4874_8DF0_04A9097CC19D */
