#include "PriorityQueueArray.h"

int pq[MAX_SIZE]; // priority queue array
int pq_size = 0;  // current size of the priority queue

void clrscr(void) { printf("\033[1J\033[H"); } // use clearing the screen

// function to swap two elements in the priority queue
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// function to insert an element into the priority queue
void insert(int element) 
{
  if (pq_size == MAX_SIZE) 
  {
    printf("Priority queue is full.\n");
    return;
  }
  pq[pq_size] = element;
  int current = pq_size;
  int parent = (current - 1) / 2; // calculating the index of the current queue
  while (current > 0 && pq[current] > pq[parent]) // if the current index is creater than zero and the element in that index is creater than the element in the parent index
  {
    swap(&pq[current], &pq[parent]);
    current = parent;
    parent = (current - 1) / 2;
  }
  pq_size++;
}

// function to remove the maximum element from the priority queue
int remove_max() 
{
  if (pq_size == 0) 
  {
    printf("Priority queue is empty.\n");
    return -1;
  }
  int max = pq[0];
  pq[0] = pq[pq_size - 1];
  pq_size--;
  int current = 0;
  int left = 2 * current + 1;
  int right = 2 * current + 2;
  while ((left < pq_size && pq[current] < pq[left]) ||
         (right < pq_size && pq[current] < pq[right])) 
  {
    if (right >= pq_size || pq[left] > pq[right]) 
    {
      swap(&pq[current], &pq[left]);
      current = left;
    } 
    else 
    {
      swap(&pq[current], &pq[right]);
      current = right;
    }
    left = 2 * current + 1;
    right = 2 * current + 2;
  }
  return max;
}

// function to print the priority queue
void print() 
{
  if (pq_size == 0) 
  {
    printf("Priority queue is empty.\n");
    return;
  }
  for (int i = 0; i < pq_size; i++) 
  {
    printf("%d ", pq[i]);
  }
  printf("\n");
}

// main function to test the priority queue implementation
// int main() {
//   insert(5);
//   insert(3);
//   insert(7);
//   insert(2);
//   insert(8);
//   print();                                   // should print: 8 5 7 2 3
//   printf("Max element: %d\n", remove_max()); // should print: Max element: 8
//   printf("Max element: %d\n", remove_max()); // should print: Max element: 7
//   print();                                   // should print: 5 3 2
//   insert(6);
//   insert(4);
//   print(); // should print: 6 5 4 3 2
//   return 0;
// }
