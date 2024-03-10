
//Preprocessor directives that prevent superfluous warnings with functions like scanf
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

//Standard libraries for basic functions and random function
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//FUNCTION DEFINITIONS

//function name: void roll_dice(int* dice, int size)
//description: generates random values for dice rolls, each value is stored in an array
//input parameters: address for the dice array, size of the array
//output: random dice rolls stored in the array

void roll_dice(int* dice);

//function name:void display_rules(void)
//description: displays the rules to the console
//input parametes: none
//output: displays menu

void display_rules(void);

//function name : int determine_user_choice(void)
//description : determines the user's choice of main menu options
//input parametes : none
//output : integer coresponding to the user's choice

int determine_user_choice(void);

//function name : void yahtzee_gameplay(void)
//description : contains all the neccessary functions to play a game of yahtzee with two players.
//input parameters : none
//output : none

void yahtzee_gameplay(void);

//function name : void print_dice(int die_values[]);
//description : prints each roll value to the console. 
//input parameters : address of the dice roll array, count of round
//output : none

void print_dice(int die_values[]);


//function name : void roll_again(int die_values[]);
//description : asks the player if they want to reroll any dice.  
//input parameters : dice values (only neccessary to be sent to the rerolling function upon chosing to reroll. 
//output : none

void roll_again(int die_values[]);

//function name : void reroll_dice(int die_values[]);
//description : asks the player how many dice they want to reroll, which ones
//input parameters : dice values in array, requires user to have entered 'Y' on roll_again function. 
//output : none, reassigns new dice rolls. 

void reroll_dice(int die_values[]);
//void store_dice(int die_values, int num_die_values);

void prompt_roll_again(char* go_again_ptr);