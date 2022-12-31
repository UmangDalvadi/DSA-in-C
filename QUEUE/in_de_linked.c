#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node *f = NULL, *r = NULL;

// struct queue{
//     int size;
//     int f;
//     int r;
//     int *arr;
// };
struct node
{
    int data;
    struct node *next;
};

void inqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue overflow\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            /* code */
            f = r = n;
            printf("enqueue : %d\n", val);
        }

        else
        {
            // struct node *n;
            r->next = n;
            r = n;
            printf("enqueue : %d\n", val);
        }
    }
    // printf("enqueue : %d\n", val);
}

int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}

void inqf(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = f;
    temp = f;
}

int main()
{
    inqueue(5);
    inqueue(6);
    inqueue(7);
    inqueue(8);
    inqueue(8);
    inqueue(8);
    inqf(345);
    printf("------------------------------------------\n");
    printf("Dequeue : %d\n", dequeue());
    printf("Dequeue : %d\n", dequeue());
    printf("Dequeue : %d\n", dequeue());
    // dequeue(f);

    return 0;
}