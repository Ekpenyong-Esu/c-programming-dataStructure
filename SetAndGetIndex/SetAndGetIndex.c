#include <stdio.h>
#include <stdlib.h>


int getArray(int arr[], int size, int index)
{
    if (index >= 0 && index < size)
    {
        return arr[index];
    }

    return -1;
}


void setArrayValue(int *ptr, int size, int value, int index)
{
    if (index >= 0 && index < size)
    {
        *(ptr + index) = value;
    }
}

void clrscr(void) { printf("\033[1J\033[H"); }

int main()
{
    int size;
    int value;
    int index;
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
        scanf("%d", ptr + i);
    }

    printf("\nEnter 1 for Set Array\nEnter -1 to exit:\nEnter 2 for Getting index of Array: ");
    int num;
    scanf("%d", &num);
    if (num != -1 || num != 1 || num !=2)
    {
        printf("Invalid Input");
        return 0;
    }

    while (num != -1)
    {
        switch (num)
        {
         case 1:
            printf("Array Set\n");
            printf("Enter the index: ");
            scanf("%d", &index);
            printf("Enter the value: ");
            scanf("%d", &value);
            setArrayValue(ptr, size, value, index);
            break;

         case 2:
            printf("Array Set\n");
            printf("Enter the index: ");
            scanf("%d", &index);
            int result = getArray(ptr, size, index);
            printf("The Array in index is %d is %d\n", index, result);
            break;

         default:
            break;
        }

        printf("\nEnter 1 for Set Array\nEnter -1 to exit:\nEnter 2 for Getting index of Array: ");
        scanf("%d", &num);
    }

    free(ptr);
    
}