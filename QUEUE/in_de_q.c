#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Q
{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct Q *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}
int isfull(struct Q *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void inQ(struct Q *q, int val)
{
    if (isfull(q))
    {
        printf("Q Overflow\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("inQ : %d\n",val);
    }
}
int deQ(struct Q *q)
{
    int val = -1;
    if (isempty(q))
    {
        printf("Q Underflow\n");
        return -1;
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        val = q->arr[q->f];
        return val;
    }
}

int main()
{
    struct Q *q;
    q->size = 6;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    inQ(q, 5);
    inQ(q, 6);
    inQ(q, 7);
    inQ(q, 8);
    inQ(q, 9);
    // inQ(q, 10);
    
    printf("deQ : %d\n", deQ(q));
    printf("deQ : %d\n", deQ(q));
    inQ(q,10);
    inQ(q,11);
    // inQ(q,12);
    printf("deQ : %d\n", deQ(q));
    printf("deQ : %d\n", deQ(q));
    printf("deQ : %d\n", deQ(q));
    printf("deQ : %d\n", deQ(q));
    printf("deQ : %d\n", deQ(q));
    // printf("deQ : %d\n", deQ(q));
    // printf("deQ : %d\n", deQ(q));
    // printf("deQ : %d\n", deQ(q));

    return 0;
}