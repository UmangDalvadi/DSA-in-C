#include <stdio.h>
#include <stdlib.h>
int l = 0;
int i = 0;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int data)
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        temp = create(data);
        return temp;
    }

    if (data < temp->data)
    {
        temp->left = insert(temp->left, data);
    }
    else if (data > temp->data)
    {
        temp->right = insert(temp->right, data);
    }
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {

        inorder(root->left);
        printf(" %d  ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf(" %d  ", root->data);
    }
}

struct node *search(struct node *root, int value)
{
    struct node *temp;
    temp = root;
    if (value == root->data)
    {
        return temp;
    }
    else if (value < temp->data)
    {
        return search(temp->left, value);
    }
    else if (value > temp->data)
    {
        return search(temp->right, value);
    }
    else
    {
        return NULL;
    }
}

struct node *min(struct node *root)
{
    struct node *temp;
    temp = root;

    while (temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

struct node *delete(struct node *root, int data)
{
    struct node *temp, *ptr;
    temp = root;
    if (temp == NULL)
    {
        return temp;
    }

    else if (data < temp->data)
    {
        temp->left = delete (temp->left, data);
    }

    else if (data > temp->data)
    {
        temp->right = delete (temp->right, data);
    }

    else
    {

        if (temp->left == NULL)
        {
            ptr = temp->right;
            free(temp);
            return ptr;
        }

        else if (temp->right == NULL)
        {
            ptr = temp->left;
            free(temp);
            return ptr;
        }
        ptr = min(temp->right);

        temp->data = ptr->data;

        temp->right = delete (temp->right, ptr->data);
    }
    return temp;
}

int height(struct node *root)
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        return 0;
    }
    int leftheight, rightheight;
    leftheight = height(temp->left);
    rightheight = height(temp->right);

    if (leftheight > rightheight)
    {
        return leftheight + 1;
    }
    else
    {
        return rightheight + 1;
    }
}

void leaf(struct node *root)
{
    struct node *temp;
    temp = root;
    if (temp != NULL)
    {
        leaf(temp->left);
        if (temp->left == NULL && temp->right == NULL)
        {
            l = l + 1;
        }
        leaf(temp->right);
    }
}

void internal(struct node *root)
{
    struct node *temp;
    temp = root;
    if (temp != NULL)
    {
        internal(temp->left);
        if (temp->left != NULL || temp->right != NULL)
        {
            i = i + 1;
        }
        internal(temp->right);
    }
}
int main()
{
    int data;
    int high;
    struct node *root, *ptr;
    root = NULL;
    root = insert(root, 24);
    printf("\n\tName : Umang Dalvadi\n");
    printf("\tEnroll no. : 210210116020\n");

    int ch;
    while (1)
    {
        printf("\n==============================================================================\n");
        printf("\n\t1.Insert\n\t2.Search node\n\t3.find Minimum element\n\t4.delete a specific data\n\t5.Print in inorder\n\t6.Print in preorder\n\t7.Print in postorder\n\t8.height of a Tree\n\t9.find number of leaf node\n\t10.find number of internal node\n\t11.find the Total number of nodes\n\t12.Exit\n");
        printf("\n Enter the choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter the data : ");
            scanf("%d", &data);
            insert(root, data);
            inorder(root);
            break;
        case 2:
            printf("\n Enter the element which you want to search : ");
            scanf("%d", &data);
            ptr = search(root, data);
            if (ptr == NULL)
            {
                printf("\nThere is not such an element");
            }
            else
            {
                printf("\nfinded element is : %d", ptr->data);
            }
            break;
        case 3:
            ptr = min(root);
            printf("\nminimum element is : %d", ptr->data);
            break;
        case 4:
            printf("\n Enter the element which you want to delete : ");
            scanf("%d", &data);
            root = delete (root, data);
            printf("\n After deleting the specific data from the tree : ");
            inorder(root);
            break;
        case 5:
            printf("\ninorder : ");
            inorder(root);
            break;
        case 6:
            printf("\npreorder : ");
            preorder(root);
            break;
        case 7:
            printf("\npostorder : ");
            postorder(root);
            break;
        case 8:
            high = height(root);
            printf("\nheight of Tree : %d", high);
            break;
        case 9:
            leaf(root);
            printf("\nnumber of leaf node : %d", l);
            break;
        case 10:
            internal(root);
            printf("\nnumber of internal node : %d", i - 1);
            break;
        case 11:
            internal(root);
            leaf(root);
            printf("\nTotal number of nodes : %d", l + i);
            break;
        case 12:
            exit(1);
            break;
        }
    }
}
