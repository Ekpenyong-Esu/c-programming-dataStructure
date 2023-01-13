#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *name;
    struct node *next;
};

struct node *head = NULL;

void add_name(char *name)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->name = strdup(name);
    new_node->next = head;
    head = new_node;
}

void print_list()
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%s\n", current->name);
        current = current->next;
    }
}

void delete_name(char *name)
{
    struct node *current = head;
    struct node *previous = NULL;

    if (current != NULL && strcmp(current->name, name) == 0)
    {
        head = current->next;
        free(current->name);
        free(current);
        return;
    }

    while (current != NULL && strcmp(current->name, name) != 0)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    previous->next = current->next;
    free(current->name);
    free(current);
}

int main()
{
    add_name("Alice");
    add_name("Bob");
    add_name("Charlie");
    print_list();
    delete_name("Bob");
    print_list();
    return 0;
}
