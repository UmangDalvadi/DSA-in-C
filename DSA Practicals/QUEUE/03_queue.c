#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int *queue;
int front = -1, rear = -1, size;
void insert_front(int x)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("queue is full");
    }
    else if ((front == -1) && (rear == -1))
    {
        front = rear = 0;
        queue[front] = x;
    }
    else if (front == 0)
    {
        front = size - 1;
        queue[front] = x;
    }
    else
    {
        front = front - 1;
        queue[front] = x;
    }
}
void insert_last(int x)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("queue is full");
    }
    else if ((front == -1) && (rear == -1))
    {
        rear = 0;
        queue[rear] = x;
    }
    else if (rear == size - 1)
    {
        rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is Empty...");
        getch();
    }
    else
    {
        printf("The Elements are : \n");
        if (front <= rear)
        {
            while (front <= rear)
            {
                printf("%d\t", queue[front]);
                front++;
            }
        }
        else
        {
            while (front <= size - 1)
            {
                printf("%d\t", queue[front]);
                front++;
            }
            front = 0;
            while (front <= rear)
            {
                printf("%d\t", queue[front]);
                front++;
            }
        }
        printf("\n");
    }
}
void del_front()
{
    if ((front == -1) && (rear == -1))
    {
        printf("queue is empty");
    }
    else if (front == rear)
    {
        printf("\nThe deleted element is %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else if (front == (size - 1))
    {
        printf("\nThe deleted element is %d", queue[front]);
        front = 0;
    }
    else
    {
        printf("\nThe deleted element is %d", queue[front]);
        front = front + 1;
    }
}
void del_last()
{
    if ((front == -1) && (rear == -1))
    {
        printf("queue is empty");
    }
    else if (front == rear)
    {
        printf("\nThe deleted element is %d", queue[rear]);
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        printf("\nThe deleted element is %d", queue[rear]);
        rear = size - 1;
    }
    else
    {
        printf("\nThe deleted element is %d", queue[rear]);
        rear = rear - 1;
    }
}
int main()
{
    int choice, n;
    printf("\nName : Umang Dalvadi\n");
    printf("Enrollmrnt No. : 210210116020\n\n");
    printf("\nEnter the size of the Queue: ");
    printf("\n");
    scanf("%d", &size);
    queue = (int *)malloc(size * sizeof(int));
    if (queue == NULL)
    {
        printf("Memory not Allocated...\n");
        getch();
    }
    else
    {
        printf("1.INSERT AT FRONT\n");
        printf("2.INSERT AT LAST\n");
        printf("3.DELETE FROM FRONT\n");
        printf("4.DELETE FROM LAST\n");
        printf("5.DISPLAY \n");
        printf("6.EXIT \n");
        do
        {
            printf("\nEnter your Choice: ");
            printf("\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter the Value you Want to Insert : ");
                scanf("%d", &n);
                insert_front(n);
                break;
            case 2:
                printf("Enter the Value you Want to Insert : ");
                scanf("%d", &n);
                insert_last(n);
                break;
            case 3:
                del_front();
                break;
            case 4:
                del_last();
                break;
            case 5:
                display();
                break;
            case 6:
                free(queue);
                exit(0);
                break;
            default:
                printf("Invalid choice...");
                break;
            }
        } while (choice != 6);
        printf("=========================================\n");
    }
    getch();
}