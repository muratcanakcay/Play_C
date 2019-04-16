#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int k = atoi(argv[1]), i = 0;
    while (i < k)
    {
        int r = rand()%3;
        printf("%d\n", r);
        i++;
    }









    return 0;
}
