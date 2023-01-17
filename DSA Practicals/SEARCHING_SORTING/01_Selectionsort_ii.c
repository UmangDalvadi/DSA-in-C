#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    printf("\n");
    printf("\n\tName : Umang Dalvadi\n");
    printf("\tEnroll no. : 210210116020\n");
    printf("=======================================================\n");
    int array[10], n, c;
    printf("\nHow many elements you want to add :");
    scanf("%d", &n);
    printf("\nEnter %d integers : \n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);
    selectionSort(array, n);
    printf("\nSorted list : ");
    printArray(array, n);
    return 0;
}
