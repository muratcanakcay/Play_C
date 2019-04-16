#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int penguin_owner;  // This is 0 if no penguin is present in the ice_floe, or it is set to the player_no which the penguin belongs to
    int fish; // This is the number of fish  present in the ice_floe.
} ice_floe;

typedef struct
{
    char player_ID[30]; //Player's name
    int player_no; // Player's number
    int player_score; //Player's current score
    int movement_possible; // 0 if player cannot move, 1 if it can (default value is 1 and it can be updated to 0 in the movement_possibility_check function)
} player;

int main ()
{
    FILE *fp;
    char ch, buffer[32];
    int r = 0, c = 0, n = 0, rows = 0, columns = 0, arr[500];

    fp = fopen("2.txt", "r");
    printf("File opened\n\n");

    while (1)
    {
        ch = getc(fp);
        //* Read the dimensions of the map from line 1 of the file

        if (rows == 0 || columns == 0)
        {

            if (ch == ' ' || ch == '\n')
            {
                arr[c] = atoi(buffer);
                c++;
                bzero(buffer, 32);
                r = 0;
            }

            else
            {
                buffer[r] = ch;
                r++;
            }
        }

        // when the first two values are read from the file, pass the values to row and column variables and create the map array.

        if (ch == '\n')
        {
            rows = arr[0];
            columns = arr[1];
            printf("Rows:%d Columns:%d\n\n", rows, columns);
            break;
        }
    }
    //* Now that the dimensions of the map are read from file we create the map array and continue parsing the file and fill in the map array until we reach player ID.

    ice_floe map[rows][columns];  // create map array

    //* Iterating through the row and columns we read values and pass them into their respective variables - fish or penguin_owner - in the ice_floe structures located in each cell of the  map array.

    for (r = 0; r < rows; r++)
    {

        for (c = 0; c < columns; c++)
        {
            ch = getc(fp);
            map[r][c].fish = ch - '0';
            ch = getc(fp);
            map[r][c].penguin_owner = ch - '0';
            getc(fp);   // to jump over the space between columns
        }

        getc(fp); // to jump over the EOL between rows
    }

    for (r = 0; r < rows; r++)
    {

        for (c = 0; c < columns; c++)
            printf("%d%d ", map[r][c].fish, map[r][c].penguin_owner);

        printf("\n");
    }

    //* Now the map is transferred to the map array. We continue parsing to transfer the player information present in the file in to the player array.

    //* First we create the players array and initialize the player_no and movement_possible variables of the first index to 0 (total no of players and number of players who can still make a move)

    player players[10];
    players[0].player_no = 0;
    players[0].movement_possible = 0;

    //* Now we start parsing the text file again.
    r = 0;
    c = 0;
    n = 1;
    ch = getc(fp);

    while (1)
    {
        // printf("getchar: %d %d '%c'\n", n, c, ch);
        //* Read the information regarding players from the final lines of the file

        if (ch == ' ' || ch == '\n' || ch == EOF)
        {
            c++;

            if (c == 1) // The name of the player is in the buffer
            {
                // printf("array update %s %d\n\n", buffer, c);
                strcpy(players[n].player_ID, buffer);
            }

            if (c == 2) // The number of the player is in the buffer
            {
                // printf("array update %s %d\n\n", buffer, c);
                players[n].player_no = atoi(buffer);
            }

            if (c == 3) // The score of the player is in the buffer
            {
                // printf("array update %s %d\n\n", buffer, c);
                players[n].player_score = atoi(buffer);
                players[n].movement_possible = 1;
                players[0].movement_possible = ++players[0].player_no;
                c = 0;
                n++; // Proceed to the next player
            }

            bzero(buffer, 32);
            r = 0;

        }

        else
        {

            buffer[r] = ch;
            // printf("buffer update %s %d\n", buffer, c);
            r++;
        }

        ch = getc(fp);

        if (ch == EOF)
        {
            // printf("%s", "breaking\n\n");
            break;
        }
    }

    printf("\nTotal no of players: %d\n", players[0].player_no);
    printf("Total no of players that can move: %d\n\n", players[0].movement_possible);

    for (c = 1; c < players[0].player_no+1; c++)
    {
        printf("Player no: %d\n", players[c].player_no);
        printf("Name: %s\n", players[c].player_ID);
        printf("Score: %d\n", players[c].player_score);
        printf("Movement possible?: %d\n\n", players[c].movement_possible);
    }

    return 0;
}
