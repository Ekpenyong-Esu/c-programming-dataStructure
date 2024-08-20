#include "PriorityQueueLinkList.h"


struct node *head = NULL;

void clrscr(void) { printf("\033[1J\033[H"); } // use clearing the screen

void enqueue(int data, int priority) 
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->priority = priority;
  new_node->next = NULL;

  if (head == NULL || priority < head->priority) 
  {
    new_node->next = head;
    head = new_node;
  } 
  else 
  {
    struct node *temp = head;
    while (temp->next != NULL && temp->next->priority <= priority) 
    {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
}

int dequeue() 
{
  if (head == NULL) 
  {
    printf("Priority queue is empty.\n");
    return -1;
  }
  int data = head->data;
  struct node *temp = head;
  head = head->next;
  free(temp);
  return data;
}

void print_priority_queue() 
{
  if (head == NULL) 
  {
    printf("Priority queue is empty.\n");
    return;
  }
  struct node *temp = head;
  printf("Priority queue: ");
  while (temp != NULL) 
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// int main() {
//   enqueue(3, 1);
//   enqueue(7, 3);
//   enqueue(2, 2);
//   enqueue(5, 4);
//   enqueue(1, 2);

//   int dequeued_data = dequeue();
//   printf("Dequeued element: %d\n", dequeued_data);

//   return 0;
// }
