#include "DequeueMain.h"



int main()
{
    int size, choice, element;
    clrscr();

    printf("Enter the size of the Deque: ");
    scanf("%d", &size);
    initDeque(size);


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
      printf("8. Check if Deque is empty\n");
      printf("9. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) 
      {
      case 1:
        printf("Enter the element to add: ");
        scanf("%d", &element);
        enqueue_front(element);
        break;

      case 2:
        printf("Enter the element to add: ");
        scanf("%d", &element);
        enqueue_rear(element);
        break;

      case 3:
        printf("Removed element from front:%d\n", dequeue_front());
        break;
        
      case 4:
        printf("Removed element from rear: %d\n", dequeue_rear());
        break;


      case 5:
        printf("Front element: %d\n", get_front());
        break;


      case 6:
        printf("Rear element: %d\n", get_rear());
        break;


      case 7:
        if (isFull()) 
        {
          printf("Deque is full!\n");
        } 
        else 
        {
          printf("Deque is not full.\n");
        }
        break;


      case 8:
        if (isEmpty()) 
        {
          printf("Deque is empty!\n");
        } 
        else 
        {
          printf("Deque is not empty.\n");
        }
        break;


      case 9:
        printf("Exiting program.\n");
        exit(0);

        
      default:
        printf("Invalid choice. Please try again.\n");
      }
    }

    return 0;
}