#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s)
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

int isFull(struct stack *s)
{
    if (s->top == s->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack * s,int val){
    if(isFull(s))
    {
        printf("Stack Overflow!! Couldn't push value : %d\n",val);
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
        printf("Value : %d pushed successfully\n",val);
    }
}

int pop(struct stack * s){
    if(isEmpty(s))
    {
        printf("Stack underflow!!\n");
    }
    else
    {
        int val = s->arr[s->top--];
        s->top = s->top--;
        return val;
    }
}

int main()
{
    int num;
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size =6;
    s->top = -1; // If our stack is empty we initialise the top variable(which points to the top of the stack) as -1
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    printf("Checking isEmpty function before pushing values in the stack\n");
    if(isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }

    push(s,4);
    push(s,5);
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    push(s,10);

    printf("popped value:%d\n",pop(s));// last in first out
    printf("popped value:%d\n",pop(s));
    printf("popped value:%d\n",pop(s));
    printf("popped value:%d\n",pop(s));
    printf("popped value:%d\n",pop(s));
    printf("popped value:%d\n",pop(s));

    printf("\nChecking isFull function after entering values in the stack\n");
    if(isFull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }
    return 0;
}
// Output:
// Checking isEmpty function before pushing values in the stack
// The stack is empty
// Value : 4 pushed successfully
// Value : 5 pushed successfully
// Value : 6 pushed successfully
// Value : 7 pushed successfully
// Value : 8 pushed successfully
// Value : 9 pushed successfully
// Stack Overflow!! Couldn't push value : 10
// popped value:9
// popped value:8
// popped value:7
// popped value:6
// popped value:5
// popped value:4