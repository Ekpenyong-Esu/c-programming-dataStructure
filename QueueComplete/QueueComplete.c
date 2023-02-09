#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Queue {
  int front;
  int rear;
  int data[MAX_QUEUE_SIZE];
};

struct Queue *createQueue() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = 0;
  q->rear = -1;
  return q;
}

int isFull(struct Queue *q) { return q->rear == MAX_QUEUE_SIZE - 1; }

int isEmpty(struct Queue *q) { return q->rear < q->front; }

void enqueue(struct Queue *q, int item) {
  if (isFull(q)) {
    printf("Queue is full!\n");
    return;
  }
  q->rear++;
  q->data[q->rear] = item;
}

int dequeue(struct Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty!\n");
    return -1;
  }
  int item = q->data[q->front];
  q->front++;
  return item;
}

void printQueue(struct Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty!\n");
    return;
  }
  for (int i = q->front; i <= q->rear; i++) {
    printf("%d ", q->data[i]);
  }
  printf("\n");
}

int main() {
  struct Queue *q = createQueue();
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  printQueue(q);
  dequeue(q);
  printQueue(q);
  return 0;
}
