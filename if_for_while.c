#include <stdio.h>
int main()
{
  int int1, int2, int3;
  printf("Please enter two numbers\n");
  scanf("%d %d", &int1, &int2);
  if(int1<int2) printf("%d is larger than %d\n", int2, int1);
  else
    if (int1>int2) printf("%d is larger than %d\n", int1, int2);
  else
    printf("The numbers are equal\n");
  printf("\n");

  printf("How many numbers do you want to print?\n");
  scanf("%d", &int1);
  printf("The numbers are\n");
  for(int2=0; int2<int1; int2++)
    {
    printf("%d\n", int2+1);
    }
  printf("\n");

  int1=1;
  int2=2;
  int3=3;
  while((int1==0&&int2==0)||int1!=int2||int3!=0)
    {
    printf("Conditions not satisfied enter new numbers\n");
    scanf("%d %d %d", &int1, &int2, &int3);
    }
  printf("Conditions are  satisfied! Well done!\n");





  printf("\n");
  printf("You are ready to ROCK AND ROLL.\n");
  printf("Well done, sir. We're going to CRUSH this course.\n");
  printf("OH YES! :)\n");
  return 0;
}
