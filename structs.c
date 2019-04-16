#include <stdio.h>
#include <stdlib.h>

int numStudents = 5;
char *names[] = {"Able", "Bully", "Chief", "Dandy", "Eeee"};
char *surnames[] = {"Artur", "Bilbo", "Cincinati", "Daddy", "Eeo"};
int days[] = {11, 2, 23, 24, 5};
int months[] = {1, 2, 3, 4, 5};
int years[] = {1901, 902, 1303, 004, 505};


typedef struct
{
    char *firstName;
    char *lastName;
    int day;
    int month;
    int year;
} student;

void print_student(int, student array[]);

void main()
{
    student students[numStudents];
    for (int z=0; z<5; z++)
    {
        students[z] = (student) {names[z], surnames[z], days[z], months[z], years[z]};

        print_student(z+1, students);
    }


}

void print_student(int n, student array[])
{
    printf("Student no.%d's first name is %s\n", n, array[n-1].firstName);
    printf("Student no.%d's first name is %s\n", n, array[n-1].lastName);
    printf("Student no.%d's first name is %d\n", n, array[n-1].day);
    printf("Student no.%d's first name is %d\n", n, array[n-1].month);
    printf("Student no.%d's first name is %d\n\n", n, array[n-1].year);
}
