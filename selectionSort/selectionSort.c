#include <stdio.h>
#include <stdlib.h>

void clrscr(void) { printf("\033[1J\033[H"); } // use clearing the screen

int main()
{

    clrscr(); // use for clearing the screen
    int i, j, arr[20], n, temp;

    printf("Enter no of elements in the array: "); // use for getting the number of ellement we want in the array
    scanf("%d", &n);

    printf("Elements in the array are\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    /*
    Test the second element in the arr with the first one, if the second one is lower than the first one,
    swap the elements if not leave it and at the same time check if the boundary requirement are met
    */
    printf("Selection Sort");
    for (i = 1; i < n; i++)
    {
        j = i;                                            // j = i
        for (; (j > 0) && (arr[j] < arr[j - 1]); j--) // while((j > 0) && (arr[j] < arr[i + 1])
        {
        temp = arr[j];                                // j--
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        }
    
    }

    printf("\nAfter Sorting new array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}