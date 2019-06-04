#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct
{
	int ID;
	char* name;
	int points;
} Student;

void create_array(Student* array, int no_entries);
void print_info(Student* array, int no_entries, char method);
void sort_array(Student* array, int no_entries);
void swap_structs(Student* A, Student* B);

int main()
{

	int i, no_entries;

	printf("How many student entries will you make?");
	if (scanf("%d", &no_entries) == 0)
		while (getchar() != '\n')
			;

	Student* array = (Student*)malloc(sizeof(Student) * no_entries);

	create_array(array, no_entries);

	sort_array(array, no_entries);

	printf("\nPrinting list in ascending order:\n");
	print_info(array, no_entries, 'a');

	printf("\nPrinting list in descending order:\n");
	print_info(array, no_entries, 'd');

}

void create_array(Student* array, int no_entries)
{
	int i;
	char temp_str[30];

	for (i = 0; i < no_entries; i++)
	{
		printf("\nPlease enter the ID of Student #%d  ", i + 1);
		while (scanf("%d", &((array+i)->ID)) == 0)
		{
			while (getchar() != '\n')
				;
			printf("Please enter only numbers!\n");
		}

		printf("Please enter the Name of Student #%d:  ", i + 1);
		scanf(" %s", temp_str);

		(array+i)->name = (char*)malloc(sizeof(char) * (strlen(temp_str)));
		strcpy((array+i)->name, temp_str);

		printf("Please enter the No. of Points of Student #%d:  ", i + 1);
		if (scanf("%d", &((array+i)->points)) == 0)
		{
			while (getchar() != '\n')
				;
			printf("Please enter only numbers!");
		}
	}
}

void print_info(Student* array, int no_entries, char method)
{
	int i;

	printf("Pts. ID         Name\n");
	if (method == 'a') for (i = 0; i < no_entries; i++)
	{
		printf("%-*d %-*d %-*s\n", 4, (array+i)->points, 10, (array+i)->ID, 30, (array+i)->name);
	}

	if (method == 'd') for (i = no_entries-1; i >= 0; i--)
	{
		printf("%-*d %-*d %-*s\n", 4, (array+i)->points, 10, (array+i)->ID, 30, (array+i)->name);
	}
}

void sort_array(Student* array, int no_entries)
{
	int i, j;

	for (i = 0; i < no_entries - 1; i++)
		for (j = i; j < no_entries - 1; j++)
			if ((array + j)->points > (array + j + 1)->points)
				swap_structs(array+j, array+j+1);
}

void swap_structs(Student* A, Student* B)
{
    Student temp = *A;
    *A = *B;
    *B = temp;
}
