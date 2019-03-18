#include <stdio.h>
int main()
{
  printf("Muratcan Akçay\n");
  int int1, int2;
  float flt1, flt2;
  char chr1, chr2;
  printf("Please enter two integers:\n");
  scanf("%d %d", &int1, &int2);
  printf("Please enter two floats:\n");
  scanf("%f %f", &flt1, &flt2);
  printf("Please enter two characters:\n");
  scanf(" %c %c", &chr1, &chr2);
  printf("The integers numbers displayed as integers are %d and %d\n", int1, int2);
  printf("The floats displayed as integers are %d and %d\n", (int)flt1, (int)flt2);
  printf("The floats displayed as floats are %f and %f\n", flt1, flt2);
  printf("The characters displayed as characters are %c and %c\n", chr1, chr2);
  printf("The characters displayed as integers are %d and %d\n", (int)chr1, (int)chr2);
  printf("\n");
  printf("The two integers added is: %d + %d = %d\n", int1, int2, int1+int2);
  printf("The two integers divided is: %d / %d = %d\n", int1, int2, int1/int2);
  printf("The two floats divided is: %f / %f = %f\n", flt1, flt2, flt1/flt2);
  printf("The first integer added to the first charcter is %d + %c = %d as an integer and %c as a character\n", int1, chr1, int1+chr1, int1+chr1);
  printf("\n");
  printf("You are ready to ROCK AND ROLL.\n");
  printf("Well done, sir. We're going to CRUSH this course.\n");
  printf("OH YES! :)\n");
  return 0;
}
