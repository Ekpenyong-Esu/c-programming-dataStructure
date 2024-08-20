

#include "DequeueMain.h"

void clrscr(void) { printf("\033[1J\033[H"); } // use clearing the screen



// Function to create a new Dequeue node
Node *createNode(int data) 
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to create a new Dequeue
Dequeue *createDequeue() 
{
  Dequeue *newDequeue = (Dequeue *)malloc(sizeof(Dequeue));
  newDequeue->front = NULL;
  newDequeue->rear = NULL;
  return newDequeue;
}

// Function to check if the Dequeue is empty
int isEmpty(Dequeue *dequeue) { return (dequeue->front == NULL); }

// Function to add an element to the front of the Dequeue
void addFront(Dequeue *dequeue, int data) 
{
  Node *newNode = createNode(data);
  if (isEmpty(dequeue)) 
  {
    dequeue->front = newNode;
    dequeue->rear = newNode;
  } 
  else 
  {
    newNode->next = dequeue->front;
    dequeue->front = newNode;
  }
  printf("Element %d added to the front of the Dequeue\n", data);
}

// Function to add an element to the rear of the Dequeue
void addRear(Dequeue *dequeue, int data) 
{
  Node *newNode = createNode(data);
  if (isEmpty(dequeue)) 
  {
    dequeue->front = newNode;
    dequeue->rear  = newNode;
  } 
  else 
  {
  dequeue->rear->next = newNode;
  dequeue->rear = newNode;
  }
  printf("Element %d added to the rear of the Dequeue\n", data);
}

// Function to remove an element from the front of the Dequeue
int removeFront(Dequeue *dequeue) 
{
  if (isEmpty(dequeue)) 
  {
  printf("Dequeue is empty, cannot remove element from front\n");
  return -1;
  }
  int data = dequeue->front->data;
  Node *temp = dequeue->front;
  dequeue->front = dequeue->front->next;
  free(temp);
  if (dequeue->front == NULL) {
  dequeue->rear = NULL;
  }
  printf("Element %d removed from the front of the Dequeue\n", data);
  return data;
}

// Function to remove an element from the rear of the Dequeue
int removeRear(Dequeue *dequeue) 
{
  if (isEmpty(dequeue)) 
  {
  printf("Dequeue is empty, cannot remove element from rear\n");
  return -1;
  }
  int data = dequeue->rear->data;
  Node *temp = dequeue->rear;
  if (dequeue->front == dequeue->rear) 
  {
  dequeue->front = NULL;
  dequeue->rear = NULL;
  } else {
  Node *current = dequeue->front;
  while (current->next != dequeue->rear) 
  {
    current = current->next;
  }
  dequeue->rear = current;
  current->next = NULL;
  }
  free(temp);
  printf("Element %d removed from the rear of the Dequeue\n", data);
  return data;
}

void printDeque(Dequeue *dequeue) 
{
  if (isEmpty(dequeue)) 
  {
  printf("Dequeue is empty, cannot remove element from rear\n");
  return;
  }

  Node *current = dequeue->front;
  
  printf("\nPrinting Items\n");
  while (current != NULL) 
  {
  printf("%d ", current->data);
  current = current->next;
  }
  printf("\n");
}

// Main function to test the Dequeue
// int main() 
// {
//   Dequeue *dequeue = createDequeue();
//   addFront(dequeue, 1);
//   addFront(dequeue, 2);
//   addRear(dequeue, 3);
//   addRear(dequeue, 4);
//   removeFront(dequeue);
//   removeRear(dequeue);
//   removeFront(dequeue);
//   removeRear(dequeue);
//   removeFront(dequeue);
//   return 0;
// }