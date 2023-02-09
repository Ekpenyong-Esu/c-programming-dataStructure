#include "HeaderLinklist.h"


int main()
{
    int choice;
    clrscr();

    do 
    {
        printf("\nHeader Link List\n");
        printf("\n\tMENU");
        printf("\n1 : Create List");
        printf("\n2 : Display");
        printf("\n3 : Exit\n");
        printf("Enter Your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
              create_header_list();
              break;
            
            case 2:
              display();
              break;
            
            case 3:
              exit(0);


            default:
              printf("Invalid option");
              break;
        }

    }while (choice != 3);
}