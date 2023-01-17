#include <stdio.h>

int linearSearch(int a[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
            return i + 1;
    }
    return -1;
}
int main()
{
    printf("\n");
    printf("\n\tName : Umang Dalvadi\n");
    printf("\tEnroll no. : 210210116020\n");
    printf("====================================================\n");
    int a[10], n, c, val;
    printf("\nHow many elements you want to add :");
    scanf("%d", &n);
    printf("\nEnter %d integers : \n", n);
    for (c = 0; c < n; c++)
    {
        scanf("%d", &a[c]);
    }
    printf("\nEnter value to be searched : ");
    scanf("%d", &val);
    int res = linearSearch(a, n, val);
    printf("\nThe elements of the arrays are : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nElement to be searched is : %d", val);
    if (res == -1)
        printf("\nElement is not present in the array");
    else
        printf("\nElement is present at '%d' position of array", res);
    return 0;
}
