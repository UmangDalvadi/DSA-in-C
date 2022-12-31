#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void travel(struct node *ptr)
{

    //  struct node *ptr = f;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insert(struct node *ptr, struct node *q, int n)
{
    // struct node *q;

    if (n == 1)
    {
        // struct node *ptr1 = (struct node *)malloc(sizeof(struct node *));
        q->next = ptr->next;
        ptr->next = q;
        // ptr1 = ptr->next;
        // ptr->next = q;
        // q->next = ptr1;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            ptr = ptr->next;
        }
        q->next = ptr->next;
        ptr->next = q;

        // for (int i = 0; i < n; i++)
        // {

        //     if (i == n - 1)
        //     {
        //         ptr->next = q;
        //     }

        //     ptr = ptr->next;
        //     // ptr=6
        //     q->next = ptr->next; // q=7
        // }
    }
}
struct node* dlt(struct node *ptr, int val)
{
    if (val == 0)
    {
        struct node *temp = ptr;
        ptr->next = ptr;
        free(temp);
    }
    return ptr;
}

struct node *cn(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
}

int main()
{
    struct node *f1 = cn(5);
    struct node *f2 = cn(6);
    struct node *f3 = cn(7);
    struct node *f4 = cn(8);
    struct node *f5 = cn(9);

    f1->next = f2;
    f2->next = f3;
    f3->next = f4;
    f4->next = f5;

    travel(f1);

    f1=dlt(f1, 0);

    // char ch;
    // do
    // {
    // struct node *q;
    // q = (struct node *)malloc(sizeof(struct node));
    // int n, ele;
    // /* code */

    // printf("enter index(between [0,5] ) to add : \n");
    // scanf("%d", &n);
    // printf("enter element wich you want to add : \n");
    // scanf("%d", &ele);
    // q->data = ele;

    // if (n != 0)
    // {
    //     insert(f1, q, n);
    // }

    // else
    // {
    //     q->next = f1;
    //     f1 = q;
    // }

    printf("\n");

    travel(f1);
    // printf("want to add again : \n");
    // scanf("%c", &ch);
    // } while (ch == 'y');

    return 0;
}