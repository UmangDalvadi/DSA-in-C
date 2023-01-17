#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main(void)
{
    printf("\n");
    printf("\n\tName : Umang Dalvadi\n");
    printf("\tEnroll no. : 210210116020\n");
    printf("================================\n");
    int arr[] = {29, 44, 45, 12, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 29;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? printf("not present in array")
        : printf("present at index : %d\n", result);
    return 0;
}
