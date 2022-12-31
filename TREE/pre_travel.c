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

int main()
{
    struct node *n1 = node(1);
    struct node *n2 = node(2);
    struct node *n3 = node(3);
    struct node *n4 = node(4);
    struct node *n5 = node(5);
    struct node *n6 = node(6);
    struct node *n7 = node(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    //         n1
    //      /       \
    //    n2         n3
    //   /  \       /  \
    // n4    n5   n6    n7

    preorder(n1);

    return 0;
}