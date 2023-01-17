#include <stdio.h>
#include <conio.h>

int main()
{
    printf("\n");
    printf("\n\tName : Umang Dalvadi\n");
    printf("\tEnroll no. : 210210116020\n");
    printf("============================================\n");
    int array[100], n, c, d, swap;
    printf("\nHow many elements you want to add :");
    scanf("%d", &n);
    printf("\nEnter %d integers : \n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);
    for (c = 0; c < n - 1; c++)
    {
        for (d = 0; d < n - c - 1; d++)
        {
            if (array[d] > array[d + 1])
            {
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
    printf("\nSorted list in ascending order : ");
    for (c = 0; c < n; c++)
        printf("%d ", array[c]);
    printf("\n");
    return 0;
}
