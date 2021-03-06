#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linked_list_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *inserting_at_the_beginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node *inserting_at_an_index(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    int i = 0;
    while (i != (index - 1))
    {
        i++;
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *inserting_at_the_end(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct Node *inserting_after_node(struct Node *head, struct Node *n, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = n->next;
    n->next = ptr;
    
    return head;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = first;

    first->data = 12;
    first->next = second;

    second->data = 16;
    second->next = third;

    third->data = 20;
    third->next = NULL;

    printf("Before insertion:\n");
    linked_list_traversal(head);

    head = inserting_at_the_beginning(head, 2);

    printf("\nAfter insertion\n");
    linked_list_traversal(head);
    return 0;
}