#include <stdio.h>

struct student
{
    char name[20];
    char dept[50];
      int enroll;
    int sem;
    float spi;
};

void display(struct student s[])
{
    printf("====================================================\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Name : %s\n", s[i].name);
    //     printf("Department : %s\n", s[i].dept);
    //     printf("Enrollment : %d\n", s[i].enroll);
    //     printf("Semster : %d\n", s[i].sem);
    //     printf("SPI : %.2f\n\n", s[i].spi);
    // }

    FILE *fp;
    fp = fopen("std_data.txt", "r");
    int i = 0;
    while (fread(&s[i], sizeof(struct student), 1, fp))
    {
        printf("Name : %s\nDepartment : %s\nEnrollment : %d\nSemster : %d\nSPI : %.2f\n\n", s[i].name, s[i].dept, s[i].enroll, s[i].sem, s[i].spi);
        i++;
    }
    fclose(fp);
}

void search(struct student s[])
{
    printf("====================================================\n");

    FILE *fp;
    fp = fopen("std_data.txt", "r");
      int enroll;
    printf("Enter Enrollment number to search: ");
    scanf("%d", &enroll);
    printf("\n");
    int i = 0;
    while (fread(&s[i], sizeof(struct student), 1, fp))
    {
        if (s[i].enroll == enroll)
        {
            printf("Name : %s\nDepartment : %s\nEnrollment : %d\nSemster : %d\nSPI : %.2f\n\n", s[i].name, s[i].dept, s[i].enroll, s[i].sem, s[i].spi);
            i++;
        }
        else
        {
            printf("details not found!!!\n");
        }
    }
    fclose(fp);
}

void sort_s(struct student s[], struct student temp, int n)
{
    printf("====================================================\n");

    FILE *fp;
    fp = fopen("std_data.txt", "r");

    for (int i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(struct student), 1, fp);
    }
    fclose(fp);
    // printf("Name : %s\nDepartment : %s\nEnrollment : %d\nSemster : %d\nSPI : %.2f\n\n", s[i].name, s[i].dept, s[i].enroll, s[i].sem, s[i].spi);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[j].spi > s[i].spi)
            {
                // float temp = s[j].spi;
                // s[j].spi = s[i].spi;
                // s[i].spi = temp;
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
        }
    }
    // fclose(fp);
    fp = fopen("std_data.txt", "w");
    for (int i = 0; i < n; i++)
    {
        printf("Name : %s\nDepartment : %s\nEnrollment : %d\nSemster : %d\nSPI : %.2f\n\n", s[i].name, s[i].dept, s[i].enroll, s[i].sem, s[i].spi);
        fwrite(&s[i], sizeof(struct student), 1, fp);
    }
    fclose(fp);
}

void edit(struct student s[])
{
    printf("====================================================\n");

    FILE *fp, *fp1;
    fp = fopen("std_data.txt", "r");
    fp1 = fopen("temp.txt", "w");

    int enroll;
    printf("Enter Enrollment number to edit: ");
    scanf("%d", &enroll);
    printf("\n");
    int i = 0;
    while (fread(&s[i], sizeof(struct student), 1, fp))
    {
        if (s[i].enroll == enroll)
        {
            // printf("Name : %s\nDepartment : %s\nEnrollment : %d\nSemster : %d\nSPI : %.2f\n\n", s[i].name, s[i].dept, s[i].enroll, s[i].sem, s[i].spi);
            printf("\nEnter new name : ");
            scanf("%s", &s[i].name);
            printf("Enter new department : ");
            scanf("%s", &s[i].dept);
            printf("Enter new Enrollment : ");
            scanf("%d", &s[i].enroll);
            printf("Enter new semester : ");
            scanf("%d", &s[i].sem);
            printf("Enter new SPI : ");
            scanf("%f", &s[i].spi);
        }
        else
        {
            printf("details not found!!!\n");
        }
        fwrite(&s[i], sizeof(struct student), 1, fp1);
        i++;
    }
    fclose(fp);
    fclose(fp1);

    i = 0;
    fp1 = fopen("temp.txt", "r");
    fp = fopen("std_data.txt", "w");
    while (fread(&s[i], sizeof(struct student), 1, fp1))
    {
        fwrite(&s[i], sizeof(struct student), 1, fp);
        i++;
    }
    fclose(fp);
    fclose(fp1);
}

void delete(struct student s[])
{
    printf("====================================================\n");

    FILE *fp, *fp1;
    fp = fopen("std_data.txt", "r");
    fp1 = fopen("temp.txt", "w");

    int enroll;
    printf("Enter Enrollment number to delete: ");
    scanf("%d", &enroll);
    printf("\n");
    int i = 0;
    while (fread(&s[i], sizeof(struct student), 1, fp))
    {
        if (s[i].enroll == enroll)
        {
            // printf("Name : %s\nDepartment : %s\nEnrollment : %d\nSemster : %d\nSPI : %.2f\n\n", s[i].name, s[i].dept, s[i].enroll, s[i].sem, s[i].spi);
        }
        else
        {
            fwrite(&s[i], sizeof(struct student), 1, fp1);
        }
        i++;
    }
    fclose(fp);
    fclose(fp1);

    i = 0;
    fp1 = fopen("temp.txt", "r");
    fp = fopen("std_data.txt", "w");
    while (fread(&s[i], sizeof(struct student), 1, fp1))
    {
        fwrite(&s[i], sizeof(struct student), 1, fp);
        i++;
    }
    fclose(fp);
    fclose(fp1);
}

int main()
{
    int n;
    printf("\nEnter the number of students : ");
    scanf("%d", &n);
    printf("\n");
    struct student s[n], temp;
    FILE *fp = NULL;
    fp = fopen("std_data.txt", "w");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of student %d : ", i + 1);
        scanf("%s", &s[i].name);
        printf("Enter the department of student %d : ", i + 1);
        scanf("%s", &s[i].dept);
        printf("Enter the Enrollment of student %d : ", i + 1);
        scanf("%d", &s[i].enroll);
        printf("Enter the semester of student %d : ", i + 1);
        scanf("%d", &s[i].sem);
        printf("Enter the SPI of student %d : ", i + 1);
        scanf("%f", &s[i].spi);
        printf("\n");
        // fprintf(fp, "name of student %d : %s \ndepartment of student %d : %s \nEnrollment of student %d : %d \nsemester of student %d : %d \nSPI of student %d : %.2f \n\n", i + 1, s[i].name, i + 1, s[i].dept, i + 1, s[i].enroll, i + 1, s[i].sem, i + 1, s[i].spi);
        fwrite(&s[i], sizeof(struct student), 1, fp);
    }
    fclose(fp);
    int n_exit;
    do
    {
        printf("====================================================\n");
        printf("Enter 1 : to Display students list\n");
        printf("Enter 2 : to Search a student\n");
        printf("Enter 3 : to Sort student with respect to SPI\n");
        printf("Enter 4 : to Edit the details of any students\n");
        printf("Enter 5 : to Delete the details of any student\n");
        printf("Enter 6 : to Exit\n\n");

        printf("Enter : ");
        scanf("%d", &n_exit);
        printf("\n");

        switch (n_exit)
        {
        case 1:

            display(s);

            break;
        case 2:

            // int enrollment;
            // printf("Enter enrollment number : ");
            // scanf("%d", &enrollment);
            // for (int i = 0; i < n; i++)
            // {
            //     if (s[i].enroll == enrollment)
            //     {
            //         printf("\nName : %s\n", s[i].name);
            //         printf("Department : %s\n", s[i].dept);
            //         printf("Enrollment : %d\n", s[i].enroll);
            //         printf("Semster : %d\n", s[i].sem);
            //         printf("SPI : %.2f\n\n", s[i].spi);
            //     }
            // }
            search(s);
            break;
        case 3:
            // printf("====================================================\n");
            // for (int i = 0; i < n - 1; i++)
            // {
            //     for (int j = i + 1; j < n; j++)
            //     {
            //         if (s[j].spi > s[i].spi)
            //         {
            //             int temp = s[j].spi;
            //             s[j].spi = s[i].spi;
            //             s[i].spi = temp;
            //         }
            //     }
            // }
            // for (int i = 0; i < 5; i++)
            // {
            //     printf("Name : %s ,SPI : %.3f\n", s[i].name, s[i].spi);
            // }
            sort_s(s, temp, n);

            break;
        case 4:
            edit(s);
            break;
        case 5:
            delete (s);
            break;

        default:
            // printf("Invalid Case!!!\n");
            break;
        }

    } while (n_exit != 6);
    printf("Thank you");

    return 0;
}