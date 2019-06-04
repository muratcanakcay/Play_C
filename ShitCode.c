#include <stdio.h>
#include <stdlib.h>

void fillMatrixWithSomeShit(int matrix[3][3], int realMatSize);
void printMatrix(int matrix[3][3], int realMatSize);

int main(int argc, char *argv[]){

    while(1) {
        printf("Determine matrix size: ");
        int size;
        scanf("%d", &size);

        if(size < 0)
            break;

        int matrix[3][3];

        fillMatrixWithSomeShit(matrix, size);
        printMatrix(matrix, size);
    }

    return 0;
}


void fillMatrixWithSomeShit(int matrix[3][3], int realMatSize){
    for(int i = 0; i < realMatSize; i++){
        for(int j = 0; j < realMatSize; j++)
            *(*(matrix + i) + j) = i * realMatSize + j;
    }
}

void printMatrix(int matrix[3][3], int realMatSize){
    for(int i = 0; i < realMatSize; i++){
        for(int j = 0; j < realMatSize; j++)
            printf("%2d", matrix[i][j]);
        printf("\n");
    }
}