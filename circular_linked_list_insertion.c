#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void circular_linked_list_traversal(struct Node *head)
{
    struct Node *ptr = head;

    // while(ptr->next != head)
    // {
    //     printf("Element : %d\n",ptr->data);
    //     ptr = ptr ->next;
    // }
    // printf("Element : %d\n",ptr->data);

    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *circular_linked_list_insertion(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    while (p->next != head)
    {
        p=p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    head = ptr;
    return head;
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

    second->data = 11;
    second->next = third;

    third->data = 22;
    third->next = fourth;

    fourth->data = 68;
    fourth->next = head;

    printf("Before insertion:\n");
    circular_linked_list_traversal(head);

    head = circular_linked_list_insertion(head, 77);
    printf("After insertion:\n");
    circular_linked_list_traversal(head);

    return 0;
}