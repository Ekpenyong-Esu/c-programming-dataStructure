#pragma once

// header file

#include <stdio.h>
#include <stdlib.h>

void clrscr(void) { printf("\033[1J\033[H"); }

//declare the node 
struct node
{
    int data;
    struct node *next;
};

// set a pointer that will point to 
//the first node and it is called head pointer
struct node *head = NULL;

void add_node_at_begining()
{
    // create the new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("%s", "Fail to create The node");
    }

    printf("%s", "Enter the value node: ");
    scanf("%d", &new_node->data);

    // The next of the new node now point and read the value in the head pointer
    // into the next section of the struct.
    new_node->next = head;

    // The head pointer now point to the address of the new node

    head = new_node;

    printf("%s", "node sucessfully added");
}

void add_node_after(int after)
{
    struct node *current_node = head;
    while (current_node != NULL && current_node->data != after)
    {
        current_node = current_node->next;
    }

    if (current_node != NULL)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));

        if (new_node == NULL)
        {
            printf("%s", "Fail to create The node");
        }

        printf("%s", "Enter the value of the node: ");
        scanf("%d", &new_node->data);

        // Since we want to add the new node after the current node, we read the next  content of the
        //  current node which is the adress of the next node into the next variable of the current node
        new_node->next = current_node->next;

        // We then assign the address of the new node to the next variable of the current node. Hence, the current node now points to the new node
        current_node->next = new_node;
    }
    else
    {
        printf("%s", "List is Empty, create a new list: ");
        return;
    }
}

void add_node_before(int before)
{

    // I first check if the head pointer data section is equal to before
    if (head->data == before)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));

        if (new_node == NULL)
        {
            printf("%s", "Fail to create The node");
        }

        printf("%s", "Enter the value of the node: ");
        scanf("%d", &new_node->data);

        new_node->next = head; // takes in the value of what head is pointing which is an address of the next node
        head = new_node;
        return;
    }

    // Else  If the data of the head pointer does not have a value that is equall to int before
    struct node *current_node = head;

    while (current_node->next != NULL && current_node->next->data != before)
    {
        current_node = current_node->next;
    }

    if (current_node->next != NULL)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));

        if (new_node == NULL)
        {
            printf("%s", "Fail to create The node");
        }

        printf("%s", "Enter the value of the node: ");
        scanf("%d", &new_node->data);

        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

void add_node_at_end()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Node can not be greated");
        return;
    }

    printf("Enter New node: ");
    scanf("%d", &new_node->data);

    struct node *previous = head;
    if (head == NULL)
    {
        printf("List is empty, create new node");
        new_node->next = head;
        head = new_node;
    }

    while (previous->next != NULL)
    {
        previous = previous->next;
    }

    new_node->next = NULL;
    previous->next = new_node;

    printf("Data is added is added to the end of the node");
}

void delete_node(int data)
{
    struct node *current = head;  // create a current node which take the address of the head pointer
    struct node *previous = NULL; // create another node pointer call previous that curent will be assigning its
                                  // value before taking another address through next of the crrent node

    if (current != NULL && current->data == data) // if the first node is not null and and the value is equll to the value we want to delete
    {
        head = current->next; // Then let head pointer points to the nextnode by assigning the address of of the curren next to it
        free(current);        // the free current
        printf("Deleted at the begining of the node");
        return;
    }

    while (current != NULL && current->data != data) // but if current is not equall to null and current is not equall to value we want to delete
    {                                                // assign current address to previous
        previous = current;                          // the point current to the next node by taking the address of the current next
        current = current->next;
    }

    if (current == NULL)
    {
        printf("%s", "*******Node not found******");
        return;
    } // if current is equall to null that means that the value is not seen

    previous->next = current->next; // if the value is seen assign the next content of the current node which hold the address
    printf("Node deleted in the middle or end");
    free(current); // of the next node and free the current node
}
void printList()
{
    
    if (head == NULL)
    {
        printf("The link list is Empty, create a node\n");
        struct node *current = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value of the node: ");
        scanf("%d", &current->data);
        current->next = head;
        head = current;
    }
    else
    {
        struct node *current = head;
        printf("\nPrinting Link List\n");
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }

}
