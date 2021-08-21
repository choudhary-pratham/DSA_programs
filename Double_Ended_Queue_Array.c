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

void enqueueR(struct queue *q, int val)
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

void enqueueF(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow!! cannot insert value : %d\n", val);
    }
    else
    {
        if (q->f != -1)
        {
            q->arr[q->f] = val;
            q->f--;
        }
        else
        {
            printf("No space to insert at the beginning of queue");
        }
    }
}

int dequeueF(struct queue *q)
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

int dequeueR(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow!! Unable to remove element\n");
    }
    else
    {
        int val = q->arr[q->r];
        q->r = q->r - 1;
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

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueueR(q, 20);
    enqueueR(q, 30);
    enqueueR(q, 40);
    enqueueR(q, 50);

    printf("Queue after enqueueR operations ->\n");
    traverse_Queue(q);

    printf("Value removed out of the queue : %d\n", dequeueF(q));
    printf("Value removed out of the queue : %d\n", dequeueF(q));

    printf("Queue after dequeueF operations ->\n");
    traverse_Queue(q);

    enqueueF(q, 20);
    enqueueF(q, 30);

    printf("Queue after enqueueF operations ->\n");
    traverse_Queue(q);

    printf("Value removed out of the queue : %d\n", dequeueR(q));
    printf("Value removed out of the queue : %d\n", dequeueR(q));

    printf("Queue after dequeueR operations ->\n");
    traverse_Queue(q);

    return 0;
}