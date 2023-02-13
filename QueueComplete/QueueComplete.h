#ifndef QUEUECOMPLETE_H
#define QUEUECOMPLETE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

struct Queue {
  int front;
  int rear;
  int data[MAX_QUEUE_SIZE];
};

struct Queue *createQueue();
bool isFull(struct Queue *q);
bool isEmpty(struct Queue *q);
void enqueue(struct Queue *q, int item);
int dequeue(struct Queue *q);
void printQueue(struct Queue *q);
void clrscr(void);


#endif