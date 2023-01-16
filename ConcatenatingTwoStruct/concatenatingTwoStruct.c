#include <stdio.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;


void concatenate(struct node *head1, struct node *head2)
{
    struct node *current = head1;

    while (current != NULL)
    {
        current = current->next;
    }

    current = head2;
}



int main()
{

}