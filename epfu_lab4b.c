#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_numbers(int numbers[30], int min, int max);
void print_numbers(int numbers[30]);
void print_numbers_backwards(int numbers[30]);
void print_differences(int numbers[30]);
void min_max_mean(int numbers[30]);
void bubble_sort(int numbers[30]);

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        int seed;
        int min, max, mean;
        time_t tt;
        int numbers[30];

        seed = time(&tt);
        srand(seed);

        min = atoi(argv[1]);
        max = atoi(argv[2]);

        fill_numbers(numbers, min, max);
        printf("The random numbers that were generated are:\n");
        print_numbers(numbers);
        print_differences(numbers);
        min_max_mean(numbers);
        bubble_sort(numbers);
        printf("Sorted numbers are:\n");
        print_numbers_backwards(numbers);

        return 1;
    }

    else
    {
        printf("You have to enter at least to arguments for the minimum and max values");
        return 0;
    }
}


void print_differences(int numbers[30])
{
    printf("The differences between the numbers are:\n");
    for (int i = 0; i < 29; i++)
    {
        int diff =  numbers[i] - numbers[i+1];
        if (diff < 0) diff *= -1;
        printf ("%d ", diff);
    }
    printf("\n");
}


void min_max_mean(int numbers[30])
{
    int min = numbers[0];
    int max = numbers[0];
    int mean = 0;
    int sum = 0;
    for (int i = 0; i < 30; i++)
    {
        if (numbers[i] < min) min = numbers[i];
        if (numbers[i] > max) max = numbers[i];
        sum += numbers[i];
    }
    mean = sum / 30;
    printf("Max value is: %d\n", max);
    printf("Min value is: %d\n", min);
    printf("Mean value is: %d\n", mean);
}

void fill_numbers(int numbers[30], int min, int max)
{
    for (int i = 0; i < 30; i++)
        numbers[i] = min + rand()%(max-min+1);
}

void print_numbers(int numbers[30])
{
    for (int i = 0; i < 30; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}

void print_numbers_backwards(int numbers[30])
{
    for (int i = 29; i >= 0; i--)
        printf("%d ", numbers[i]);
    printf("\n");
}

void bubble_sort(int numbers[30])
{
    for (int i = 0; i < 29; i++)
    {
        for (int j = 0; j < 29 - i; j++)
            if (numbers[j] > numbers[j+1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
    }
}
