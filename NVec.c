#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *Coordinates;
	int length;
} NVec;


NVec CreateVector();
void PrintVector(NVec Vector);
NVec AddVector(NVec Vector1, NVec Vector2);
NVec SubtractVector(NVec Vector1, NVec Vector2);
NVec DotProduct(NVec Vector1, NVec Vector2);
NVec MultiplyByScalar(NVec Vector1, int Scalar);
int Length(NVec Vector);
int NVecCmp(NVec Vector1, NVec Vector2);


void main ()
{
	NVec result; // result variable declaration

	// ask user for 2 vectors

	NVec Vector1 = CreateVector();
	NVec Vector2 = CreateVector();

	printf("\n");

	PrintVector(Vector1);
	printf("Length of the vector 1 is %d\n", Length(Vector1));
	PrintVector(Vector2);
	printf("Length of the vector 2 is %d\n", Length(Vector2));

	printf("\nThe size comparison of the two vectors is: %d\n", NVecCmp(Vector1, Vector2));

	printf("\nSum of the two vectors is \n");
	result = AddVector(Vector1, Vector2);
	PrintVector(result);

	printf("\nDifference of the two vectors is \n");
	result = SubtractVector(Vector1, Vector2);
	PrintVector(result);

	printf("\nDot product of the two vectors is \n");
	result = DotProduct(Vector1, Vector2);
	PrintVector(result);

	printf("\nScalar product of the first vector by scalar (c=5) is \n");
	result = MultiplyByScalar(Vector1, 5);
	PrintVector(result);

}


NVec CreateVector()
{
    NVec* result = (NVec*)malloc(sizeof(NVec));
    printf("Dim of vector:\n");
    scanf("%d", &(result->length));
    result->Coordinates=(int*)malloc(sizeof(int)*(result->length));

	for(int i=0; i<result->length; i++)
    {
        printf("%d coordinate:\n", i);
        scanf("%d", &(result->Coordinates[i]));
    }

    return *result;
}

NVec AddVector(NVec Vector1, NVec Vector2) // Assuming they're the same dim
{
	NVec* result = (NVec*)malloc(sizeof(NVec));
	result->length = Vector1.length;

	result->Coordinates=(int*)malloc(sizeof(int)*(Vector1.length));
	for(int i = 0; i < Vector1.length; i++)
		result->Coordinates[i] = Vector1.Coordinates[i] + Vector2.Coordinates[i];

	return *result;
}

NVec SubtractVector(NVec Vector1, NVec Vector2) // Assuming they're the same dim
{
	NVec* result = (NVec*)malloc(sizeof(NVec));
	result->length = Vector1.length;
	result->Coordinates=(int*)malloc(sizeof(int)*(Vector1.length));

	for(int i=0; i < Vector1.length; i++)
   		result->Coordinates[i] = Vector1.Coordinates[i] - Vector2.Coordinates[i];
   	return *result;
}

NVec DotProduct(NVec Vector1, NVec Vector2) // Assuming they're the same dim
{
	NVec* result = (NVec*)malloc(sizeof(NVec));
	result->length = Vector1.length;
	result->Coordinates=(int*)malloc(sizeof(int)*(Vector1.length));
	for(int i=0; i < Vector1.length; i++)
   		result->Coordinates[i] = Vector1.Coordinates[i] * Vector2.Coordinates[i];
   		return *result;
}

NVec MultiplyByScalar(NVec Vector1, int Scalar)
{
	NVec* result = (NVec*)malloc(sizeof(NVec));
    result->length = Vector1.length;
    result->Coordinates=(int*)malloc(sizeof(int)*(Vector1.length));
	for(int i=0; i < Vector1.length; i++)
   		result->Coordinates[i] = Vector1.Coordinates[i] * Scalar;
   	return *result;
}

int Length(NVec Vector)
{
	int length = Vector.length;
	return length;
}

void PrintVector(NVec Vector)
{
	printf("[");
	for(int i = 0; i < Vector.length; i++)
	{
		printf("%d", Vector.Coordinates[i]);
		if (i + 1 != Vector.length) printf(" ");
	}
	printf("]\n");
}

int NVecCmp(NVec Vector1, NVec Vector2)
{
	if (Vector1.length == Vector2.length) return 0;
	if (Vector1.length < Vector2.length) return -1;
	return 1;
}
