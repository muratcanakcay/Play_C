#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct
{
	char* name;
	char* surname;
	int phone;
	int age;
	char sex;
	float miles;
} Driver;

Driver * readFile(char* filename);
void printArray(Driver* array);

void main()

{

char* filename = "test.txt";
Driver* array = readFile(filename);


}

Driver * readFile(char* filename)
{
	FILE* fp; // declaration of the pointer to the file
    char ch, temp_str[256];
	int counter = 0, field = 1, i = 0;

	strcpy(temp_str, ""); // initialize temp_str to ""
	fp = fopen(filename, "r"); // open file for reading

	if (fp == NULL) return 1;

	printf("File %s opened\n\n", filename); // the input file is found and opened

	printf("Creating driver array\n");

	Driver* array;
	array = malloc(sizeof(Driver));

	printf("Reading data from file\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("get char\n");
		if (ch != ' ' && ch != '\n')
		{
			*(temp_str + i) = ch;
			printf("add to buffer: %s\n", temp_str);
			i++;
			continue;
		}

		if (ch == ' ')
		{
			printf("space!\n");
			if (field == 1)
			{
				int str_len = strlen(temp_str);
				(array+counter)->name = malloc(sizeof(char) * str_len);
				strcpy((array + counter)->name, temp_str);
			}
			printf("space!\n");
			if (field == 2)
			{
				int str_len = strlen(temp_str);
				(array+counter)->surname = malloc(sizeof(char) * str_len);
				strcpy((array + counter)->surname, temp_str);
			}
			printf("space!\n");
			if (field == 3) (array + counter)->phone = atoi(temp_str);
			printf("space!\n");
			if (field == 4) (array + counter)->age = atoi(temp_str);
			printf("space!\n");
			if (field == 5) (array + counter)->sex = *temp_str;
			printf("space!\n");

			// free(temp_str);
			strcpy(temp_str, "");
			printf("temp_str %s\n", temp_str);
			i = 0;
			field += 1;
			continue;
		}

		if (ch == '\n')
		{
			(array+counter)->miles = atof(temp_str);

			i = 0;
			field = 0;
			counter += 1;

			Driver* temp_array = (Driver*)realloc(array, sizeof(Driver) * counter);
			array = temp_array;
		}


    }

	printf("exit\n");
	bzero(temp_str, 32); // empty the temp_str
	return array;
}

void printArray(Driver* array)
{
	printf("here\n");
}
