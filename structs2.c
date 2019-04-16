#include <stdio.h>
#include <stdlib.h>

//* The struct declaration as type "box"
typedef struct
{
    int contents;
    int row;
    int column;
} box;

//* Two function declarations one for printing the boxes the other for modifying their contents.
void print_boxes(int rows, int columns, box array[rows][columns]);
void modify_boxes(int rows, int columns, box array[rows][columns], int row, int column, int new_value);

//* Main body of the program
int main(int argc, char *argv[])
{
    if(argc == 4)
    {
        //* Initializing the variables
        int value = 0;
        int rows = atoi(argv[2]);
        int columns = atoi(argv[3]);
        box boxes[rows][columns];

        //* Initial assignment of the values to the boxes
        for (int r=0; r<rows; r++)
        {
            for (int c=0; c<columns; c++)
            {
                value += atoi(argv[1]);  //* Value algorithm
                boxes[r][c] = (box) {value, r+1, c+1};
                printf("The value %d is entered into box %d %d\n", boxes[r][c].contents, r + 1, c + 1);
            }
        }
        print_boxes(rows, columns, boxes);

        //* Loop where the user can modify the values of the boxes
        while(1==1)
        {
            int row_input, column_input, value_input;
            printf("\nPlease enter the coordinates (row and column) of the box you want to modify and the new value of the box, with spaces between them (use Ctrl-C to exit): \n");
            scanf(" %d %d %d", &row_input, &column_input, &value_input);
            modify_boxes(rows, columns, boxes, row_input, column_input, value_input);
            print_boxes(rows, columns, boxes);
        }
    }
    else
    {
        printf("You must enter three arguments!\nThe first argument is the value to be used.\nThe second argument is the number of rows.\nThe third argument is the number of columns.\nFor example try: 'structs2 0 5 5'\n\n");
    }
}

//* Function definitions
void print_boxes(int rows, int columns, box array[rows][columns])
{
    printf("\nThis is the function printing the boxes.\n");
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
        printf("%dx%d = %d  ", array[r][c].row, array[r][c].column, array[r][c].contents);
        }
        printf("\n");
    }
}

void modify_boxes(int rows, int columns, box array[rows][columns], int row, int column, int new_value)
{
    array[row-1][column-1].contents = new_value;
    printf("\nThis is the function modifying the box value.\n");
    printf("Box %dx%d's value is changed to %d\n", row, column, array[row-1][column-1].contents);
}
