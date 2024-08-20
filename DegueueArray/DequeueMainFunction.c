#include "DequeueMain.h"



#define MAX_SIZE 100

int deque[MAX_SIZE];
int front = -1, rear = -1;

void clrscr(void) { printf("\033[1J\033[H"); } // use clearing the screen

int isFull() 
{
  if ((front == 0 && rear == MAX_SIZE - 1) ||
      (front == rear + 1)) // (front == rear + 1) means if the rear position is onee position behind the front
  {
    return 1;
  }
  return 0;
}

int isEmpty() 
{
  if (front == -1) 
  {
    return 1;
  }
  return 0;
}

void initDeque(int size) 
{
  if (size > MAX_SIZE) 
  {
    printf("Deque size exceeds maximum limit!\n");
    exit(1);
  }
  front = rear = -1;
}

void enqueue_front(int x) 
{
  if (front == 0 && rear == MAX_SIZE - 1) 
  {
    printf("Deque is full\n");
  } 
  else if (front == -1 && rear == -1) 
  {
    front = rear = 0;
    deque[front] = x;
  } 
  else if (front == 0) 
  {
    front = MAX_SIZE - 1;  // if the front of queue is already in the zero position which is the begining of the queue
                            // we add the element to the end of the queue and move the front to that position
    deque[front] = x;
  } 
  else 
  {
    deque[--front] = x;
  }
}

void enqueue_rear(int x) 
{
  if (front == 0 && rear == MAX_SIZE - 1) 
  {
    printf("Deque is full\n");
  } 
  else if (front == -1 && rear == -1) 
  {
    front = rear = 0;
    deque[rear] = x;
  } 
  else if (rear == MAX_SIZE - 1) // if the rear is already in the end of the queue, move the rear to the 
                                // begining of the queue and add the element there.
  {
    rear = 0;
    deque[rear] = x;
  } 
  else 
  {
    deque[++rear] = x;
  }
}

int dequeue_front() 
{
    int element;
  if (front == -1 && rear == -1) 
  {
    printf("Deque is empty\n");
    return -1;
  } 

  element = deque[front];
  if (front == rear) // any time the rear == front, that means the queue is empty
  {
    front = rear = -1;
  } 
  else if (front == MAX_SIZE - 1) 
  {
    front = 0;
  } 
  else 
  {
    front++;
  }
  return element;
}

int dequeue_rear() 
{
  int element;
  if (front == -1 && rear == -1) 
  {
    printf("Deque is empty\n");
    return -1;
  }
  element = deque[rear]; 

  if (front == rear) 
  {
    front = rear = -1;
  } 
  else if (rear == 0) 
  {
    rear = MAX_SIZE - 1;
  } 
  else 
  {
    rear--;
  }
  return element;
}

int get_front() 
{
  if (front == -1 && rear == -1) 
  {
    printf("Deque is empty\n");
    return -1;
  } 
  else 
  {
    return deque[front];
  }
}

int get_rear() 
{
  if (front == -1 && rear == -1) 
  {
    printf("Deque is empty\n");
    return -1;
  } 
  else 
  {
    return deque[rear];
  }
}

void print_deque() 
{
  if (front == -1 && rear == -1) 
  {
    printf("Deque is empty\n");
    return;
  }
  printf("The deque contains: ");

  for (int i = front; i <= rear; i++) 
  {
    printf("%d ", deque[i]);
  }
  printf("\n");
  

}

  // int main() {
  //   enqueue_rear(5);
  //   enqueue_rear(10);
  //   enqueue_front(3);
  //   enqueue_front(1);

  //   printf("%d\n", get_front()); // 1
  //   printf("%d\n", get_rear());  // 10

  //   dequeue_front();
  //   dequeue_rear();

  //   printf("%d\n", get_front()); // 3
  //   printf("%d\n", get_rear());  // 5

  //   return 0;
  // }
