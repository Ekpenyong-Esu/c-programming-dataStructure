#ifndef BFEDC140_94CB_4577_929A_C6B24BF5507C
#define BFEDC140_94CB_4577_929A_C6B24BF5507C

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  int priority;
  struct node *next;
};

void enqueue(int data, int priority);
int dequeue();
void print_priority_queue();
void clrscr(void);
#endif /* BFEDC140_94CB_4577_929A_C6B24BF5507C */
