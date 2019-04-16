#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(int argc, char* argv[])
{
    if (argc == 3)
    {
        int i, j, n;
        long fact = 1, factn = 1, fact2n = 1;
        float x, y, sum = 0;
        x = atof(argv[1]);
        n = atoi(argv[2]);

        printf("x is %.2f\n", x);
        printf("n is %d\n\n\n", n);

        // e^x - for all x
        sum = 1; // n = 0 case, i.e. first term of the series
        printf("The Taylor series expansion of e^x around x = %.2f for %d terms is = (%.2f)", x, n, sum);
        for (i=1; i<n; i++)
        {
            fact = fact * i;
            float next_term = (pow(x, i)/fact);
            printf(" + (%f)", next_term);
            sum += next_term;
        }
        printf(" = %.2f\n\n",sum);

        // ln(x) 0<x2
        y = 1-x; //substitute in the Taylor series
        sum = 0; // no need to set n = 0 case, i.e. first term of the series
        printf("The Taylor series expansion of ln(x) around x = %.2f for %d terms is = ", x, n);
        for (i=1; i<n+1; i++) //i counts to n+1 because first term was not set
        {
            float next_term = -(pow(y, i)/i);
            printf(" + (%f)", next_term);
            sum += next_term;
        }
        printf(" = %.2f\n\n",sum);


        // sin(x) any x
        sum = x; // n = 0 case, i.e. first term of the series
        printf("The Taylor series expansion of sin(x) around x = %.2f for %d terms is = (%.2f)", x, n, sum);
        for (i=1; i<n; i++)
        {
            fact = 1; // reset fact variable
            for (j = 1; j < 2*i+2; j++)
                fact = fact * j;
            // printf("%d! is %ld\n", 2*i+1, fact);
            float next_term = (pow(-1, i) * pow(x, 2*i+1)) / fact;
            printf(" + (%f)", next_term);
            sum += next_term;
        }
        printf(" = %.2f\n\n",sum);



        // cos(x) any x
        sum = 1; // n = 0 case, i.e. first term of the series
        printf("The Taylor series expansion of cos(x) around x = %.2f for %d terms is = (%.2f)", x, n, sum);
        for (i = 1; i < n; i++)
        {
            fact = 1; // reset fact variable
            for (j = 1; j < 2*i +1; j++)
                fact *= j;
            // printf("%d! is %ld\n", 2*i, fact);
            float next_term = (pow(-1, i) * pow(x, 2*i)) / fact;
            printf(" + (%f)", next_term);
            sum += next_term;
        }
        printf(" = %.2f\n\n",sum);

        //arcsin(x) -1 <= x <= 1
        sum = x; // // n = 0 case, i.e. first term of the series
        printf("The Taylor series expansion of arsin(x) around x = %.2f for %d terms is = (%.2f)", x, n, sum);
        for (i = 1; i < n; i++)
        {
            factn = fact2n = 1; // reset fact variables
            for (j = 1; j < 2*i+1; j++)
                {
                    fact2n *= j;
                    if (j==i) factn = fact2n;
                }
            // printf("n!=%d! is %ld\n", i, factn);
            // printf("2n!=%d! is %ld\n\n", 2*i, fact2n);
            float next_term = (fact2n * pow(x, 2*i+1)) / (pow(4, i) * pow(factn,2) * (2*i+1));
            printf(" + (%f)", next_term);
            sum += next_term;
        }
        printf(" = %.2f\n\n",sum);

        //arccos(x) -1 <= x <= 1
        sum = x; // n = 0 case, i.e. first term of the series
        printf("The Taylor series expansion of arccos(x) around x = %.2f for %d terms is = PI/2 - [(%.2f)", x, n, sum);
        for (i = 1; i < n; i++)
        {
            factn = fact2n = 1; // reset fact variables
            for (j = 1; j < 2*i+1; j++)
                {
                    fact2n *= j;
                    if (j==i) factn = fact2n;
                }
            // printf("n!=%d! is %ld\n", i, factn);
            // printf("2n!=%d! is %ld\n\n", 2*i, fact2n);
            float next_term = (fact2n * pow(x, 2*i+1)) / (pow(4, i) * pow(factn,2) * (2*i+1));
            printf(" + (%f)", next_term);
            sum += next_term;
        }
        printf("] = %.2f\n\n", 1.57 - sum);

        // arctan(x) 1 <= x <= 1
        sum = x; // n = 0 case, i.e. first term of the series
        printf("The Taylor series expansion of arctan(x) around x = %.2f for %d terms is = (%.2f)", x, n, sum);
        for (i = 1; i < n; i++)
        {
            float next_term = (pow(-1, i) * pow(x, 2*i +1)) / (2*i +1);
            printf(" + %f", next_term);
            sum += next_term;
        }
        printf(" = %.2f\n\n", sum);


        //arcsinh(x) -1 <= x <= 1
        sum = x; // // n = 0 case, i.e. first term of the series
        printf("The Taylor series expansion of arsinh(x) around x = %.2f for %d terms is = (%.2f) + ", x, n, sum);
        for (i = 1; i < n; i++)
        {
            factn = fact2n = 1; // reset fact variables
            for (j = 1; j < 2*i+1; j++)
                {
                    fact2n *= j;
                    if (j==i) factn = fact2n;
                }
            // printf("n!=%d! is %ld\n", i, factn);
            // printf("2n!=%d! is %ld\n\n", 2*i, fact2n);
            float next_term = (pow(-1, i) * fact2n * pow(x, 2*i+1)) / (pow(4, i) * pow(factn,2) * (2*i+1));
            printf("(%f) + ", next_term);
            sum += next_term;
        }
        printf("= %.2f\n\n",sum);
    }
}








// #include<stdio.h>
//
// #include<math.h>
//
// int main()
// {
//     printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
//
//     int x,i;
//     int fact = 1,n;
//     float sum=0;
//
//     printf("\n\nEnter the value of x in the series :  ");
//     scanf("%d",&x);
//
//     printf("\nEnter the number of terms in the series  :   ");
//     scanf("%d",&n);
//
//     for(i=1;i<n;i++)
//     {
//         fact = fact*i;
//         sum = sum + (pow(x,i)/fact) ;
//
//     }
//     sum= sum +1; //Since series starts with 1
//
//     printf("\n\nThe sum of the taylor series is :  %.2f\n\n",sum);
//
//     printf("\n\n\n\n\t\t\tCoding is Fun !\n\n\n");
//     return 0;
// }
