#include "stack.h"

int main()
{
    int stack[20], item, ch;

    while (1)
    {
        printf("\n********MENU******");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) 
        {
            case 1:
                printf("Enter value to push");
                scanf("%d", &item);
                push(stack, item);
                break;

            case 2:
                pop(stack);
                break;
            
            case 3:
                item = peek(stack);
                if (item != -1)
                {
                    printf("The value at the top of the stack is %d", item);
                }
                break;

            case 4:
                display(stack);
                break;

            case 5:
                printf("!!Exit!!");
                exit(0);

            default:
                printf("Wrong choice");


        }
    }
}