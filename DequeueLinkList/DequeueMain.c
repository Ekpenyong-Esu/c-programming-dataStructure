#include "DequeueMain.h"

int main() {
  int size, choice, element, item;
  Dequeue *dequeue = createDequeue();
  clrscr();

  while (1) 
  {
    printf("\n");
    printf("1. Add element to front\n");
    printf("2. Add element to rear\n");
    printf("3. Remove element from front\n");
    printf("4. Remove element from rear\n");
    printf("5. Get front element\n");
    printf("6. Get rear element\n");
    printf("7. Check if Deque is full\n");
    printf("8. Printing Dequeue\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) 
    {
    case 1:
      printf("Enter the element to add: ");
      scanf("%d", &element);
      addFront(dequeue, element);
      break;

    case 2:
      printf("Enter the element to add: ");
      scanf("%d", &element);
      addRear(dequeue, element);
      break;

    case 3:
      printf("\nRemoved element from front:%d\n", removeFront(dequeue));
      break;

    case 4:
      printf("Removed element from rear: %d\n", removeRear(dequeue));
      break;

    case 5:
      item = removeFront(dequeue);
      printf("Front element: %d\n", item);
      break;

    case 6:
      item = removeRear(dequeue);
      printf("Rear element: %d\n", item);
      break;

    case 7:
      if (isEmpty(dequeue)) 
      {
        printf("Deque is empty!\n");
      } else {
        printf("Deque is not empty.\n");
      }
      break; 
    
    case 8:
      printDeque(dequeue);
      break;


    case 9:
      printf("Exiting program.\n");
      exit(0);

    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  }

  return 0;
}