// single linkedlist
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert_at_first(struct node *ptr)
{
    int value;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to insert\n");
    scanf("%d", &value);
    if (temp == NULL)
    {
        printf("node is not created\n");
    }
    else
    {
        printf("NodeCreated \n");
        temp->data = value;
        temp->next = ptr;
        ptr = temp;
        return temp;
    }
}

struct node *insert_at_end(struct node *ptr)
{
    int value;
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter the value to insert at end\n");
    scanf("%d", &value);
    temp->data = value;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = NULL;
    printf("Node Inserted \n");
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insert_after_value(struct node *head)
{
    int val, match, flag = 0;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = head;
    printf("Enter the value of  node \n");
    scanf("%d", &match);

    while (head != NULL)
    {
        if (head->data == match)
        {
            if (head->next == NULL)
            {
                char u;
                printf("This value is found last of the list \nAre you insert at end (y\\n)\n");
                scanf(" %c", &u);
                if (u == 'y' || u == 'Y')
                {
                    insert_at_end(head2);
                }
                else if (u == 'n' || u == 'N')
                {
                    return;
                }
                else
                {
                    printf("Choose valid value\n");
                }
                flag = 1;
            }
            else
            {

                printf("Enter the value,  to add  after node\n");
                scanf("%d", &val);
                flag = 1;
                temp->data = val;
                temp->next = head->next;
                head->next = temp;
                break;
            }
        }
        head = head->next;
    }

    if (flag == 0)
    {
        printf("Value not found \n");
        return;
    }
    else
    {
        printf("Value Inserted\n");
    }
}

struct node *insert_before_value(struct node *head)
{
    int match, val, flag = 0;
    struct node *head2 = head;
    printf("Enter the node value\n");
    scanf("%d", &match);
    char u;
    if (head->data == match)
    {
        flag = 1;
        printf("This value found on head  continue to add value before head to enter \n");
        scanf(" %c", &u);
        fflush(stdout);
        fflush(stdin);
        if (u == 'y' || u == 'Y')
        {
            head = insert_at_first(head);
            return head2;
        }
        else if (u == 'n' || u == 'N')
        {
            return head2;
        }
        else
        {
            printf("Enter proper value\n");
            return head2;
        }
    }

    else
    {
        struct node *prev = head;

        while (head->next != NULL)
        {

            if (head->data == match)
            {
                printf("Enter the value to insert \n");
                scanf("%d", &val);
                struct node *temp = (struct node *)malloc(sizeof(struct node));
                temp->data = val;
                temp->next = head;
                prev->next = temp;
                flag = 1;
                break;
            }
            prev = head;
            head = head->next;
        }
        if (flag)
        {
            printf("Value inserted\n");
        }
        else
        {
            printf("Value not found\n");
        }
    }

    return head2;
}

struct node *delete_at_end(struct node *ptr)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *q = (struct node *)malloc(sizeof(struct node));
    p = ptr;
    q = ptr->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return p;

    printf("Delete at end\n");
}

void change1(struct node *head)
{
    int match, val;
    printf("Enter the node value \n");
    scanf("%d", &match);
    while (head->next != NULL)
    {
        if (head->data == match)
        {
            printf("Enter the value to change\n");
            scanf("%d", &val);
            head->data = val;
            break;
        }
    }
    if (head != NULL)
    {
        printf("Value change %d to %d\n", match, val);
        return;
    }
    printf("value not found\n");
}

struct node *delete_at_begin(struct node *ptr)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p = ptr->next;
    free(ptr);
    printf("Delete at beign\n");
    return p;
}

void delete_after_value(struct node *ptr)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *q = (struct node *)malloc(sizeof(struct node));
    p = ptr;
    q = ptr->next;
    int flag = 0, val;
    printf("Enter the value, to DELETE after : ");
    scanf("%d", &val);
    while (q != NULL)
    {
        if (p->data == val)
        {
            flag = 1;
            printf("%d\n", q->data);
            break;
        }
        p = p->next;
        q = q->next;
    }
    if (flag == 0)
    {
        printf("%d is not found\n", val);
        return;
    }
    printf("Deleted");
    p->next = q->next;
    free(q);
}

void delete_before_value(struct node *ptr)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *q = (struct node *)malloc(sizeof(struct node));
    p = ptr;
    q = ptr->next;
    int flag = 0, val;
    printf("Enter the value, to DELETE before : ");
    scanf("%d", &val);
    while (q != NULL)
    {
        if (p->data == val)
        {
            flag = 1;
            printf("%d\n", q->data);
            break;
        }
        p = p->next;
        q = q->next;
    }
    if (flag == 0)
    {
        printf("%d value  not found in linkedlist\n", val);
        return;
    }
    else
    {
        printf("Delete successfully\n");
    }

    p->next = q->next;
    free(q);
}

void delete_at_value(struct node *ptr)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *q = (struct node *)malloc(sizeof(struct node));
    p = ptr;
    q = ptr->next;
    int flag = 0, val;
    printf("Enter the value, to DELETE at value : ");
    scanf("%d", &val);
    while (q != NULL)
    {
        if (q->data == val)
        {
            flag = 1;
            printf("%d\n", q->data);
            break;
        }
        p = p->next;
        q = q->next;
    }
    if (flag == 0)
    {
        printf("%d value  not found in linkedlist\n", val);
        return;
    }
    else
    {
        printf("Delete successfully\n");
    }

    p->next = q->next;
    free(q);
}

void deletell(struct node *ptr)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    struct node *s = (struct node *)malloc(sizeof(struct node));
    s = ptr->next;
    while (s != NULL)
    {
        s = s->next;
        t = s;
        free(t);
    }
    free(ptr);
}

void sort(struct node *head)
{
    struct node *ptr, *ptr2;
    int temp;
    for (ptr = head; ptr != NULL; (ptr) = ptr->next)
    {
        for (ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if (ptr->data > ptr2->data)
            {
                temp = ptr2->data;
                ptr2->data = ptr->data;
                ptr->data = temp;
            }
        }
    }
}

int main()
{

    printf("\nName : Umang Dalvadi\n");
    printf("Enrollmrnt No. : 210210116020\n\n");
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *last = (struct node *)malloc(sizeof(struct node));

    head->data = 24;
    head->next = last;

    last->data = 29;
    last->next = NULL;

    int c, val, flag = 0;

    while (1)
    {

        printf("\nINSERT operations\n");

        printf("\t1: Insert At Begin\n");
        printf("\t2: Insert At End\n");
        printf("\t3: Insert At Given Value\n");
        printf("\t4: Insert Before Value\n");
        printf("\t5: Insert After Given Value\n\n");

        printf("DELETE operations\n");

        printf("\t6: Delete At Begin\n");
        printf("\t7: Delete At End\n");
        printf("\t8: Delete At Value\n");
        printf("\t9: Delete After Value\n");
        printf("\t10: Delete Before Value\n\n");

        printf("LINKEDLIST OPERATIONS\n");

        printf("\t11: DISPLAY\n");
        printf("\t12: Delete Linkedlist\n");
        printf("\t13: Create Linkedlist\n");

        printf("\t14: Sort\n");
        printf("\t15: EXIT\n");
        printf("=================================================\n");

        printf("\nEnter the choise : ");

        scanf("%d", &c);

        switch (c)
        {
        case 1:
            head = insert_at_first(head);
            break;
        case 2:
            insert_at_end(head);
            break;
        case 3:
            change1(head);
            break;
        case 4:
            head = insert_before_value(head);
            break;
        case 5:
            insert_after_value(head);
            break;
        case 6:
            head = delete_at_begin(head);
            break;
        case 7:
            delete_at_end(head);
            break;
        case 8:
            delete_at_value(head);
            break;
        case 9:
            delete_after_value(head);
            break;
        case 10:
            delete_before_value(head);
            break;
        case 11:
            display(head);
            break;
        case 12:
            deletell(head);
            flag = 1;
            break;
        case 13:
            head->data = val;
            break;
        case 14:
            sort(head);
            break;
        case 15:
            exit(1);
            break;
        default:
            printf("Enter proper value\n");
            break;
        }
        printf("-------------------------------------------------\n");
        sleep(2);
    }
    return 0;
}