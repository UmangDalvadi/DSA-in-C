// 1. Write a program to create queue and perform operation like insert, delete and display
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct queue *q)
{
    if (q->f == q->r||q->f=-1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct queue *q)
{
    if (q->r  == q->size-1)
    {
        return 1;
    }
    return 0;
}

void inQ(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("\n------------Queue Overflow-------------\n");
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
        // printf("inQ : %d\n", val);
    }
}
int deQ(struct queue *q)
{
    int val = -1;
   
    if (isempty(q))
    {
        printf("Q Underflow\n");
        return -1;
    }
    else
    {
        val = q->arr[q->f];
        q->f = q->f + 1;
        return val;
    }
}

void insert(struct queue *q)
{
    printf("How many elements you want to add : ");
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {

        printf("Enter value %d : ", i);
        int val;
        scanf("%d", &val);
        inQ(q, val);
    }
}

void display(struct queue *q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d \n", q->arr[i]);
    }
}

int main()
{
    printf("\nEnter size of QUEUE : ");
    int x;
    scanf("%d", &x);
    // printf("\n");

    struct queue *q;
    q->size = x;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    int val;
    do
    {
        printf("\n===========================================================\n\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("\nEnter your choice : ");
        scanf("%d", &val);
        printf("\n");

        switch (val)
        {
        case 1:
            insert(q);
            break;
        case 2:
            printf("deQ : %d\n", deQ(q));
            break;
        case 3:
            display(q);
            break;

        default:
            break;
        }

    } while (val != 4);

    // inQ(q, 5);
    // inQ(q, 6);
    // inQ(q, 7);
    // inQ(q, 8);
    // inQ(q, 9);
    // // inQ(q, 10);

    // printf("deQ : %d\n", deQ(q));
    // inQ(q, 10);
    // inQ(q, 11);
    // // inQ(q,12);
    // printf("deQ : %d\n", deQ(q));
    // printf("deQ : %d\n", deQ(q));
    // printf("deQ : %d\n", deQ(q));
    // printf("deQ : %d\n", deQ(q));
    // printf("deQ : %d\n", deQ(q));
    // printf("deQ : %d\n", deQ(q));
    // printf("deQ : %d\n", deQ(q));
    // printf("deQ : %d\n", deQ(q));

    return 0;
}