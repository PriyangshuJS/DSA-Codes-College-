#include <stdio.h>

int main()
{

    // creating a FILE variable
    FILE *fptr;

    // integer variable
    int num;

    // open the file in write mode
    fptr = fopen("integers.txt", "w");

    if (fptr != NULL)
    {
        printf("File created successfully!\n");
    }
    else
    {
        printf("Failed to create the file.\n");
        // exit status for OS that an error occurred
        return -1;
    }

    // enter integer numbers
    printf("Enter some integer numbers [Enter -1 to exit]: ");
    while (1)
    {
        scanf("%d", &num);
        if (num != -1)
        {
            fputw(num, fptr);
        }
        else
        {
            break;
        }
    }

    // close connection
    fclose(fptr);

    // open file for reading
    fptr = fopen("integers.txt", "r");

    // display numbers
    printf("\nNumbers:\n");
    while ((num = getw(fptr)) != EOF)
    {
        printf("%d\n", num);
    }

    printf("\nEnd of file.\n");

    // close connection
    fclose(fptr);
}