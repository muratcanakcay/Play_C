#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void createrandom(int arr[], int arrLength, int toRange);
void swap(int *x, int*y);
void bubblesort(int arr[], int lengthOfArray);
void printarr(int arr[], int lengthOfArray);

int main(int argc, char *argv[]) {
    if(argc>2){
        srand(time(NULL));

        int arrLength=atoi(argv[1]), Range=atoi(argv[2]);
        int random[arrLength];

        createrandom(random, arrLength, Range);

        printarr(random,arrLength);

        printf("-------------------------- \n");

        bubblesort(random, arrLength);

        printarr(random,arrLength);

        return 1;
    }
    else{
        printf("Not enough number of arguments");
        return -1;
    }
}

void createrandom(int arr[], int arrLength, int toRange){
    for(int it=0; it<arrLength; it++){
        arr[it]=rand() % toRange + 1;
    }
}
void swap(int *x, int*y){
    int tmp=*x;
    *x=*y;
    *y=tmp;
}

void bubblesort(int arr[], int lengthOfArray){
    for(int it=0; it< lengthOfArray-1; it++){
        //after first iteration the last element will be the greatest one
        //that's why we dont have to consider it later = lengthOfArray-it-1
        for(int iter=0; iter < lengthOfArray-it-1; iter++){
            if(arr[iter]>arr[iter+1])
                swap(&arr[iter],&arr[iter+1]);
        }
    }
}

void printarr(int arr[], int lengthOfArray){
    for(int it=0; it<lengthOfArray; it++){
        printf("%d \n",arr[it]);
    }
}
