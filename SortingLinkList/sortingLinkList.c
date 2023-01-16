#include <stdio.h>


struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;

void sorting()
{
    int new;
    struct node *current, *temp;

    current = head;

    while (current != NULL)
    {
        temp = current->next;

        while (temp != NULL)
        {
            if (current->value > temp->value)
            {
                new = temp->value;
                temp->value = current->value;
                current->value = new;
            }

            temp = temp->next;
        }

        temp = current->next;
    }
}