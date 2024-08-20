#include "PriorityQueueArray.h"

int main() {
  

  int choice, item;
  clrscr();

  while (1) {

    printf("\n***MENU****\n");
    printf("\n1. INSERT");
    printf("\n2. REMOVE_MAX");
    printf("\n3. PRINT PRIORITY QUEUE");
    printf("\n4. EXIT");
    printf("\nENTER YOUR CHOICE: ");

    scanf("%d", &choice);

    switch (choice) {

    case 1:
      printf("Enter an Item to the Queue: ");
      scanf("%d", &item);
      insert(item);
      break;

    case 2:
      remove_max();
      break;

    case 3:
      print();
      break;

    case 4:
      exit(0);
      break;

    default:
      printf("Wrong Choice");
    }
  }
}