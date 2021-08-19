#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int push(struct stack *sp, char c)
{
    if (isFull(sp))
    {
        return 1;
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = c;
    }
}

int pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}

int stacktop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '+' || c == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *infix_to_postfix(char *infix_exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(infix_exp) + 1;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix_exp = (char *)malloc(sp->size * sizeof(char));
    int i = 0; // variable to traverse through my infix expression
    int j = 0; // variable to traverse through my postfix expression
    while (infix_exp[i] != '\0')
    {
        if (!isoperator(infix_exp[i]))
        {
            postfix_exp[j] = infix_exp[i];
            i++;
            j++;
        }
        else
        {
            if (!(precedence(infix_exp[i]) > precedence(stacktop(sp))))
            {
                postfix_exp[j] = pop(sp);
                j++;
            }
            else
            {
                push(sp, infix_exp[i]);
                i++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix_exp[j] = pop(sp);
        j++;
    }
    postfix_exp[j] = '\0';
    return postfix_exp;
}

int main()
{
    char *infix_exp = "x+y*z";
    printf("The postfix expression of the corresponding infix expression is %s\n", infix_to_postfix(infix_exp));
    return 0;
}