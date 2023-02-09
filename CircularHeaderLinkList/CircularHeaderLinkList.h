#pragma once


#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node *next;
};

struct node *head = NULL;

void clrscr(void) { printf("\033[1J\033[H"); }

struct node *CreateCircularHeaderLinkList() 
{

  // Create a new node
  struct node *newNode, *location;
  newNode = (struct node *)malloc(sizeof(struct node));

  if (newNode == NULL) 
  {
    printf("Node not created");
    return 0;
  }

  printf("Enter the data: ");
  scanf("%d", &newNode->data);


  // If it is the first node
  if (head == NULL) 
  {

    // Initialize the head
    head = (struct node *)malloc(sizeof(struct node));
    head->next = newNode;
    newNode->next = newNode;
  } 
  else 
  {

    // Insert the node in the end
    location = head->next; // the struct node pointer now points to the head pointer

    while (location->next != head->next) 
    {
      location = location->next;
    }
    location->next = newNode;
    newNode->next = head->next;

  }
  return head;
}

void display() 
{
  struct node *temp = head->next; // skip the header node first

  if (head == NULL || head->next == NULL) 
  {
    printf("Linked list is empty.\n");
    return;
  }

  printf("Linked list: ");
  do 
  {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != head->next);
  printf("\n");
  printf("\n");
}



void deleteNode(int data) 
{
  if (head == NULL || head->next == NULL) 
  {
    printf("Linked list is empty.\n");
    return;
  }
  struct node *temp = head->next;   // skip the header 
  struct node *prev = head;
  while (temp->next != head && temp->data != data) 
  {
    prev = temp;
    temp = temp->next;
  }
  if (temp->data == data) 
  {
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", data);
  } 
  else 
  {
    printf("Node with data %d not found.\n", data);
  }
}
