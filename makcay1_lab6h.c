#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void bubble_sort(char* inputstring);

int main(int argc, char* argv[])
{
	if (argc > 1)
	{ 
		int i;		
		char ch, userinput[15];
		for (i = 0; i < 15; i++)
			*(userinput+i) = *(argv[1]+i);
		printf ("\nYour input string is: %s\n\n", userinput);
		
		printf("Your input string includes the following letters:\n");
		for (i = 0; i < 15; i++)
			if (strchr(userinput, *(userinput+i)) == userinput+i)
			{
				if (*(userinput+i) == '\0') break;
				printf("The letter %c at position %d\n", *(userinput+i), i+1); 
			}

		bubble_sort(userinput);
		printf ("\nThe input string re-ordered alphabetically is: %s\n", userinput);

		for (i = 0; i < 15; i++)
		{
			ch = *(userinput + i);			
			if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch =='o' 				|| ch=='O' || ch == 'u' || ch == 'U') *(userinput + i) = '$';
		}
	
		printf ("\nThe vowels replaced by $ is: %s\n", userinput);

		printf ("\nThank you!\n\n");
		
		return 1;

	}

	else 
	{
		printf("You have to enter a string of characters for the program to execute");
		return 0;
	}
}



void bubble_sort(char* inputstring)
{
	int i, j;
	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14 - i; j++)
		{
			if (*(inputstring + j + 1) == '\0') break;
			if (*(inputstring + j) > *(inputstring + j + 1)) 
			{
				// printf("Replacing %c with %c\n", *(inputstring + j), *(inputstring + j + 1));
				char temp = *(inputstring+j);
				*(inputstring + j) = *(inputstring + j + 1);
				*(inputstring + j + 1) = temp;

			
			}
		} 	
	
	}
	// printf("Reordered string is %s\n", inputstring);
}
