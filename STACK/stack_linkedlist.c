#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isempty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
int isfull(struct node *top)
{
    struct node *n = (struct node *)malloc(sizeof(struct node *));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}
struct node *push(struct node *top, int x)
{
    if (isfull(top))
    {
        printf("\nstack overflow\n");
    }
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->next = top;
    top = n;
    return top;
}

int pull(struct node *top)
{
    if (isempty(top))
    {
        printf("\nstack underflow\n");
        // return 0;
    }
    struct node *n = (struct node *)malloc(sizeof(struct node *));
    n = top;
    top = top->next;

    return n->data;
}
void travel(struct node *ptr)
{

    //  struct node *ptr = f;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *top = NULL;

    top = push(top, 20);
    top = push(top, 26);
    top = push(top, 82);
    top = push(top, 65);
    top = push(top, 88);
    top = push(top, 14);
    top = push(top, 56);

    travel(top);

    int n = pull(top);

    printf("pulled:%d", n);
    // free(n);

    // printf("pulled : ", pull(top));
    // printf("pulled : ", pull(top));

    travel(top);

    return 0;
}