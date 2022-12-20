#include "main.h"  // user define header file




void clrscr(void) { printf("\033[1J\033[H"); }

void main()
{
    int i, n, choice, arr[20];
    clrscr();
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    printf("Enter the elements of array ");
    // Accepting the elements of array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n***MENU ***\n");

    printf("1. Insertion in beginning \n");
    printf("2. Insertion at specified location \n");
    printf("3. Insertion at end \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (n == 10)
    {
        printf("Overflow error ");
        exit(0);
    }
    else
        switch (choice)
        {
        case 1:
            arrayInsertBegining(arr, n);
             break;
        case 2:
             arrayInsertAnyLocation(arr, n);
              break;
        case 3:
              arrayInsertAnyLocation(arr, n);
               break;
        default:
            printf("Wrong Choice");
            exit(0);
        }
    // End of switch case
    getch();
} // End of main
