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
        printf("inQ : %d\n", val);
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
    q->size = 40;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    int node;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    printf("%d ", i);
    visited[i] = 1;
    inQ(q, i);
    while (!isempty(q))
    {
        int node=deQ(q);
        for (int j = 0; j < 7; j++)
        {
            if (graph[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                inQ(q, j);
            }
        }
    }

    return 0;
}