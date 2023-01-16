#include <stdio.h>
#include <stdlib.h>


int binarySearch(int arr[], int size, int key)
{
    int mid, low = 0, high = size-1;

    while (low <= high)
    {
        mid = (high + low) / 2;

        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

    }
    
    return -1;
    
}

void clrscr(void) { printf("\033[1J\033[H"); }

int main()
{

    int size;
    int key;
    clrscr();

    printf("Enter the size of the array: ");

   

    scanf("%d", &size);

    int *ptr = (int *)malloc(size * sizeof(int));

    if (ptr == NULL)
    {
        printf("Can not allocate array!");
        return 0;
    }


    printf("Enter %d number of elements\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d",ptr + i);
    }

    printf("Enter the key\n");
    
    scanf("%d", &key);
    int result = Binary_Search(ptr, size, key);

    if (result == -1)
    {
        printf("Key not found!");
    }
    else
    {
        printf("The index id is %d: ", result);
    }

    free(ptr);
}