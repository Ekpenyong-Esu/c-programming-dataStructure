
// user define header file
#include "main.h"

void arrayDeleteBegining(int arr[], int n)
{
    int i;
    for (i = 0; i < n-1; i++) // shift the first element by right. the size is always lower than the normal
    {                         // by 1 because index is 0
        arr[i + 1] = arr[i];    
    } 
    printf("After deletion array is ");
    for (i = 0; i < n-1; i++)        
    {
        printf("\t%d", arr[i]);
    }
}

void arrayDeleteAnyLocation(int arr[], int n)
{
    int i, pos;
    printf("Enter position ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > n)
    {
        printf("Out of range");
        exit(-1);
    }

    for (i = pos - 1; i < n-1; i++) // position is always one position ahead since the index start from 0
    {
        arr[i] = arr[i + 1];
    }

    printf("After deletion array is ");
    for (i = 0; i < n-1; i++)
    {
        printf("\t%d ", arr[i]);
    }
}

void arrayDeleteEnd(int arr[], int n)
{
    int i;
    n -= 1;
    printf(" After deletion array is ");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", arr[i]);
    }
}
