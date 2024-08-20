#include "stack.h"

int stack[MAX];
int top = -1;

void push(int stack[], int item)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    top++;
    stack[top] = item;
    printf("success");
}


int peek(int stack[])
{
    if (top == -1)
    {
        printf("\nStack is empty");
        return -1;
    }
    else 
    {
        return (stack[top]);
    }
}

int pop(int stack[])
{
    int item;
    if (top == -1)
    {
        printf("\nStack underflow");
        return -1;
    }
    else 
    {
        item = stack[top];
        top--;
        printf("Item deleted is %d ", item);
        return item;
    }
   
}

void display(int stack[])
{
    if (top == -1)
    {
        printf("\nStackOverflow");
    }
    for (int i = top; i >= 0; i--)
    {
        printf("\n%d", stack[i]);
    }
}