#include "PriorityQueueLinkList.h"



int main() {
  

  int choice, data, priority;
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
      printf("Enter the data: ");
      scanf("%d", &data);

      printf("Enter the priority: ");
      scanf("%d", &priority);
      enqueue(data, priority);
      break;

    case 2:
      dequeue();
      break;

    case 3:
      print_priority_queue();
      break;

    case 4:
      exit(0);
      break;

    default:
      printf("Wrong Choice");
    }
  }
}