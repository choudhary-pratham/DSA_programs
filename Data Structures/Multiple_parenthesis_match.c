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

char pop(struct stack *sp)
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

int match_character(char open, char close)
{
    if (open == '(' && close == ')')
    {
        return 1;
    }

    if (open == '{' && close == '}')
    {
        return 1;
    }

    if (open == '[' && close == ']')
    {
        return 1;
    }

    return 0;
}

int multiple_parenthesis_match(char *exp)
{
    char popped_char;
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                popped_char = pop(sp);
                if (!match_character(popped_char, exp[i]))
                {
                    return 0;
                }
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
    char *exp = "[}";

    if (multiple_parenthesis_match(exp))
    {
        printf("The equation has balanced paranthesis");
    }

    else
    {
        printf("The equation doesnot have balanced paranthesis");
    }
    return 0;
}
