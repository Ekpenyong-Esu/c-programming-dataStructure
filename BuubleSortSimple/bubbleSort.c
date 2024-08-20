#include <stdio.h>

#include <stdlib.h>
void swap(int *xp, int *yp) 
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}


void bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
            swap(&arr[j], &arr[j + 1]) ;   
            }
        }
    }
    printf("The array is sorted in asccending order");
}

void clrscr(void) { printf("\033[1J\033[H"); }

int main()
{
    int arr[10], i, j, num;

    printf("Enter the number of elements: ");
    scanf_s("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("Enter your element %d: ", i+1);
        scanf_s("%d", &arr[i]);
    }


    bubbleSort(arr,num);
    printf("[ ");
    for(int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    printf(" ]");
}


