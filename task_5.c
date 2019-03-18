#include <stdio.h>

int i1, i2, i3, h, n;
float f1, f2;
char c;

void check_negative(int);
float arithmetic_mean(float, float);
void pyramid(int, int, char);
void minmax(int, int, int);

int main(){
  printf("Please enter the number to be checked: ");
  scanf("%d", &i1);
  check_negative(i1);
  printf("\n");

  printf("Please enter two numbers to calculate the arithmetic mean of: ");
  scanf("%f %f", &f1, &f2);
  printf("The arithmetic mean of %f and %f is %f.\n", f1, f2, arithmetic_mean(f1, f2));
  printf("\n");

  printf("Enter the spaces, no. of lines and the starting character: ");
  scanf("%d %d %c", &h, &n, &c);
  pyramid(h, n, c);
  printf("\n");

  printf("Enter three numbers to find the min and max: ");
  scanf("%d %d %d", &i1, &i2, &i3);
  minmax(i1, i2, i3);
  printf("\n");

  printf("You are ready to ROCK AND ROLL.\n");
  printf("Well done, sir. We're going to CRUSH this course.\n");
  printf("OH YES! :)\n");
  return 0;
}

void minmax(int i1, int i2, int i3){
  int min, max;
  if (i1 <= i2){
    if (i2 <= i3){
      min = i1;
      max = i3;
    }
    else{
      if (i1 <= i3){
      min = i1;
      max = i2;
    }
      else {
        min = i3;
        max = i2;
      }
    }
  }
  else{
    if (i3 <= i2){
      min = i3;
      max = i1;
    }
    else{
      if (i3 <= i1){
        min = i2;
        max = i1;
      }
      else {
        min = i2;
        max = i3;
      }
    }
  }
printf("The minimum of the three numbers is %d, and the maximum is %d.\n", min, max);
}

void pyramid(int h, int n, char c){
  for(int i=0; i<n; i++){
    for (int k = 0;k < h;k++){
      printf(" ");
    }
    for (int k = 0; k < i+1; k++){
      printf("%c", c+i);
    }
  printf("\n");
  }
}

float arithmetic_mean(float f1, float f2){
  return (f1 + f2) / 2;
}

void check_negative(int i1){
   if (i1 < 0) printf("The number is negative.\n");
   else printf("The number is %s.\n", i1>0?"positive" : "zero");
}
