#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int interpolationSearch(int arr[], int size, int val);

int main() {
  int size, val;

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int *Arr = (int *)calloc(size, sizeof(int));

  printf("Enter the elements of the array: ");

  for (int i = 0; i < size; i++) {
    scanf("%d", (Arr + i));
  }

  printf("Enter the search element: ");
  scanf("%d", &val);

  int r = interpolationSearch(Arr, size, val);

  if (r == -1) {
    printf("Value not found");
  } else {
    printf("%d found at index %d", val, r);
  }

  free(Arr);
}

int interpolationSearch(int arr[], int size, int val) {
  int low = 0, high = size - 1, mid;

  while (low <= high) {
    mid = low + (high - low) * ((val - arr[low]) / (arr[high] - arr[low]));

    if (arr[mid] == val) {
      return mid;
    } else if (arr[mid] < val) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}
