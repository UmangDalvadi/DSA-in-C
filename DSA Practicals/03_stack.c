#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isfull(struct stack *n)
{
    if (n->top == n->size - 1)
    {
        return 1;
    }
    return 0;
}

int isempty(struct stack *n)
{
    if (n->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *n, char exp)
{
    if (isfull(n))
    {
        printf("-----Stack Overflow-----\n");
    }
    n->top++;
    n->arr[n->top] = exp;
}

char pop(struct stack *n)
{
    if (isempty(n))
    {
        printf("-----Stack Underflow-----\n");
        return 1;
    }
    char x = n->arr[n->top];
    n->top--;
    return x;
}

int ismatch(char exp, char x)
{
    if (exp == '{' && x == '}')
    {
        return 1;
    }
    if (exp == '(' && x == ')')
    {
        return 1;
    }
    if (exp == '[' && x == ']')
    {
        return 1;
    }
    return 0;
}

int checkexp(char *exp)
{
    gets(exp);
    struct stack *n;
    n->size = strlen(exp);
    n->top = -1;
    n->arr = (char *)malloc(n->size * sizeof(char));
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        {
            push(n, exp[i]);
            i++;
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (isempty(n))
            {
                return 0;
            }
            char x = pop(n);
            if (ismatch(x, exp[i]))
            {
                i++;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            i++;
        }
    }
    if (isempty(n))
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
    char *exp;
    printf("\nEnter Expression :");
    // scanf("%s", exp);

    if (checkexp(exp))
    {
        printf("\n----------Expression is Valid----------\n\n");
    }
    else
    {
        printf("\n----------Invalid Expression----------\n\n");
    }

    return 0;
}