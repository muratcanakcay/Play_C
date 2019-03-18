#include <stdio.h>

int i;
long int factorial(int);

int main()
{
   printf("Please enter the factorial to be calculated: ");
   scanf("%d", &i);
   printf("Factorial of %d is %ld\n", i, factorial(i));

   printf("\n");
   printf("You are ready to ROCK AND ROLL.\n");
   printf("Well done, sir. We're going to CRUSH this course.\n");
   printf("OH YES! :)\n");
   return 0;
}

long int factorial(int i)
{
   if(i <= 1)
      return 1;
   return i * factorial(i - 1);
}
