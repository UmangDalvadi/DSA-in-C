#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_c(char **c_name, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {

            if (strcmp(c_name[j], c_name[j + 1]) > 0)
            {
                char *temp;
                temp = (char *)calloc(30, sizeof(char));
                strcpy(temp, c_name[j]);
                strcpy(c_name[j], c_name[j + 1]);
                strcpy(c_name[j + 1], temp);
            }
        }
    }
}

//*


int main()
{
    char **c_name;
    int i, n;
    printf("Enter the number of  city's Names : ");
    scanf("%d", &n);
    // scanf("%s", c_name[i]);

    c_name = (char **)calloc(n, sizeof(char));

    for (i = 0; i < n; i++)
    {
        c_name[i] = (char *)calloc(30, sizeof(char));
        printf("Enter %d city : ",i+1);
        scanf("%s", c_name[i]);
        // scanf("%s", c_name[i]);
        // scanf("%s", c_name[i]);
    }
   //*
    sort_c(c_name, n);

    printf("\nAfter sorting city's names : \n");

    for (i = 0; i < n; i++)
    {
        printf("%s\n", c_name[i]);
    }

    return 0;
}