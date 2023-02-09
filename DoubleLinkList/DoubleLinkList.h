

#include <stdio.h>
#include <stdlib.h>

//#define _CRT_SECURE_NO_WARNINGS

/**
 * @brief this function creates the node
 *
 *
 */

void clrscr(void);
void printList();
void addAtBeg();
void addAfter(int after);
void addBefore(int before);
void addAtEnd();
void deleteAtBeg();
void deleteAtMiddle(int position); 
void deleteAtEnd();

struct node {
  struct node *prev;
  int data;
  struct node *next;
};

/**
 * @brief declaring head pointer
 *
 */
struct node *head = NULL;

void clrscr(void) { printf("\033[1J\033[H"); }

void addAtBeg() 
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  printf("Enter new node: ");
  scanf("%d", &newNode->data);

  if (head == NULL) 
  {
    printf("List is empty, enter new list");
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return;
  } 
  else 
  {
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    newNode->prev = NULL;
    head = newNode;
    return;
  }
  printf("Data is entered");
}

void addAfter(int after) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  struct node *location = head;

  printf("Enter new node: ");
  scanf("%d", &newNode->data);

  if (head == NULL) 
  {
    printf("List is empty, create new");
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return;
  }
  while (location != NULL) 
  {
    if (location->data == after) 
    {
      location->next->prev = newNode;
      newNode->next = location->next;
      location->next = newNode;
      newNode->prev = location;
      return;

    } 
    else 
    {
      location = location->next;
    }
  }
  printf("Data is entered");
}

void addBefore(int before) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  struct node *location = head;

  printf("Enter new node: ");
  scanf("%d", &newNode->data);

  if (head == NULL) 
  {
    printf("List is empty, create new");
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return;
  }

  while (location != NULL) 
  {
    if (location->data == before) 
    {
      location->prev->next = newNode;
      newNode->prev = location->prev;
      location->prev = newNode;
      newNode->next = location;
    } 
    else 
    {
      location = location->next;
    }
  }
  printf("Data is entered before item");
}

void addAtEnd() 
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  struct node *location = head;

  printf("Enter new node: ");
  scanf("%d", &newNode->data);

  if (head == NULL) 
  {
    printf("List is empty, create new");
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return;
  } 
  else 
  {
    while (location->next != NULL)
    {
      location = location->next;
    }

    location->next = newNode;
    newNode->prev = location;
    newNode->next = NULL;
  }

  printf("Node added at the end");
}

void deleteAtBeg() 
{
  struct node *newNode = NULL;
  struct node *location = NULL;

  if (head == NULL) 
  {
    printf("List is Empty, create new");
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return;
  } 
  else 
  {
    location = head;
    head = head->next;
    head->prev = NULL;
    printf("Data is deleted");
    free(location);
  }
}

void deleteAtMiddle(int position) 
{
  struct node *newNode = NULL;
  struct node *location = head;

  if (head == NULL) 
  {
    printf("List not found, Create new");
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return;
  }

  while (location != NULL) 
  {
    if (location->data == position) 
    {
      newNode = location;
      location->prev->next = location->next;
      location->next->prev = location->prev;
      printf("Data is deleted");
      free(newNode);
      return;
    } 
    else 
    {
      location = location->next;
    }
  }
}

void deleteAtEnd() 
{
  struct node *newNode = NULL;
  struct node *location = head;

  if (head == NULL) 
  {
    printf("List not found, Create new");
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return;
  }
  while (location->next != NULL) 
  {
    location = location->next;
  }
  newNode = location;
  location->prev->next = NULL;
  printf("Item is deleted");
  free(newNode);
}

void printList() 
{
  struct node *newNode;
  if (head == NULL) 
  {
    printf("List is empty");
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return;
  }

  struct node *temp = head;
  printf("\nPrinting The List\n");
  do 
  {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != NULL);
  printf("\n");
}
