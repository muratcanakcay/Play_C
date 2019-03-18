#include <stdio.h>

int i, k;
int fibonacci(int);

int main()
{
   printf("Please enter the number of steps to be calculated for the fibonacci seris: ");
   scanf("%d", &i);
   printf("The fibonacci series up to step %d is:\n", i);
   for(k=0; k<i; k++)
      printf("%d ", fibonacci(k+1));

   printf("\n");
   printf("You are ready to ROCK AND ROLL.\n");
   printf("Well done, sir. We're going to CRUSH this course.\n");
   printf("OH YES! :)\n");
   return 0;
}

int fibonacci (int i)
{
   if (i == 1 || i == 2) return 1;
   return fibonacci(i - 1) + fibonacci(i - 2);
}
