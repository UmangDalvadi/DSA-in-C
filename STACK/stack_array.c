#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("Stack overflow!!!\n\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("Stack Underflow!!!\n\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("invalid\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("\nstack is created\n\n");
    printf("is full : %d\n", isfull(sp));
    printf("is empty : %d\n\n", isempty(sp));
    push(sp, 22);
    push(sp, 26);
    push(sp, 56);
    push(sp, 36);
    push(sp, 55);
    push(sp, 36); // extra
    printf("is full : %d\n", isfull(sp));
    printf("is empty : %d\n\n", isempty(sp));
    printf("popping value : %d\n\n", pop(sp));
    for (int i = 1; i <= sp->top + 1; i++)
    {
        printf("value at position %d is %d\n", i, peek(sp, i));
    }

    return 0;
}