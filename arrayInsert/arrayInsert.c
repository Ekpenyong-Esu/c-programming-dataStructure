
// user define header file
#include "main.h"

void arrayInsertBegining(int arr[], int n)
{
    int i, value;
    for (i = n - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    printf("Enter new value : ");
    scanf("%d", &value);
    arr[0] = value;
    printf("After insertion array is ");
    for (i = 0; i <= n; i++)
    {
        printf("\t%d", arr[i]);
    }
}

void arrayInsertAnyLocation(int arr[], int n)
{
    int i, value, pos;
    printf("Enter position ");
    scanf("%d", &pos);
    for (i = n - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    printf("Enter new value: ");
    scanf("%d", &value);
    arr[pos - 1] = value;
    printf("After insertion array is ");
    for (i = 0; i <= n; i++)
    {
        printf("\t%d ", arr[i]);
    }
}

void arrayInsertEnd(int arr[], int n)
{
    int i, value;
    printf("Enter new value: ");
    scanf("%d", &value);
    arr[n] = value;
    printf(" After insertion array is ");
    for (i = 0; i <= n; i++)
    {
        printf("\t%d", arr[i]);
    }
}
