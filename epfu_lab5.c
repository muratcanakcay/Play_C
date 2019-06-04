#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if (argc > 3)
    {
        int seed;
        int min, max, size, row_temp, col_temp, row_max, col_max, row_result, col_result;
        time_t tt;

        seed = time(&tt);
        srand(seed);

        size = atoi(argv[1]);
        min = atoi(argv[2]);
        max = atoi(argv[3]);

        int matrix[size][size];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix[i][j] = min + rand()%(max-min+1);

        printf("The matrix with random numbers that were generated is:\n");

        for (int i = 0; i < size; i++)
            {
            for (int j = 0; j < size; j++)
                printf("%d  ", matrix[i][j]);
            printf("\n");
            }


        row_temp = row_max = row_result = 0;
        col_temp = col_max = col_result = 0;

        for (int i = 0; i < size; i++)
            {
            row_temp = col_temp = 0;
            for (int j = 0; j < size; j++)
                {
                row_temp += matrix[i][j];
                col_temp += matrix[j][i];
                }

            if (row_temp > row_max)
                {
                    row_max = row_temp;
                    row_result = i;
                }
            if (col_temp > col_max)
                {
                    col_max = col_temp;
                    col_result = i;
                }

            printf("%d row sum is %d max is %d\n", i+1, row_temp, row_max);
            printf("%d col sum is %d max is %d\n", i+1, col_temp, col_max);
            }


        printf("\n%d %d\n", row_result+1, col_result+1);

        return 1;
    }

    else
    {
        printf("You have to enter three arguments for the program to work.");
        return 0;
    }
}
