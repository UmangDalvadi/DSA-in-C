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

int search(struct node *n, int val)
{
    if (n == NULL)
    {
        return 0;
    }
    else if (n->data == val)
    {
        return val;
    }
    else if (n->data > val)
    {
        return search(n->left, val);
    }
    else
    {
        return search(n->right, val);
    }
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;
    while (root != NULL)
    {
        prev = root;

        if (root->data == key)
        {
            printf("Duplicate is not allowed\n");
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (root == NULL)
    {
        if (prev->data > key)
        {
            prev->left = ptr;
            printf("inserted : %d\n", prev->left->data);
        }
        else
        {
            prev->right = ptr;
            printf("inserted : %d\n", prev->right->data);
        }
    }
}
// int deletion_leafnode(struct node *root, int key)
// {
//     struct node *prev = NULL;

//     while (root != NULL)
//     {
//         if (prev != NULL)
//         {
//             if (prev->left->data == key)
//             {
//                 prev->left = NULL;
//                 printf("leaf_deletion completed : ");
//                 return 0;
//             }
//             else if (prev->right->data == key)
//             {
//                 prev->right = NULL;
//                 printf("leaf_deletion completed : ");
//                 return 0;
//             }
//         }
//         prev = root;
//         if (key < root->data)
//         {
//             root = root->left;
//         }
//         else
//         {
//             root = root->right;
//         }
//     }
//     printf("deletion is not allowed\n");
// }

struct node *inorder_pre(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *dltnode(struct node *root, int val)
{
    struct node *inpre;
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (root->data > val)
    {
        root->left = dltnode(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = dltnode(root->right, val);
    }
    else
    {
        inpre = inorder_pre(root);
        root->data = inpre->data;
        root->left = dltnode(root->left, inpre->data);
    }
    return root;
}

int main()
{
    struct node *n7 = node(7);
    struct node *n5 = node(5);
    struct node *n10 = node(10);
    struct node *n3 = node(3);
    struct node *n6 = node(6);
    struct node *n9 = node(9);
    struct node *n11 = node(11);
    n7->left = n5;
    n7->right = n10;
    n5->left = n3;
    n5->right = n6;
    n10->left = n9;
    n10->right = n11;
    //         n7
    //      /       \
    //    n5         n10
    //   /  \       /  \
    // n3    n6   n9    n11

    // preorder(n1);
    // printf("\n");
    // inorder(n1);
    // printf("\n");
    // postorder(n1);
    // printf("%d\n", isbst(n7));
    // printf("%d\n", search(n7, 3));
    // isbst(n7);
    inorder(n7);
    printf("\n");
    // insert(n7, 8);
    // printf("%d\n", deletion_leafnode(n7, 6));
    dltnode(n7, 7);
    inorder(n7);
    return 0;
}