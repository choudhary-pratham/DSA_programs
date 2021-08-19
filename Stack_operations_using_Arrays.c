#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s) // Time complexity = O(1)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *s) // Time complexity = O(1)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *s, int val) // Time complexity = O(1)
{
    if (isFull(s))
    {
        printf("Stack Overflow!! Couldn't push value : %d\n", val);
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
        printf("Value : %d pushed successfully\n", val);
    }
}

int pop(struct stack *s) // Time complexity = O(1)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!!\n");
    }
    else
    {
        int val = s->arr[s->top];
        s->top = s->top--;
        return val;
    }
}

int peek(struct stack *s, int index) // Time complexity = O(1)

{
    if (s->top - index + 1 < 0)
    {
        printf("index value less than 0\n");
    }
    else
    {
        return s->arr[s->top - index + 1];
    }
}

int stacktop(struct stack *s) // Time complexity = O(1)
{
    return s->arr[s->top];
}

int stackbottom(struct stack *s) // Time complexity = O(1)
{
    return s->arr[0];
}

int main()
{
    int num;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1; // If our stack is empty we initialise the top variable(which points to the top of the stack) as -1
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Checking isEmpty function before pushing values in the stack\n");
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }

    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);

    printf("popped value:%d\n", pop(s)); // last in first out
    printf("popped value:%d\n", pop(s));
    printf("popped value:%d\n", pop(s));
    printf("popped value:%d\n", pop(s));
    printf("popped value:%d\n", pop(s));
    printf("popped value:%d\n", pop(s));

    printf("\nChecking isFull function after entering values in the stack\n");
    if (isFull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }
    s->top = -1;
    push(s, 44);
    push(s, 55);
    push(s, 64);
    push(s, 72);
    push(s, 88);
    push(s, 99);
    push(s, 104);
    for (int i = 0; i < s->top + 1; i++)
    {
        printf("value at index %d is %d\n", i + 1, peek(s, i + 1));
    }
    printf("Top value of the stack is %d\n", stacktop(s));
    printf("Bottom value of the stack is %d\n", stackbottom(s));
    return 0;
}
