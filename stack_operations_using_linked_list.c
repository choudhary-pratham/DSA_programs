#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL; //--------> If we declare it globally then we dont have to pass the address of top in pop function as the changes
// made in the top changes it globally.
void linked_list_traversal(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL) // if the first element is NULL then it return true
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) // if the heap section of the RAM is unable to allocate memory then the linked list is full and it returns true
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int data)
{
    if (isFull(top))
    {
        printf("Stack overflow\n");
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

// int pop(struct Node **top)// if we are declaring top locally
// {
//     if(isEmpty(*top))
//     {
//         printf("Stack underflow\n");
//     }
//     else
//     {
//         struct Node *ptr = (*top);
//         (*top)=(*top)->next;
//         int value = ptr->data;
//         free(ptr);
//         return value;
//     }
// }
int pop(struct Node *tp) //--------> for global declaration of top.
{
    if (isEmpty(tp))
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct Node *ptr = (tp);
        (top) = (tp)->next;
        int value = ptr->data;
        free(ptr);
        return value;
    }
}

int peek(struct Node *top, int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stacktop(struct Node *top)
{
    return top->data;
}

int stackbottom(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    //struct Node *top = NULL; // here top refers to head that we used in linked list

    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    printf("Elements after push operation in our linked list :\n");
    linked_list_traversal(top);
    //printf("Element popped out of the linked list: %d\n",pop(&top)); // in case of pop we are passing the address of the structure pointer
    //because the value returned by pop function will be the element to be deleted hence we wouldn't be able to
    // update the structure pointer.(for local dec)
    //printf("Element popped out of the linked list: %d\n",pop(top)); // for global dec
    // printf("After popping the element:");
    //linked_list_traversal(top);

    printf("Element at the top of the linked list using stack: %d\n", stacktop(top));
    printf("Element at the bottom of the linked list using stack: %d\n", stackbottom(top));
    for (int i = 1; i <= 4; i++)
    {
        printf("Index of the elements at position %d :%d\n", i, peek(top, i));
    }
    return 0;
}
