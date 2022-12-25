#include <stdio.h>
#include <conio.h>

void clrscr(void) { printf("\033[1J\033[H"); } // use clearing the screen

void main()
{
    int arr1[10], arr2[10], arr3[20];
    size_t arr1_size, arr2_size, s;
    int i = 0, j = 0, k = 0;

    clrscr();

    printf("Enter number of elements in array 1: ");
    scanf("%d", &arr1_size);

    printf("Enter elements of array: \n");
    for (s = 0; s < arr1_size; s++)
    {
        printf("Enter element %d: ", s + 1);
        scanf("%d", &arr1[s]);
    }

    printf("Enter number of elements in array 2: ");
    scanf("%d", &arr2_size);

    printf("Enter elements of array: \n");
    for (s = 0; s < arr2_size; s++)
    {
        printf("Enter element %d: ", s + 1);
        scanf("%d", &arr2[s]);
    }

    while (i < arr1_size && j < arr2_size)   // Note imediately any of the conditions are not mate, the loop will terminate most especially in 
    {                                        // when the array sizes are not the same                   
        if (arr1[i] < arr2[j])         // In the sorted array, if arr1[i] is greater than arr2[j]
        {                               // then copy arr1[i] into arr3[k]
            arr3[k] = arr1[i];
            k++;                        // increment k to point to the next index of the array
            i++;                        // increment i to point to the next index of the arr
        }
        else if (arr2[j] < arr1[i])         // else if arr2[j] is less than arr[i]
        {
            arr3[k] = arr2[j];              // copy arr2[j] into arr3[k] and increment k and j
            j++;
            k++;
        }
        else
        {
            arr3[k] = arr1[i];                 // Else if they are the same, copy arr[i] into arr[k]
            k++;                                // increment k
            i++;                                // increment i
            arr3[k] = arr2[j];                     // the same thing is don for arr2[j]
            k++;
            j++;
        }  
        
    }// end of the loop

    while (i < arr1_size)                          // if the arr1 size and arr2 size are not the same and was cut short then the remaining part need to be accounted for
    {                                                // the remaining part will be coppied into the third arr3
        arr3[k] = arr1[i];
        k++;
        i++;
    }

    while (j < arr2_size)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }

    printf("After merging new array is: ");
    for (s = 0; s < (arr1_size + arr2_size); s++)     // Note the size of array three is the combination of arr1_size and arr2_size
    {
        printf("%d ", arr3[s]);
    }

}
