#include <stdio.h>

int linearSearch(int arr[], int n, int x)
 {
  int i;
  for (i = 0; i < n; i++) 
  {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1; // element not found
}

int main() 
{
  int arr[] = {6, 5, 2, 1, 3, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 2;

  int result = linearSearch(arr, n, x);

  if (result == -1) 
  {
    printf("Element not found\n");
  } else {
    printf("Element found at index %d\n", result);
  }

  return 0;
}
