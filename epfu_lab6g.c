#include <stdio.h>
#include <stdlib.h>


void det(int matrix[3][3], int size);

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        int size, temp;

        size = atoi(argv[1]);

        if (size>3 || size<1)
        {
            printf("The matrix size must be between 1 and 3!!!!!\n");
            exit(0);
        }

        int matrix[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                *((*(matrix+i))+j) = 0;

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                printf("Enter the number for matrix position row:%d column:%d:\n", i+1, j+1);
                scanf("%d", &temp);
                *((*(matrix+i))+j) = temp;
            }

        printf("The matrix is:\n");

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                printf("%d  ", *((*(matrix+i))+j));
            printf("\n");
        }

        // printf("\n%d  ", **matrix);
        // printf("\n%d  ", *((*matrix)+1));
        // printf("\n%d  ", *(*(matrix+1)));
        // printf("\n%d  ", *((*(matrix+1))+1));

        det(matrix, size);



        return 1;
    }

    else
    {
        printf("You have to enter one argument for the program to work.");
        return 0;
    }
}


void det(int matrix[3][3], int size)
{
    int determinant;

    if (size == 1)
        determinant = *(*matrix);

    if (size == 2)
    {
        determinant = ((*(*matrix + 0) + 0) * (*(*(matrix + 1) + 1))) - ((*(*(matrix + 1) + 0)) * (*(*(matrix + 0 ) + 1)));
    }

    if (size == 3)
    {
        int determinant = (*((*(matrix+0))+0)) * (((*((*(matrix+1))+1)) * (*((*(matrix+2))+2))) - ((*((*(matrix+2))+1))*(*((*(matrix+1))+2)))) -(*((*(matrix+0))+1)) * ((*((*(matrix+1))+0)) * (*((*(matrix+2))+2)) - (*((*(matrix+2))+0)) * (*((*(matrix+1))+2))) + (*((*(matrix+0))+2)) * ((*((*(matrix+1))+0)) * (*((*(matrix+2))+1)) - (*((*(matrix+2))+0)) * (*((*(matrix+1))+1)));
    }

    printf("determinant is %d\n", determinant);
}
