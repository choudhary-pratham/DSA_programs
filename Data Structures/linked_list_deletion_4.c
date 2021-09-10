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
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleting_the_given_node(struct Node *head, struct Node *n)
{
    struct Node *ptr = head;
    while (ptr->next != n)
    {
        ptr = ptr->next;
    }
    ptr->next = n->next;
    free(n);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = NULL;

    printf("Before deletion\n");
    linked_list_traversal(head);

    head = deleting_the_given_node(head, second);

    printf("After deletion\n");
    linked_list_traversal(head);
    return 0;
}