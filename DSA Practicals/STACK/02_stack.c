#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

void push(struct stack *n, char strg[])
{
    for (int i = 0; i < strlen(strg); i++)
    {
        n->top++;
        n->arr[n->top] = strg[i];
    }
}

void pop(struct stack *n, char strg[])
{
    printf("\nReversed String : ");
    for (int i = n->top; i != -1; i--)
    {
        printf("%c", n->arr[i]);
    }
}

int main()
{
    printf("\nEnter String : ");
    char strg[50];
    // scanf("%s", strg);
    gets(strg);

    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    n->size = strlen(strg);
    n->top = -1;
    n->arr = (char *)malloc(n->size * sizeof(char));

    push(n, strg);

    printf("\nString Length : %d\n", strlen(strg));

    pop(n, strg);

    printf("\n");

    return 0;
}