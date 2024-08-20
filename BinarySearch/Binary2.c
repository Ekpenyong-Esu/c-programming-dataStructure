#include <stdio.h>

// Function to perform binary search in a sorted array
int binary_search(int arr[], int size, int key) 
{
  int low = 0;
  int high = size - 1;

  while (low <= high) 
  {
    int mid = (low + high) / 2;

    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1; // key not found
}

int main() 
{
  int arr[] = {1, 3, 5, 7, 9, 11, 13};
  int size = sizeof(arr) / sizeof(arr[0]);
  int key = 7;

  int index = binary_search(arr, size, key);

  if (index == -1) 
  {
    printf("Key not found\n");
  } else {
    printf("Key found at index %d\n", index);
  }

  return 0;
}
