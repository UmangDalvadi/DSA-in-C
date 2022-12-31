#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
int push(struct stack *ptr, char x)
{
    if (isfull(ptr))
    {
        printf("stack overflow\n");
    }
    ptr->top++;
    ptr->arr[ptr->top] = x;
}

char pull(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack underflow\n");
        return -1;
    }
    char temp = ptr->arr[ptr->top];
    ptr->top--;
    return temp;
}

int pm(char *exp)
{
    struct stack *n;
    n->size = 50;
    n->top = -1;
    n->arr = (char *)malloc(n->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(n, '(');
        }
        else if (exp[i] == ')')
        {
            if (isempty(n))
            {
                return 0;
            }
            else
            {
                pull(n);
            }
        }
    }
    if (isempty(n))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *exp = "()";
    if (pm(exp))
    {
        printf("matched\n");
    }
    else
    {
        printf("Un-matched\n");
    }

    return 0;
}