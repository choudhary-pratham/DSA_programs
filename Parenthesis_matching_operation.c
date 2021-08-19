#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *sp, char c)
{
    if (isFull(sp))
    {
        printf("Stack overflow!!");
    }
    else
    {
        sp->top += 1;
        sp->arr[sp->top] = c;
    }
}

void pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack underflow");
    }
    else
    {
        sp->top -= 1;
    }
}

int parenthesis_match(char *exp)
{
    struct stack *sp;
    // Initialised my stack where i need to put my '(' bracket
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * (sizeof(char)));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                pop(sp);
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *exp = ")("; // Parenthesis matching only checks the parenthesis. It will
                       // return True even if the expression doesnot validate.
                       // eg - ((8)(*9))---> This equation has balanced parenthesis 
                       // but the Expression is invalid.
    if (parenthesis_match(exp))
    {
        printf("Parenthesis is matching.\n");
    }
    else
    {
        printf("Parenthesis is not matching.\n");
    }
    return 0;
}
