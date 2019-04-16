#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <struct_function_call.h>

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



struct* struct_function_call();


int main()
{






}
