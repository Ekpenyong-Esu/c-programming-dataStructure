#include "SimpleQueue.h"


int main()
{
    
    int queue[SIZE], value, choice;

    clrscr();
    
    while (1)
    {

    
        printf("\n***MENU****\n");
        printf("\n1. INSERTION IN QUEUE");
        printf("\n2. DELETION IN QUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter Value to insert: ");
                scanf("%d", &value);

                insertion(queue,value);
                break;

            case 2:
                deletion(queue, value);
                break;

            case 3:
                display(queue);
                break;
            
            case 4:
                printf("!!Exit!!");
                exit(0);

            default:
                printf("Wrong Choice");
        }
    }
}