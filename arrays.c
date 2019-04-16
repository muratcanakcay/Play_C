#include <stdio.h>
#include <stdlib.h>


void print_table(int rows, int columns, int array[rows][columns]);

int main(int argc, char *argv[])
{
    if(argc==4)
    {
        int value = 0;
        int rows = atoi(argv[2]);
        int columns = atoi(argv[3]);
        int a[rows][columns];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
            value += atoi(argv[1]);
            a[i][j] = value;
            printf("The value %d is entered into box %d %d\n", a[i][j], i+1, j+1);
            }
        }

        printf("\nThis is the for-loop printing the table.\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
            printf("%d   ", a[i][j]);
            }
        printf("\n");
        }
        print_table(rows, columns, a);
        printf("\nThe final value is %d\n", value);

    }
    else
    {
        printf("You must enter three arguments!\nThe first argument is the value to be used.\nThe second argument is the number of rows.\nThe third argument is the number of columns.\n");
    }
}

void print_table(int rows, int columns, int array[rows][columns])
{
    printf("\nThis is the function printing the table.\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
        int result = array[i][j];
        printf("%d  ", result);
        }
        printf("\n");
    }
}
