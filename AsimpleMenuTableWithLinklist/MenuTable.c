#include "MenuTable.h"



int main()
{
    clrscr();
    int choice, data;
    //struct node *head = NULL;

    do
    {
        printf("\nSINGLY LINKED LISTS\n");
        printf("\n\tMENU");
        printf("\n 1: addition at beginning");
        printf("\n 2: addition after given node");
        printf("\n 3: addition before given node");
        printf("\n 4: addition at end");
        printf("\n 5: deletion at beginning");
        printf("\n 6: deletion at middle");
        printf("\n 7: deletion at end");
        printf("\n 8: print linklist");
        printf("\n Exit:");
        //printf(" \n : Exit");
        printf("Enter your choice: ");
      

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_node_at_begining();
            break;


        case 2:
            printf("\nEnter the Data: ");
            scanf("%d",&data);
            add_node_after(data);
            break;

        case 3:
            printf("\nEnter the  Data: ");
            scanf("%d", &data);
            add_node_before(data);
            break;

        case 4:
            add_node_at_end();
            break;


        case 5:
            printf("\nEnter the Data: ");
            scanf("%d", &data);
            delete_node(data);
            break;

        case 6:
            printf("\nEnter the Data: ");
            scanf("%d", &data);
            delete_node(data);
            break;

        case 7:
            printf("\nEnter the Data: ");
            scanf("%d", &data);
            delete_node(data);
            break;

        case 8:
            printList();
            break;

        case 9:
        exit(0);

        default:
            printf("Wrong Choice");
            break;
        }

    } while (choice != 0);
    
}