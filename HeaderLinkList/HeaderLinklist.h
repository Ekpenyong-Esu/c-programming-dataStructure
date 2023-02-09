#pragma once


#include <stdio.h>
#include <stdlib.h>

// Structure of the list
struct node {
  int data;
  struct node *next;
};

void clrscr(void) { printf("\033[1J\033[H"); }



// Empty List
struct node *head = NULL;

// Function to create a header nodeed list
struct node *create_header_list() 
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
 
  newNode->next = NULL;

  // If it is the first node
  if (head == NULL) 
  {

    // Initialize the head
    head = (struct node *)malloc(sizeof(struct node));
    head->next = newNode;
  } 
  else 
  {

    // Insert the node in the end
    location = head;                        // the struct node pointer now points to the head pointer      
    while (location->next != NULL) 
    {
      location = location->next;
    }
    location->next = newNode;
  }
  return head;
}

// Function to display the
// header nodeed list
void display() 
{
  struct node *node;
  node = head;
  node = node->next;  // skip the header node first

  if (head == NULL)
  {
    printf("List is empty");
    return;
  }

  while (node != NULL) 
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
  
}