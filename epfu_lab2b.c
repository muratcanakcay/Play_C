#include <stdio.h>
#include <stdlib.h>
int factorial_recursive(int);
int factorial_iterative(int);


int main(int argc, char *argv[])
{
	if (argc!=2) printf("This program calculates all of the factorials up to a number you enter. Please enter ONE number after ./a.out to calculate the factorials or the program won`t work. Thank you for your cooperation. Do widzenia.\n");
	int N;
	N = atoi(argv[1]);
	printf("\n");
	printf("The number you have entered is %d: \n", N);
	printf("\n");
	printf("Recursive: The first %d numbers for %d! are: \n", N, N);
	factorial_recursive(N);
	printf("\n");
	printf("Iterative: The first %d numbers for %d! are: \n", N, N);
	factorial_iterative(N);
	printf("\n");
	return 0;
}

int factorial_recursive(int N)
{
	if (N==0)
	{
		printf("0! = 1\n");
		return 1;
	}
	else
	{
		int k = N*factorial_recursive(N-1);
		printf("%d! = %d \n", N, k);
		return k;
	}
}

int factorial_iterative(int N)
{
	for(int i=0; i < N+1; i++)
	{
		int k = 1;
		for (int j=0; j<i; j++)
		{
			k *= j+1;
		}
	printf ("%d! = %d\n", i, k);
	}
}
