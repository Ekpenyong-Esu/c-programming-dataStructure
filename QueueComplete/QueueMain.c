#include "QueueComplete.h"
#include <stdlib.h>


int main() 
{
  struct Queue *queue = queue = createQueue();


  int choice, item;
  clrscr();

  while (1) {

    printf("\n***MENU****\n");
    printf("\n1. ENQUEUE");
    printf("\n2. DEQUEUE");
    printf("\n3. PRINT QUEUE");
    printf("\n4. EXIT");
    printf("\nENTER YOUR CHOICE: ");

    scanf("%d", &choice);

    switch (choice) {

    case 1:
      printf("Enter an Item to the Queue: ");
      scanf("%d", &item);
      enqueue(queue, item);
      break;

    case 2:
      dequeue(queue);
      break;

    case 3:
      printQueue(queue);
      break;

    case 4:
      exit(0);
      break;

    default:
      printf("Wrong Choice");
    }
    }
}