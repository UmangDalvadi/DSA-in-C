#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void push(struct stack *n, char x)
{
    // if (isfull(n))
    // {
    //     printf("Stack Overflow! Cannot push %c to the stack\n", x);
    // }
    n->top++;
    n->arr[n->top] = x;
}
int pop(struct stack *n)
{
    // if (isempty(n))
    // {
    //     printf("Stack Underflow! Cannot pop from the stack\n");
    //     return -1;
    // }
    char x = n->arr[n->top];
    n->top--;
    return x;
}
int isop(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == ')' || x == '(')
    {
        return 1;
    }
    return 0;
}
int pre(char x)
{
    if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    return 0;
}
int stacktop(struct stack *n)
{
    return n->arr[n->top];
}
int isempty(struct stack *n)
{
    if (n->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
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
char *infixtopostfix(char *exp)
{
    printf("\nEnter INFIX Expression : ");
    gets(exp);
    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    n->size = strlen(exp);
    n->top = -1;
    n->arr = (char *)malloc(n->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(exp) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (exp[i] != '\0')
    {
        if (!isop(exp[i]))
        {
            postfix[j] = exp[i];
            i++;
            j++;
        }
        else
        {
            if (exp[i] == '(')
            {
                push(n, exp[i]);
                i++;
            }

            else if (pre(exp[i]) > pre(stacktop(n)))
            {
                push(n, exp[i]);
                i++;
            }

            else
            {
                if (exp[i] == ')')
                {
                    while (n->arr[n->top] != '(')
                    {
                        postfix[j] = pop(n);
                        j++;
                    }
                    pop(n);
                }

                postfix[j] = pop(n);
                j++;
            }
        }
    }
    while (!isempty(n))
    {
        postfix[j] = pop(n);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *exp;
    printf("\npostfix : %s\n", infixtopostfix(exp));
    printf("\n");
    return 0;
}