#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} boolean;

struct node *in_succ(struct node *p);
struct node *in_pred(struct node *p);
struct node *insert(struct node *root, int ikey);
struct node *del(struct node *root, int dkey);
struct node *case_a(struct node *root, struct node *par, struct node *ptr);
struct node *case_b(struct node *root, struct node *par, struct node *ptr);
struct node *case_c(struct node *root, struct node *par, struct node *ptr);

void inorder(struct node *root);
void preorder(struct node *root);

struct node
{
    struct node *left;
    boolean lthread;
    int info;
    boolean rthread;
    struct node *right;
};

int main()
{
    int choice, num;
    struct node *root = NULL;
    printf("\n\tName : Umang Dalvadi\n");
    printf("\tEnroll no. : 210210116020\n");

    while (1)
    {
        printf("\n============================================================\n");
        printf("\t1.Insert\n");
        printf("\t2.delete\n");
        printf("\t3.Inorder Traversal\n");
        printf("\t4.Preorder Traversal\n");
        printf("\t5.exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("\nEnter the number to be inserted : ");
            scanf("%d", &num);
            root = insert(root, num);
            break;

        case 2:
            printf("\nEnter the number to be deleted : ");
            scanf("%d", &num);
            root = del(root, num);
            break;

        case 3:
            inorder(root);
            break;

        case 4:
            preorder(root);
            break;

        case 5:
            exit(1);

        default:
            printf("\nWrong choice\n");
        }
    }
    return 0;
}
struct node *insert(struct node *root, int ikey)
{
    struct node *tmp, *par, *ptr;

    int found = 0;

    ptr = root;
    par = NULL;

    while (ptr != NULL)
    {
        if (ikey == ptr->info)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (ikey < ptr->info)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    if (found)
        printf("\nDuplicate key");
    else
    {

        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = ikey;
        tmp->lthread = true;
        tmp->rthread = true;
        if (par == NULL)
        {
            root = tmp;
            tmp->left = NULL;
            tmp->right = NULL;
        }
        else if (ikey < par->info)
        {
            tmp->left = par->left;
            tmp->right = par;
            par->lthread = false;
            par->left = tmp;
        }
        else
        {
            tmp->left = par;
            tmp->right = par->right;
            par->rthread = false;
            par->right = tmp;
        }
    }
    return root;
}

struct node *del(struct node *root, int dkey)
{
    struct node *par, *ptr;

    int found = 0;

    ptr = root;
    par = NULL;

    while (ptr != NULL)
    {
        if (dkey == ptr->info)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (dkey < ptr->info)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    if (found == 0)
        printf("\ndkey not present in tree");
    else if (ptr->lthread == false && ptr->rthread == false)
        root = case_c(root, par, ptr);
    else if (ptr->lthread == false)
        root = case_b(root, par, ptr);
    else if (ptr->rthread == false)
        root = case_b(root, par, ptr);
    else
        root = case_a(root, par, ptr);
    return root;
}

struct node *case_a(struct node *root, struct node *par, struct node *ptr)
{
    if (par == NULL)
        root = NULL;
    else if (ptr == par->left)
    {
        par->lthread = true;
        par->left = ptr->left;
    }
    else
    {
        par->rthread = true;
        par->right = ptr->right;
    }
    free(ptr);
    return root;
}

struct node *case_b(struct node *root, struct node *par, struct node *ptr)
{
    struct node *child, *s, *p;

    if (ptr->lthread == false)
        child = ptr->left;
    else
        child = ptr->right;

    if (par == NULL)
        root = child;
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;

    s = in_succ(ptr);
    p = in_pred(ptr);

    if (ptr->lthread == false)
        p->right = s;
    else
    {
        if (ptr->rthread == false)
            s->left = p;
    }

    free(ptr);
    return root;
}

struct node *case_c(struct node *root, struct node *par, struct node *ptr)
{
    struct node *succ, *parsucc;

    parsucc = ptr;
    succ = ptr->right;
    while (succ->left != NULL)
    {
        parsucc = succ;
        succ = succ->left;
    }

    ptr->info = succ->info;

    if (succ->lthread == true && succ->rthread == true)
        root = case_a(root, parsucc, succ);
    else
        root = case_b(root, parsucc, succ);
    return root;
}

struct node *in_succ(struct node *ptr)
{
    if (ptr->rthread == true)
        return ptr->right;
    else
    {
        ptr = ptr->right;
        while (ptr->lthread == false)
            ptr = ptr->left;
        return ptr;
    }
}

struct node *in_pred(struct node *ptr)
{
    if (ptr->lthread == true)
        return ptr->left;
    else
    {
        ptr = ptr->left;
        while (ptr->rthread == false)
            ptr = ptr->right;
        return ptr;
    }
}

void inorder(struct node *root)
{
    struct node *ptr;
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }

    ptr = root;

    while (ptr->lthread == false)
        ptr = ptr->left;

    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = in_succ(ptr);
    }
}

void preorder(struct node *root)
{
    struct node *ptr;
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    ptr = root;

    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        if (ptr->lthread == false)
            ptr = ptr->left;
        else if (ptr->rthread == false)
            ptr = ptr->right;
        else
        {
            while (ptr != NULL && ptr->rthread == true)
                ptr = ptr->right;
            if (ptr != NULL)
                ptr = ptr->right;
        }
    }
}
