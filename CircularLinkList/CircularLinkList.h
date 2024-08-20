#pragma once


#include <stdio.h>
#include <stdlib.h>

/**
 * @brief this function creates the node
 * 
 * 
 */
struct node
{
    int data;
    struct node *next;
};

/*****************************************************************
 * @brief this declaration initialize the head pointer to NULL    *
 * 
 */
struct node *head = NULL;

void clrscr(void) { printf("\033[1J\033[H"); }

struct node *createNode()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Node is not created");
    }

    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    return newNode;
}



void addToBeginning()
{
    struct node *newNode = createNode();

    if (head == NULL)
    {
        printf("List is empty, add new list!");
        head = newNode;  // head now take in the address of the newnode
        newNode->next = head;   // the next variable of the new node now take in the
        return;                 // addres of the new node
    }                           
    else
    {
        struct node *tail = head;

        while (tail->next != head)
        {
            tail = tail->next;
        }
        newNode->next = head;   // the next variale of the current newnode now takes in the the address
                                // of the former new node
        head = newNode;         // the head pointer now points to the new node now
        tail->next = head;      // now the tail now point to the head pointer
        printf("Successfull Insertion");
    }
}

// Add node to the middle of the list
void addAfter(int after)
{
    struct node *newNode = createNode();
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty, add new list!");
        head = newNode;
        newNode->next = head;
        return;
    }

    while (temp != NULL)
    {
        if (temp->data == after)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }


}


// Add node to the end of the list
void addBefore(int before)
{
    struct node *newNode = createNode();
    struct node *temp = head;
    struct node *previous = head;

    if (head == NULL)
    {
        printf("List is empty, add new list!");
        head = newNode;
        newNode->next = head;
        return;
    }
    while (temp != NULL)
    {
        if (temp->data == before)
        {
            newNode->next = temp;
            previous->next = newNode;
            return;
        }
        else
        {
            previous = temp;
            temp = temp->next;
        }
    }
}

void addAtEnd()
{
    struct node *newNode = createNode();
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty, add new list!");
        head = newNode;
        newNode->next = head;
        return;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    printf("Data is added at the END");
}


void deleteAtBeg()
{

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = head->next;
    free(head);
    head = temp->next;
}

void deleteAtMiddle(int position)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        struct node *previous = head;
        struct node *toDelete = previous->next;

        while (toDelete != NULL)
        {
            if (toDelete->data == position)
            {
                previous->next = toDelete->next;
                free(toDelete);
                return;
            }
            else
            {
                previous = toDelete;
                toDelete = toDelete->next;
            }
        }
        printf("Item not Found");
    }

} 


void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    struct node *previous = head;
    struct node *temp = previous->next;
    while (temp->next != head)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = head;
    free(temp);
    
}

void printList()
{
    
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
