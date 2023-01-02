#include <stdio.h>

struct student
{
    char name[20];
    char dept[50];
    int sem;
    float spi;
};

int main()
{
    struct student s[2];
    FILE *fp = NULL;
    fp = fopen("std_data.txt", "a");
    for (int i = 0; i < 2; i++)
    {
        printf("Enter the name of student %d : ", i + 1);
        scanf("%s", &s[i].name);
        printf("Enter the department of student %d : ", i + 1);
        scanf("%s", &s[i].dept);
        printf("Enter the semester of student %d : ", i + 1);
        scanf("%d", &s[i].sem);
        printf("Enter the SPI of student %d : ", i + 1);
        scanf("%f", &s[i].spi);
        printf("\n");
        fprintf(fp, "name of student %d : %s \ndepartment of student %d : %s \nsemester of student %d : %d \nSPI of student %d : %f \n\n", i + 1, s[i].name, i + 1, s[i].dept, i + 1, s[i].sem, i + 1, s[i].spi);
    }

    printf("Enter 1 : to Display students list\n");
    printf("Enter 2 : to Search a student\n");
    printf("Enter 3 : to Sort student with respect to SPI\n");
    printf("Enter 4 : Edit the details of any students\n");
    printf("Enter 5 : to Delete the details of any student\n\n");
    int n, o, p;
    printf("Enter : ");
    scanf("%d", &n);
    printf("\n\n");
    // char ch;

    switch (n)
    {

    case 1:
        for (int i = 0; i < 5; i++)
        {
            printf("%s\n", s[i].name);
        }
        break;

    case 2:

        break;

    case 3:
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 5; j++)
            {
                if (s[j].spi > s[i].spi)
                {
                    int temp = s[j].spi;
                    s[j].spi = s[i].spi;
                    s[i].spi = temp;
                }
            }
        }
        for (int i = 0; i < 5; i++)
        {
            printf("Name : %s ,SPI : %.3f\n", s[i].name, s[i].spi);
        }

        break;

    case 4:
        // int o;
        printf("Enter the number in the respect of the person whose details you want to edit\n");
        printf("press 1 : to %s\n", s[0].name);
        printf("press 2 : to %s\n", s[1].name);
        printf("press 3 : to %s\n", s[2].name);
        printf("press 4 : to %s\n", s[3].name);
        printf("press 5 : to %s\n", s[4].name);
        scanf("%d", &o);
        // int p;
        printf("Which data you want to edit\n");
        printf("press 1 : to Name\n");
        printf("press 2 : to Dept\n");
        printf("press 3 : to Sem\n");
        printf("press 4 : to SPI\n");
        scanf("%d", &p);
        switch (o)
        {

        case 1:
            // again:

            switch (p)
            {
            case 1:
                printf("Enter new name : ");
                scanf("%s", &s[0].name);
                printf("Edit succesful!!!");
                break;
            case 2:
                printf("Enter new dept : ");
                scanf("%s", &s[0].dept);
                printf("Edit succesful!!!");
                break;
            case 3:
                printf("Enter new sem : ");
                scanf("%d", &s[0].sem);
                printf("Edit succesful!!!");
                break;
            case 4:
                printf("Enter new SPI : ");
                scanf("%f", &s[0].spi);
                printf("Edit succesful!!!");
                break;

            default:
                break;
            }
            // char ch;
            // printf("want to edit more or again details of this student [y/n] : ");
            // scanf("%c", &ch);
            // if (ch == 'y')
            // {
            //     goto again;
            // }

            break;
        case 2:

            switch (p)
            {
            case 1:
                printf("Enter new name : ");
                scanf("%s", &s[1].name);
                printf("Edit succesful!!!");
                break;
            case 2:
                printf("Enter new dept : ");
                scanf("%s", &s[1].dept);
                printf("Edit succesful!!!");
                break;
            case 3:
                printf("Enter new sem : ");
                scanf("%d", &s[1].sem);
                printf("Edit succesful!!!");
                break;
            case 4:
                printf("Enter new SPI : ");
                scanf("%f", &s[1].spi);
                printf("Edit succesful!!!");
                break;

            default:
                break;
            }

            break;
        case 3:

            switch (p)
            {
            case 1:
                printf("Enter new name : ");
                scanf("%s", &s[2].name);
                printf("Edit succesful!!!");
                break;
            case 2:
                printf("Enter new dept : ");
                scanf("%s", &s[2].dept);
                printf("Edit succesful!!!");
                break;
            case 3:
                printf("Enter new sem : ");
                scanf("%d", &s[2].sem);
                printf("Edit succesful!!!");
                break;
            case 4:
                printf("Enter new SPI : ");
                scanf("%f", &s[2].spi);
                printf("Edit succesful!!!");
                break;

            default:
                break;
            }

            break;
        case 4:

            switch (p)
            {
            case 1:
                printf("Enter new name : ");
                scanf("%s", &s[3].name);
                printf("Edit succesful!!!");
                break;
            case 2:
                printf("Enter new dept : ");
                scanf("%s", &s[3].dept);
                printf("Edit succesful!!!");
                break;
            case 3:
                printf("Enter new sem : ");
                scanf("%d", &s[3].sem);
                printf("Edit succesful!!!");
                break;
            case 4:
                printf("Enter new SPI : ");
                scanf("%f", &s[3].spi);
                printf("Edit succesful!!!");
                break;

            default:
                break;
            }

            break;
        case 5:

            switch (p)
            {
            case 1:
                printf("Enter new name : ");
                scanf("%s", &s[4].name);
                printf("Edit succesful!!!");
                break;
            case 2:
                printf("Enter new dept : ");
                scanf("%s", &s[4].dept);
                printf("Edit succesful!!!");
                break;
            case 3:
                printf("Enter new sem : ");
                scanf("%d", &s[4].sem);
                printf("Edit succesful!!!");
                break;
            case 4:
                printf("Enter new SPI : ");
                scanf("%f", &s[4].spi);
                printf("Edit succesful!!!");
                break;

            default:
                break;
            }

            break;

        default:
            break;
        }

        break;

    default:
        break;
    }

    fclose(fp);

    // for (int i = 0; i < 2; i++)
    // {
    //     printf(" name of student %d is : %s\n", i + 1, s[i].name);
    //     printf(" dept of student %d is : %s\n", i + 1, s[i].dept);
    //     printf(" sem of student %d is : %d\n", i + 1, s[i].sem);
    //     printf(" SPI of student %d is : %f\n", i + 1, s[i].spi);
    //     printf("\n");
    // }

    return 0;
}