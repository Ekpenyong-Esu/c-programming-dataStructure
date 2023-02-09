#include "CircularHeaderLinkList.h"

int main() 
{
  int choice, item;
  clrscr();

  do 
  {
    printf("\n Circular Header Link List\n");
    printf("\n\tMENU");
    printf("\n1 : Create List");
    printf("\n2 : Delete");
    printf("\n3 : Display");
    printf("\n3 : Exit\n");
    printf("Enter Your choice: ");
    fflush(stdout);

    scanf("%d", &choice);

    switch (choice) {
    case 1:
      CreateCircularHeaderLinkList();
      break;

    case 2:
    {
        printf("Enter Item you want to delete: ");
        scanf("%d", &item);
        deleteNode(item);
        break;
    }

    case 3:
        display();
        break;

    case 4:
        exit(0);
        break;


    default:
      printf("Invalid option");
      break;
    }

  } while (choice != 4);
}