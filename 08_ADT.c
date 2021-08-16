#include <stdio.h>
#include <stdlib.h>
struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void setvalue(struct myarray *a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc((a->used_size) * sizeof(int));
    int i, n = a->used_size;
    for (i = 0; i < n; i++)
    {
        printf("Enter value number %d ", i + 1);
        scanf("%d", &(a->ptr)[i]);
    }
}

void getvalue(struct myarray *a)
{
    int i, n = a->used_size;
    printf("marks entered are as follows :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

int main()
{
    struct myarray marks;
    int tsize, usize;
    printf("Enter total size of the array = ");
    scanf("%d", &tsize);
    printf("Enter used size of the array = ");
    scanf("%d", &usize);
    setvalue(&marks, tsize, usize);
    getvalue(&marks);
    return 0;
}