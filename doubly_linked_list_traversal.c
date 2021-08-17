#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void doubly_linked_list_traversal(struct Node *ptr)
{
    while (ptr->next!= NULL)
    {
        printf("Element from left to right : %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("Element from left to right : %d\n", ptr->data);
    printf("\n");

    while (ptr->prev != NULL)
    {
        printf("Element from right to left : %d\n", ptr->data);
        ptr = ptr->prev;
    }
    printf("Element from left to right : %d\n", ptr->data);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node *));
    second = (struct Node *)malloc(sizeof(struct Node *));
    third = (struct Node *)malloc(sizeof(struct Node *));
    fourth = (struct Node *)malloc(sizeof(struct Node *));

    head->data = 7;
    head->next = second;
    head->prev = NULL;

    second->data = 11;
    second->next = third;
    second->prev = head;

    third->data = 22;
    third->next = fourth;
    third->prev = second;

    fourth->data = 68;
    fourth->next = NULL;
    fourth->prev = third;

    doubly_linked_list_traversal(head);
    return 0;
}