#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int player;
    int fish;
} ice_floe;

int main ()
{
    FILE *fp;
    char ch, buffer[32];
    int i = 0, arr[500], j = 0, space = ' ';
    fp = fopen("2.txt", "r");
    while (1)
    {
        ch = getc(fp) ;
        printf("%c", ch);
        if (ch == ' ' || ch == EOF)
        {
            arr[j] = atoi(buffer);
            j++;
            bzero(buffer, 32);
            i = 0;
            if (ch == EOF) break;
            continue;
        }
        else
        {
            buffer[i] = ch;
            i++;
        }
    }
    fclose(fp);
    for(i = 0; i < j; i++)
    {
    		printf("Number [%d]: %d\n", i, arr[i]);
    }
    return 0;
}
