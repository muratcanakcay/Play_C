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
void polar_form(Complex n1);
void print_complex(Complex n1);


void main ()
{
	Complex result;

	Complex n1 = init();
	polar_form(n1);

	Complex n2 = init();
	polar_form(n2);

	result = add(n1, n2);
	printf("\nThe sum of the two numbers is: ");
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
}

Complex init(void)
{
	Complex temp = {0, 0};
	printf("\nEnter the real part of the number: \n");
	while (scanf("%d", &(temp.real)) == 0)
    	while (getchar() != '\n')
      				;

	printf("Enter the imaginary part of the number: \n");
	while (scanf("%d", &(temp.imag)) == 0)
    	while (getchar() != '\n')
      				;
	printf("\nThe number is: ");
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
    printf("%d + %di\n", n1.real, n1.imag);
}

void polar_form(Complex n1)
{
	float abs_z = sqrt(n1.real*n1.real + n1.imag*n1.imag);
	// double theta = asin(n1.real/abs_z);
	double theta = atan2(n1.imag, n1.real);

	printf("The number in polar form is: %.2f (cos(%.2lf)+i sin(%.2lf)\n", abs_z, theta, theta);
}
