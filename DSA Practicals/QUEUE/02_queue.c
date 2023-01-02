#include <stdio.h>
#define SIZE 5
int q[SIZE];
int f = -1, r = -1;
void insert()
{
    int data;
    if ((r == SIZE - 1 && f == 0) || (r == f - 1))
    {
        printf("\nQueue is full!!");
    }
    else
    {
        printf("\nEnter data : ");
        scanf("%d", &data);
        if (r == -1)
        {
            f++;
        }
        if (r == SIZE - 1 && f != 0)
        {
            r = -1;
        }
        q[++r] = data;
    }
}
void display()
{
    if (f == -1)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue : ");
    if (r >= f)
    {
        for (int i = f; i <= r; i++)
        {
            printf("%d ", q[i]);
        }
    }
    else
    {
        for (int i = f; i < SIZE; i++)
        {
            printf("%d ", q[i]);
        }
        for (int i = 0; i <= r; i++)
        {
            printf("%d ", q[i]);
        }
    }
}
void pop()
{
    if (f == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        if (f == r)
        {
            f = -1;
            r = -1;
            return;
        }
        else if (f == SIZE - 1)
        {
            f = 0;
        }
        printf("\n%d is pop from queue!", q[f]);
        f++;
    }
}
int main()
{

    int ch;
    printf("\nName : Umang Dalvadi\n");
    printf("Enrollmrnt No. : 210210116020\n\n");
    while (1)
    {
        printf("0. EXIT\n");
        printf("1. INSERT\n");
        printf("2. DISPLAY\n");
        printf("3. POP\n");
        printf("\n");

        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 0:
            return 0;
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            pop();
            break;
        }
        printf("\n=============================================\n");
    }
    return 0;
}