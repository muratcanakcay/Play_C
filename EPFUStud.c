#include <stdio.h>
#include <stdlib.h>

typedef union {
	int type1;
	float type2;
} grade;

typedef struct
{
	char *name;
	int id;
	long phoneNumber;
	grade testGrade;
	int finalGrade;
} EPFUStud;

EPFUStud init();

void main()
{




}

EPFUStud init()
{
	EPFUStud temp;
	printf("Asking for student info\n");
	printf("Enter name: ");
	scanf("%s", &(temp.name));
	printf("Enter id: ");
	scanf("%d", &(temp.id));
	printf("Enter phone: ");
	scanf("%ld", &(temp.phoneNumber));
	printf("Enter testgrade type: ");
	scanf("%f", &(temp.grade));

}
