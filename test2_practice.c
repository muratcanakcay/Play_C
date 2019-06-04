#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list_el
{
	int val;
	struct list_el * next;
} list_el;

void add_number_last(list_el * head, int val);
void fill_numbers(list_el * head, int length, int min, int max);
void print_numbers(list_el * head);
int get_length(list_el * head);
int get_sum(list_el * head);
int get_value(list_el * head, int pos);
void change_value(list_el * head, int pos, int val);
void bubble_sort(list_el * head, int length);
void delete_value(list_el ** head, int pos, int* length);
void insert_value(list_el ** head, int pos, int value, int* length);
list_el * search_value(list_el * head, int value);





void print_numbers_backwards(int numbers[30]);
void print_differences(int numbers[30]);
void min_max_mean(int numbers[30]);


int main(int argc, char* argv[])
{
    if (argc > 3)
    {
        int seed;
        int min, max, mean, val, pos, length;
        time_t tt;
        int numbers[30];

		seed = time(&tt);
		srand(seed);

		length = atoi(argv[1]);
		min = atoi(argv[2]);
		max = atoi(argv[3]);

		list_el * head = NULL;
		head = malloc(sizeof(list_el));
		if (head == NULL) return 1;

		head->val = min + rand()%(max-min+1); // first value
		head->next = NULL;

        fill_numbers(head, length, min, max);

		int found_length = get_length(head);
		int found_sum = get_sum(head);

		printf("\nTotal number of entries: %d\n", found_length);
		printf("Sum of the entries: %d\n", found_sum);


		while(1)
		{

			printf("\nThe list of numbers is:\n");
			print_numbers(head);
			int value;


			char selection;
			printf("\n(b)ubblesort, (c)hange, (d)elete, (i)nsert, (s)witch, s(e)arch ? ");
			scanf(" %c", &selection);


			if (selection == 'c' || selection == 'd' || selection == 'i' )
			{
				printf("Which position? (Enter a number between 0 and %d)", length);
				scanf("%d", &pos);
				if (pos < 1 || pos > length)
				{
					printf("%d is not a valid position. Enter a number between 0 and %d\n", pos, length);
					continue;
				}
				value = get_value(head, pos - 1);
				printf("The value of position %d is %d\n", pos, value);
			}

			if (selection == 'c')
			{
				printf("\nEnter new value for position %d:", pos);
				scanf("%d", &value);
				printf("\nThe value of position %d will be changed to %d:\n", pos, value);

				change_value(head, pos - 1, value);
				continue;
			}

			if (selection == 'd')
			{
				printf("\nPosition %d will be deleted:\n", pos);
				delete_value(&head, pos - 1, &length);
				continue;
			}

			if (selection == 'b')
			{
				printf("The random numbers sorted are:\n");
				bubble_sort(head, length);
				continue;
			}

			if (selection == 'i')
			{
				printf("\nEnter value to be inserted at position %d:", pos);
				scanf("%d", &value);
				printf("\n%d will be inserted at position %d:\n", value, pos);

				insert_value(&head, pos - 1, value, &length);
				continue;
			}

			if (selection == 'e')
			{
				printf("\nEnter value to be searched in the list:");
				scanf("%d", &value);
				search_value(head, value);
				continue;
			}
		}
    }

    else
    {
        printf("You have to enter at least three arguments: i.e. the length, minimum and max values");
        return 0;
    }
}

void fill_numbers(list_el * head, int length, int min, int max)
{
    for (int i = 0; i < length - 1; i++)
    {
		int number = min + rand()%(max-min+1);
		add_number_last(head, number);
	}
}

void print_numbers(list_el * head)
{
    list_el * current = head;
	int counter = 0;
    while (current != NULL)
	{
        printf("%d ", current->val);
        current = current->next;
		counter++;
	}

	printf(" Total length: %d \n", counter);
}

void bubble_sort(list_el * head, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
		{
			int left = get_value(head, j);
			int right = get_value(head, j + 1);
			if (left > right)
            {
                int temp = left;
                left = right;
                right = temp;
				change_value(head, j, left);
				change_value(head, j + 1, right);
            }
		}
    }
}

void change_value(list_el * head, int pos, int val)
{
	list_el * current = head;
	int counter = 0;
	while (counter < pos)
	{
		current = current->next;
		counter++;
	}

	current->val = val;

}

int get_value(list_el * head, int pos)
{
	list_el * current = head;
	int counter = 0;

	while(counter < pos)
	{
		current = current->next;
		counter++;
	}

	return current->val;
}

int get_length(list_el * head)
{
	list_el * current = head;
	int counter = 1;
	while (current->next != NULL)
	{
		current = current->next;
		counter++;
	}
	return counter;
}

int get_sum(list_el * head)
{
	list_el * current = head;
	int sum = current->val;
	while (current->next != NULL)
	{
		current = current->next;
		sum += current->val;
	}
	return sum;
}

void add_number_last(list_el * head, int val)
{
	list_el * current = head;

	while (current->next != NULL)
        current = current->next;
    // this loop takes us to the last element of the list

    /* now we can add a new variable */
    current->next = malloc(sizeof(list_el)); // first allocate memory for a NVec struct
    current->next->val = val; // now give the value
    current->next->next = NULL; // and define next struct as NULL so this struct will be recognized as the last

}

void delete_value(list_el ** head, int pos, int* length)
{
	*length -= 1;

	if (pos == 0)
	{
		*head = (*head)->next; /* if deleting the first value replace pointer to head with the adress of the next struct. */
		return;
	}

	list_el * current = *head;
	int counter = 0;
	while (counter < pos - 1)
	{
		current = current->next;
		counter++;
	}

	current->next = current->next->next;


}

void insert_value(list_el ** head, int pos, int value, int* length)
{
	*length += 1;

	list_el * new_el;
	new_el = malloc(sizeof(list_el));
	new_el->val = value;

	if (pos == 0)
	{
		new_el->next = *head;
		*head = new_el;
		return;
	}

	list_el * current = *head;
	int counter = 0;
	while (counter < pos - 1)
	{
		current = current->next;
		counter++;
	}

	new_el->next = current->next;
	current->next = new_el;

}

list_el * search_value(list_el * head, int value)
{
	list_el * current = head;
	int counter = 1;

	do
	{
		if (current->val == value)
		{
			printf("%d found at position %d\n", value, counter);
			return current;
		}
		current = current->next;
		counter++;
	} while (current != NULL);

	printf("%d not found in the list\n", value);
	return current;
}
