#include <stdio.h>
#include <stdlib.h>

struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularqueue *q)
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

int isFull(struct circularqueue *q)
{
    if (((q->r + 1) % q->size) == q->f) // circular queue increment is i+1%size
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circularqueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->r = ((q->r + 1) % (q->size));
        q->arr[q->r] = val;
        printf("Element added : %d\n", q->arr[q->r]);
    }
}

int dequeue(struct circularqueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
    }
    else
    {
        int val = -1;
        q->f = q->f + 1;
        val = q->arr[q->f];
        return val;
    }
}

int circularqueuetop(struct circularqueue *q)
{
    return q->arr[q->f + 1];
}

int circularqueuebottom(struct circularqueue *q)
{
    return q->arr[q->r];
}

int main()
{
    struct circularqueue *cq = (struct circularqueue *)malloc(sizeof(struct circularqueue));
    cq->size = 11;
    cq->f = cq->r = 0;
    cq->arr = (int *)malloc(cq->size * sizeof(int));

    enqueue(cq, 10);
    enqueue(cq, 20);
    enqueue(cq, 30);
    enqueue(cq, 40);
    enqueue(cq, 50);
    enqueue(cq, 60);
    enqueue(cq, 70);
    enqueue(cq, 80);
    enqueue(cq, 90);
    enqueue(cq, 100);

    printf("Element removed : %d \n", dequeue(cq));
    printf("Element removed : %d \n", dequeue(cq));
    printf("Element removed : %d \n", dequeue(cq));

    enqueue(cq, 80);
    enqueue(cq, 90);
    enqueue(cq, 100);

    printf("Element at the top : %d \n", circularqueuetop(cq));
    printf("Element at the bottom : %d \n", circularqueuebottom(cq));

    return 0;
}