#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow!! cannot insert value : %d\n", val);
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow!! Unable to remove element\n");
    }
    else
    {
        q->f++;
        int val = q->arr[q->f];
        return val;
    }
}

int traverse_Queue(struct queue *q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("Element : %d\n", q->arr[i]);
    }
}

int first_value(struct queue *q)
{
    return q->arr[q->f + 1];
}

int last_value(struct queue *q)
{
    return q->arr[q->r];
}

int peek(struct queue *q, int pos)
{
    return q->arr[pos];
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));// NOTE: we are using a
                                                                    //structure pointer so we are passing
                                                                    //the pointer directly in to the function
                                                                    //if we are using an object then we
                                                                    //need to pass the address of the object
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("Queue after enqueue operations ->\n");
    traverse_Queue(q);

    printf("First value of queue :%d\n", first_value(q));
    printf("Last value of queue :%d\n", last_value(q));

    printf("Value removed out of the queue : %d\n", dequeue(q));
    printf("Value removed out of the queue : %d\n", dequeue(q));

    printf("Queue after dequeue operations ->\n");
    traverse_Queue(q);

    printf("First value of queue :%d\n", first_value(q));
    printf("Last value of queue :%d\n", last_value(q));

    for (int i = q->f + 1; i <= q->r; i++)
    {
        static int p = 1;
        printf("Value at position %d is %d\n", p, peek(q, i));
        p++;
    }
    return 0;
}