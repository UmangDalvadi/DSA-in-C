#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void travel(struct node *ptr)
{

    do     
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;

    } while (1);
   
}

int main()
{

    struct node *n1, *n2, *n3, *n4, *n5;
    n1 = (struct node *)malloc(sizeof(struct node *));
    n2 = (struct node *)malloc(sizeof(struct node *));
    n3 = (struct node *)malloc(sizeof(struct node *));
    n4 = (struct node *)malloc(sizeof(struct node *));
    n5 = (struct node *)malloc(sizeof(struct node *));

    n1->data = 5;
    n1->prev = NULL;
    n1->next = n2;

    n2->data = 6;
    n2->prev = n1;
    n2->next = n3;

    n3->data = 7;
    n3->prev = n2;
    n3->next = n4;

    n4->data = 8;
    n4->prev = n3;
    n4->next = n5;

    n5->data = 9;
    n5->prev = n4;
    n5->next = NULL;

    travel(n1);

    return 0;
}