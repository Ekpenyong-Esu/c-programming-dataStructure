#include <stdio.h>
#include <stdlib.h>

void clrscr(void) { printf("\033[1J\033[H"); }

void arrayReverse1(int *ptr, int size)
{
    int *tempArray = (int *)malloc(size * sizeof(int));
    if (tempArray == NULL)
    {
        printf("Array Reverse Alocation problem");
    }

    for(int i = 0, j = size - 1; i < size; i++, j--)
    {
        *(tempArray + i) = *(ptr + j);
    }

    for (int i = 0; i < size; i++)
    {
        ptr[i] = tempArray[i];
    }
}

void arrayReverse2(int *ptr, int size)
{
    int temp;

    for (int i = 0, j = size-1; i < size/2; i++, j--) // divide the size into two so that what you swap will not reswap the secnd time
    {
        temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
    }
}

void leftShift(int *arr, int size, int shift)
{
    for (int i = 0; i < shift; i++)
    {
        int temp = arr[0];
        for (int j = 0; j < size - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }
}

int main()
{

    clrscr();
    int const size = 6;
    int const size1 = 7;
    int arr[] = {10,20,30,40,50,60};
    int arr1[] = {100, 200, 300, 400, 500, 600, 700};

    arrayReverse1(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i] );
    }
    putchar('\n');

    arrayReverse2(arr1, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr1[i]);
    }
}

