#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *s)
{
    if (s->top != s->size - 1)
    {
        printf("stack underflow\n");
        return 1;
    }
}

int isfull(struct stack *s)
{
    if (s->top == s->size - 1)
    {

        return 1;
    }
    return 0;
}

int main()
{
    struct stack *s;
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    int n = 5;
    for (int i = 0; i < 5; i++)
    {
        if (isempty(s) == 1)
        {
            s->top++;
            s->arr[s->top] = n;
            n++;
        }
    }
    // for (int i = 0; i < 5; i++)
    // {
        if (isfull(s) == 1)
        {
            printf("stack overflow\n");
        }
        else
        {
            int val = s->arr[s->top];
            s->top--;
            // return val;
            printf("val : %d\n", val);
        }
    // }

    return 0;
}