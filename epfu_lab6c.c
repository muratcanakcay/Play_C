#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        int k, temp;
        k = 0;

        char* words = argv[1];

        // if (size>3 || size<1)
        // {
        //     printf("The matrix size must be between 1 and 3!!!!!\n");
        //     exit(0);
        // }

        char* A[4][10];

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 10; j++)
            {
                *((*(A+i))+j) = argv[(3*i)+j];
            }

        printf("The matrix is:\n");

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 10; j++)
                while (*((*((*(A+i))+j))+k) != '\0')
                {
                    printf("%s  ", *((*(A+i))+j));
                    k++;
                }

            printf("\n");
        }

        // printf("\n%d  ", **matrix);
        // printf("\n%d  ", *((*matrix)+1));
        // printf("\n%d  ", *(*(matrix+1)));
        // printf("\n%d  ", *((*(matrix+1))+1));

        // printf("\n\nThe determinant of the matrix is: %d\n", det(matrix, size));


        return 1;
    }

    else
    {
        printf("You have to enter one argument for the program to work.");
        return 0;
    }
}
