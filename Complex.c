#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int real;
	int imag;
} Complex;

Complex init(void);
Complex add(Complex n1, Complex n2);
Complex subtract(Complex n1, Complex n2);
Complex divide(Complex n1, Complex n2);
Complex multiply(Complex n1, Complex n2);
void print_complex(Complex n1);
int ComplexCmp(Complex n1, Complex n2);

void main ()
{
	Complex result; // result variable declaration

	// ask user for 2 vectors

	Complex n1 = init();
	Complex n2 = init();

	result = add(n1, n2);
	printf("The sum of the two numbers is: ");
	print_complex(result);

	result = subtract(n1, n2);
	printf("The difference of the two numbers is: ");
	print_complex(result);

	result = divide(n1, n2);
	printf("The ratio of the two numbers is: ");
	print_complex(result);

	result = multiply(n1, n2);
	printf("The product of the two numbers is: ");
	print_complex(result);

	int comparison = ComplexCmp(n1, n2);
	printf("The comparison of the two numbers is: %d\n", comparison);



}

Complex init(void)
{
	Complex temp = {0, 0};
	printf("Enter the real part of the number: \n");
	scanf("%d", &(temp.real));
	printf("Enter the real part of the number: \n");
	scanf("%d", &(temp.imag));
	printf("The number is: ");
	print_complex(temp);

	return temp;
}
Complex add(Complex n1, Complex n2)
{
	Complex temp = {n1.real + n2.real, n1.imag + n2. imag};
	return temp;
}

Complex subtract(Complex n1, Complex n2)
{
    Complex temp = {n1.real - n2.real, n1.imag - n2. imag};
	return temp;
}


Complex divide(Complex n1, Complex n2)
{
    int x = n1.real*n2.real + n1.imag*n2.imag;
    int y = n1.imag*n2.real - n1.real*n2.imag;
    int z = n2.real*n2.real + n2.imag*n2.imag;
    Complex temp = {x/z, y/z};

    return temp;
}

Complex multiply(Complex n1, Complex n2)
{
    int x = n1.real*n2.real - n1.imag*n2.imag;
    int y = n1.imag*n2.real + n1.real*n2.imag;
    Complex temp = {x, y};

    return temp;
}

void print_complex(Complex n1)
{
    printf("The number is %d + %di\n", n1.real, n1.imag);
}

int ComplexCmp(Complex n1, Complex n2)
{
	float abs_n1 = sqrt((n1.real * n1.real) + (n1.real * n1.real));
	float abs_n2 = sqrt((n2.real * n2.real) + (n2.real * n2.real));
	printf("The absolute value of 1st number is %f\n", abs_n1);
	printf("The absolute value of 1st number is %f\n", abs_n2);

	if (abs_n1 == abs_n2)
	{
		if (n1.real < n2.real) return -1;
		if (n1.real > n2.real) return 1;
		return 0;
	}

	if (abs_n1 < abs_n2) return -2;
	if (abs_n1 > abs_n2) return 2;
}
