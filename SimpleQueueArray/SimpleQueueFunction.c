#include "SimpleQueue.h"

int front = -1, rear = -1;

void clrscr(void) { printf("\033[1J\033[H"); }

void insertion(int queue[], int item)
{
    if (rear == SIZE-1 )
    {
        printf("\n Queue overflow");
    }
    else 
    {
        rear = rear + 1;
        queue[rear] = item;
        
        if (front == -1) 
        {
          front = 0;
        }
        printf("Success");
    }
}

/**
 * @brief Note that deletion is in the front!!
 * 
 */

// void deletion(int queue[], int item)
// {
//     int i;

//     if (front == -1 && rear == -1)
//     {
//         printf("Queue Underflow");
//     }
//     else 
//     {
//         for (i = front; i < rear; i++)
//         {
//             queue[i] = queue[i + 1];
//         }
//         rear--;                    // since we have deleating one thing, we have to reduce the position of the rear by 1
//         printf("Queue Deleated value is %d", item);
//     }
// }

void deletion(int queue[], int item) 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue underflow\n");
    } 
    else 
    {
        front++;  // just shift the front forward
    }
}

void display (int queue[])
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        
        printf("\nPrinting The Queue\n");
        for (int i = front; i <= rear; i++) 
        {
          printf("%d ", queue[i]);
        }
    }
}