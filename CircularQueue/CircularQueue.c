#include "CircularQueue.h"

void clrscr(void) { printf("\033[1J\033[H"); }

Queue *createQueue() 
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = q->rear = -1;
  return q;
}

int isEmpty(Queue *q) { return q->front == -1; }

int isFull(Queue *q) { return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); }

void enqueue(Queue *q, int item) 
{
  if (isFull(q)) 
  {
    printf("Queue is full\n");
    return;
  }
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  q->data[q->rear] = item;
  if (q->front == -1) 
  {
    q->front = q->rear;
  }
}

int dequeue(Queue *q) 
{
  int item;
  if (isEmpty(q)) 
  {
    printf("Queue is empty\n");
    return -1;
  }
  item = q->data[q->front];
  if (q->front == q->rear) 
  {
    q->front = q->rear = -1;
  } 
  else 
  {
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  }
  return item;
}

void printQueue(Queue *q) 
{
  if (isEmpty(q)) 
  {
    printf("Queue is empty!\n");
    return;
  }

  printf("\nPrinting Queue\n");
  for (int i = q->front; i <= q->rear; i++) 
  {
    printf("%d ", q->data[i]);
  }
  printf("\n");
}

// int main() {
//   Queue *q = createQueue();
//   enqueue(q, 1);
//   enqueue(q, 2);
//   enqueue(q, 3);
//   printf("Dequeued item: %d\n", dequeue(q));
//   printf("Dequeued item: %d\n", dequeue(q));
//   printf("Dequeued item: %d\n", dequeue(q));
//   return 0;
// }
