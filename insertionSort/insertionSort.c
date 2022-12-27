#include <stdio.h>
#include <stdlib.h>

void clrscr(void) { printf("\033[1J\033[H"); } // use clearing the screen

int main()
{

    clrscr();                            // use for clearing the screen
    int i, j, arr[20], n, temp;

    printf("Enter no of elements in the array: ");  // use for getting the number of ellement we want in the array
    scanf("%d", &n);
    printf("Elements in the array are\n");         

    for(i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Selection Sort");

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)

        if(arr[j] < arr[i])            // if the second element in the array is greater than the first element 
        {
            temp = arr[j];            // then swap
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    printf("\nAfter Sorting new array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}