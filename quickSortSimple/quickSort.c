void quickSort(int arr[], int low, int high) {
  int stack[high - low + 1];
  int top = -1;

  stack[++top] = low;
  stack[++top] = high;

  while (top >= 0) {
    high = stack[top--];
    low = stack[top--];

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
      if (arr[j] <= pivot) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    if (i + 1 < high) {
      stack[++top] = i + 2;
      stack[++top] = high;
    }
    if (i + 1 > low) {
      stack[++top] = low;
      stack[++top] = i;
    }
  }
}
