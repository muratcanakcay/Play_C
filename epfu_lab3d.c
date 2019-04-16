#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long factorial(int);
float sin_function(float, int);
float error_value(float, int);

void main (int argc, char * argv[])
{
	if (argc == 3)
	{
		float x = atof(argv[1]);
		int N = atoi(argv[2]);
		printf("\nThe numbers you have entered are x=%f and N=%d\n", x, N);
		printf("The value of sin(%f) calculated by built-in function is = %e\n", x, sin(x));
		printf("The value of sin(%f) calculated by approximation is = %e\n", x, sin_function(x, N));
		printf("The value of error for sin(%f) calculated by approximation is = %e\n", x, error_value(x, N));
		printf("\n");
	}

	else
		printf("You must enter two valuesas arguments for this program to work. The first value is the x value and the second value is the N value. Thank you.");
}

float sin_function(float x, int N)
{
	int i;
	float next_term=0, sum = x; // initialize the first value of the Taylor series and the next term.

for (i = 1; i < N; i++)
	{
		float a = pow(-1, i);
		float b = pow(x, 2 * i + 1);
		float c = factorial(2 * i + 1);
		next_term = (a * b)/c;
		sum += next_term;
	}
}

float error_value(float x, int N)
{
	float value;
	value = sin(x) - sin_function(x, N);
	if (value < 0) value = -value;
	return value;
}

long factorial(int i)
{
	int k;
	long fact = 1;
	for(k = 1; k < i+1; k++)
		fact *= k;
	return fact;
}
