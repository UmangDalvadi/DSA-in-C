#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

int isfull(struct node *top)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}
int isempty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

struct node *push(struct node *top)
{
    if (isfull(top))
    {
        printf("-----Stack Overflow!!-----\n");
        return 0;
    }

    int n, val;
    printf("\nHow many element you want to push :");
    scanf("%d", &n);
    printf("\n");
    for (int i = n - 1; i >= 0; i--)
    {
        struct node *node = (struct node *)malloc(sizeof(struct node));
        printf("Enter %d element :", i);
        scanf("%d", &val);
        node->data = val;
        node->next = top;
        top = node;
    }
    return top;
}

struct node *pop(struct node *top)
{
    if (isempty(top))
    {
        printf("-----Stack Underflow!!!-----\n");
        return 0;
    }
    // struct node *n = (struct node *)malloc(sizeof(struct node));
    // n = top;
    // top = top->next;
    printf("popped element :%d\n", top->data);
    return top->next;
}

void peek(struct node *top)
{
    printf("\nEnter element number to peeked value :");
    int ele;
    scanf("%d", &ele);
    if (isempty(top))
    {
        printf("-----Stack Underflow-----\n");
    }

    for (int i = 0; i < ele; i++)
    {
        top = top->next;
    }
    printf("\npeeked element at position %d is :%d\n", ele, top->data);

    // struct node *n = (struct node *)malloc(sizeof(struct node));
    // n = top;
    // top = top->next;
    // return top->data;
}

void change_value(struct node *top)
{
    printf("\nEnter element to change value :");
    int ele;
    scanf("%d", &ele);
    if (isempty(top))
    {
        printf("-----Stack Underflow-----\n");
    }

    for (int i = 0; i < ele; i++)
    {
        top = top->next;
    }
    printf("\nenter new value : ");
    int val;
    scanf("%d", &val);
    top->data = val;
    printf("\n-----Value Changed-----\n");
}

void display(struct node *top)
{
    for (int i = 0; top != NULL; i++)
    {
        printf("value at element %d is :%d\n", i, top->data);
        top = top->next;
    }
}

int main()
{
    printf("\nName : Umang Dalvadi\n");
    printf("Enrollmrnt No. : 210210116020\n\n");
    printf("\n-------------------------create a stack (PUSH Elements)-------------------------\n");
    struct node *top = NULL;
    int num;
    do
    {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. CHANGE VALUE\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            top = push(top);
            printf("\n-----Elements pushed-----\n");
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            change_value(top);
            break;
        case 5:
            display(top);
            break;

        default:
            break;
        }
        printf("\n--------------------------------!!!THANK YOU!!!------------------------------------\n");
    } while (num != 6);

    return 0;
}