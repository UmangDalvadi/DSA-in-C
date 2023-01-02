#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int q[SIZE];
int r = -1;
int f = -1;

void insert()
{
    int num;
    if (r == SIZE - 1)
    {
        printf("\nQueue Is Full..\n");
    }
    else
    {
        printf("\nEnter Number : ");
        scanf("%d", &num);
        r++;
        q[r] = num;
        if (f == -1)
        {
            f++;
        }
    }
}
void display()
{
    for (int i = f; i <= r; i++)
    {
        printf(" %d", q[i]);
    }
}
void deleteQ()
{
    if (f == -1)
    {
        printf("\nQueue Is Empty..\n");
    }
    else
    {
        printf("\n%d Deleted", q[f]);
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f++;
        }
    }
}
void search()
{
    int searchNum, counter = 0, isFund = 0;
    printf("\nName:JATIN RATHOD");
    printf("\nEnrollment No: 210210116017");
    printf("\nEnter number which you want search : ");
    scanf("%d", &searchNum);
    for (int i = r; i <= f; i++)
    {
        counter++;
        if (searchNum == q[i])
        {
            isFund = 1;
            printf("\n%d Is Found at %d location", q[i], counter);
            break;
        }
    }
    if (!isFund) // 0 ---> (!0=1)
    {
        printf("%d is not found", searchNum);
    }
}
int main()
{
    printf("\nName : Umang Dalvadi\n");
    printf("Enrollmrnt No. : 210210116020\n\n");
    int choice;
    while (1)
    {
        printf("1. INSERT\n");
        printf("2. DISPLAY\n");
        printf("3. DELETE\n");
        printf("4. INSERT\n");
        printf("5. SEARCH\n");
        printf("0. EXIT\n");
        printf("\n");

        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            insert();
            printf("\n");
            break;
        case 2:
            display();
            printf("\n");
            break;
        case 3:
            deleteQ();
            printf("\n");
            break;
        case 4:
            search();
            printf("\n");
            break;

        default:
            printf("\nYou Enter Worng Choice\n");
        }
        printf("===================================================\n");
    }
    return 0;
}