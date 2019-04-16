#include <stdio.h>              //including stdio.h for printf and other functions


int main()                        //default function for call
{
	int a[100],n,i,j;
	printf("Array size: ");
        scanf("%d",&n);
        printf("Elements: ");

      for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
	for (int i = 0; i < n; i++)                     //Loop for ascending ordering
	{
		for (int j = 0; j < n; j++)             //Loop for comparing other values
		{
			if (a[j] > a[i])                //Comparing other array elements
			{
                printf("Holding: %d Moving: %d Array: ", i,j );
                for (int k = 0; k < n; k++)                     //Loop for printing array data after sorting
            	{
            		printf("%d ", a[k]);                   //Printing data
            	}
                printf("\n");             //storing last value
                int tmp = a[i];         //Using temporary variable for storing last value
				a[i] = a[j];            //replacing value
				a[j] = tmp;             //storing last value

			}
		}
	}
	printf("\n\nAscending : ");                     //Printing message
	for (int i = 0; i < n; i++)                     //Loop for printing array data after sorting
	{
		printf(" %d ", a[i]);
	}
	for (int i = 0; i < n; i++)                     //Loop for descending ordering
	{
		for (int j = 0; j < n; j++)             //Loop for comparing other values
		{
			if (a[j] < a[i])                //Comparing other array elements
			{
				int tmp = a[i];         //Using temporary variable for storing last value
				a[i] = a[j];            //replacing value
				a[j] = tmp;

			}
		}
	}
	printf("\n\nDescending : ");                    //Printing message
	for (int i = 0; i < n; i++)                     //Loop for printing array data after sorting
	{
		printf(" %d ", a[i]);                   //Printing data
	}

	return 0;                                       //returning 0 status to system
}

// #include <stdio.h>
//
// int* sort(int, int, int*);
// int result[10];
// int i;
//
// int main()
// {
//     int arr[10] = {2, 5, 4, 3, 10, 7, 9, 8, 1, 6};
//     // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//     i = 0;
//     for (i; i < 10; i++) sort(i, arr[i], result);
//
//     i = 0;
//     printf("The unsorted array was : ");
//     for (i; i < 10; i++) printf("%d ", arr[i]);
//
//     i = 0;
//     printf("\nThe sorted array is : ");
//     for (i; i < 10; i++) printf("%d ", result[i]);
//
//     printf("\n");
//     return 0;
// }
//
// int* sort(int i, int num, int* result)
// {
//     if (i == 0) *(result+i) = num;
//     else
//     {
//         if (*(result+i-1)<=num) *(result+i)=num;
//         else
//         {
//             *(result+i) = *(result+i-1);
//             sort(i-1, num, result);
//         }
//     }
//
//     printf("index %d is now %d\n", i, result[i]);
//     return result;
// }
