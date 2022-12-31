#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *node(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node *n)
{
    // printf("enterd node : %d\n", n->data);
    if (n != NULL)
    {
        printf("%d ", n->data);
        preorder(n->left);
        preorder(n->right);
        // printf("e:%d ", n->data);
    }
    // printf(" v:%d \n",n->data);
}
void postorder(struct node *n)
{
    // printf("enterd node : %d\n", n->data);
    if (n != NULL)
    {
        postorder(n->left);
        postorder(n->right);
        printf("%d ", n->data);
        // printf("e:%d ", n->data);
    }
    // printf(" v:%d \n",n->data);
}
void inorder(struct node *n)
{
    // printf("enterd node : %d\n", n->data);
    if (n != NULL)
    {
        inorder(n->left);
        printf("%d ", n->data);
        inorder(n->right);
        // printf("e:%d ", n->data);
    }
    // printf(" v:%d \n",n->data);
}

int isbst(struct node *n)
{
    static struct node *prev = NULL;
    if (n != NULL)
    {
        // printf("isbst(n->left) : %d\n", !isbst(n->left));
        if (!isbst(n->left))
        {
            return 0;
        }
        printf("n->data : %d\n", n->data);
        if (prev != NULL && n->data <= prev->data)
        {
            return 0;
        }
        prev = n;
        printf("prev : %d\n", prev->data);
        return isbst(n->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct node *n7 = node(7);
    struct node *n5 = node(5);
    struct node *n10 = node(10);
    struct node *n1 = node(3);
    struct node *n6 = node(6);
    struct node *n9 = node(9);
    struct node *n11 = node(11);
    n7->left = n5;
    n7->right = n10;
    n5->left = n1;
    n5->right = n6;
    n10->left = n9;
    n10->right = n11;
    //         n7
    //      /       \
    //    n5         n10
    //   /  \       /  \
    // n1    n6   n9    n11

    // preorder(n1);
    // printf("\n");
    // inorder(n1);
    // printf("\n");
    // postorder(n1);
    printf("%d\n", isbst(n7));
    // isbst(n7);

    return 0;
}