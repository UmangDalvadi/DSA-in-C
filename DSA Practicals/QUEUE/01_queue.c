// WRITE A PROGRAM TO CREATE A QUEUE AND PERFORM

// FOLLOWING OPERATION ON QUEUE
// ===========================================
// INSERT AN ELEMENT

// DELETE AN ELEMENT

// DISPLAY ALL ELEMENTS IN QUEUE
// =========================================
#include <stdio.h>

#include <conio.h>

#include <stdlib.h>

int *queue, choice, front, rear, x, i, n;

void insert();

void del();

void display();

int main()
{

    front = rear = -1;

    printf("Enter the size of the Queue: ");

    scanf("%d", &n);

    queue = (int *)malloc(n * sizeof(int));

    if (queue == NULL)
    {
        printf("Memory not Allocated...\n");

        getch();

        exit(0);
    }

    else
    {
        printf("1.INSERT \n");

        printf("2.DELETE \n");

        printf("3.DISPLAY \n");

        printf("4.EXIT \n");
    }

    do
    {
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            insert();
            break;

        case 2:
            del();

            break;

        case 3:
            display();

            break;

        case 4:
            return 0;

            break;

        default:
            printf("Invalid choice...");

            break;
        }
    }

    while (choice = 4);

    getch();
}

void insert()

{

    if (rear == n - 1)
    {

        printf("Queue Overflow...");
    }

    else
    {

        if (front == -1)
        {

            front = 0;
        }

        printf("Enter a Value: ");
        scanf("%d", &x);

        rear++;

        queue[rear] = x;
    }
}

void display()
{

    if (front == -1)
    {

        printf("Queue is Empty");
    }

    else
    {

        printf("Your Data...\n");

        for (i = front; i <= rear; i++)
        {

            printf("%d\n", queue[i]);
        }
    }
}

void del()
{

    if ((front == -1) || (front > rear))
    {

        printf("Queue Underflow...");

        getch();

        // exit(0);
    }
    else
    {
        printf("Deleted Element is %d", queue[front]);

        front++;

        // rear-;
    }
}