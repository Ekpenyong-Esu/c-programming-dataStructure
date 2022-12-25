#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int arr[], size_t size, int element)
{
    int i;

    for (i = 0; i < size; i++) // Search the array from left to write if the array member == element
    {                          // return the array location of the element
        if (arr[i] == element)
        {
            return i;
        }
    }

    return -1;
}

void clrscr(void) { printf("\033[1J\033[H"); } // use clearing the screen

#define size 20

int main()
{

    clrscr();
    int i, n, value;
    int arr[size]; //= {23, 15, 47, 9, 30, 33, 90, 77, 100, 11};

    printf("***LINEAR SEARCH ***");     // welcome message
    printf("\nEnter no of elements: "); // Enter the number of element you want in the arrray
    scanf("%d", &n);

    if (n == size)
    {
        printf("Stack overflow"); // if the number of element im looking for is bigger than the array
        exit(0);                  // print error
    }

    printf("Enter the elements of array "); // Enter the elements here
    // Accepting the elements of array
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter value to search: "); // Enter the search value here
    scanf("%d", &value);

    // size_t size = sizeof(arr)/sizeof(int);

    int result = LinearSearch(arr, n, value);

    if (result == -1)
    {
        printf("The Element  is not found: ");
    }
    else
    {
        printf("The Element is found at: %d", result + 1);
    }
}