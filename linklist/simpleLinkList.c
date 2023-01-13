#include <stdio.h>
#include <stdlib.h>

// creating a node first
struct node 
{
    int value;
    struct node *next;
};

// Creatin a pointer that will always point to the head of the list
struct node *head = NULL;


// Adding to the node
void add_node(int value)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node)); //This dynamically created a new node
    new_node->value = value;                                    // We assign the value to the value part of the new node
    new_node->next = head;                               // Here we assign the content of head which is the address of a null node struct to the
                                                // next section of the new node
    head = new_node;                             //we now assign the address of the new node to the head pointer head and head now points to the new node

}

void print_list()
{
    struct node *current = head;       // create a new current pointer to struct node and take in the address of the head pointer
                                     // Note the head pointer is pointing to the first node
    while (current != NULL)
    {
        printf("%d\n", current->value);  // Print the value portion of the node 
        current = current->next;         // asign the content of the next part of the current node to curren
    }                                      // and noe that the next of the current node has the address of the next node
}

void delete_node(int value)
{
    struct node *current = head;          // create a current node which take the address of the head pointer
    struct node *previous = NULL;          //create another node pointer call previous that curent will be assigning its
                                            //value before taking another address through next of the crrent node

    if (current != NULL && current->value == value)  // if the first node is not null and and the value is equll to the value we want to delete
    {                                               
        head = current->next;                        //Then let head pointer points to the nextnode by assigning the address of of the curren next to it
        free(current);                              // the free current
        return;
    }

    while (current != NULL && current->value != value) // but if current is not equall to null and current is not equall to value we want to delete
    {                                                   // assign current address to previous 
        previous = current;                             //the point current to the next node by taking the address of the current next 
        current = current->next;
    }

    if (current == NULL)                            // if current is equall to null that means that the value is not seen
        return;

    previous->next = current->next;                 // if the value is seen assign the next content of the current node which hold the address 
    free(current);                                  // of the next node and free the current node
}

void printList()
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
}

int main()
{
    add_node(5);
    add_node(6);

    for (int i = 7; i <= 15; i++)
    {
        add_node(i);
    }

    print_list();
   
}