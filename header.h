//This file contains all function declarations and descriptions neccessary to play yahtzee

//Preprocessor directives that prevents warnings with functions like scanf
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

//Standard libraries for basic functions and random function
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//FUNCTION DEFINITIONS

void sort_array(int array[], int size);

//function name: void roll_dice(int* dice, int size)
//description: generates random values for dice rolls, each value is stored in an array
//input parameters: address for the dice array, size of the array
//output: random dice rolls stored in the array

void roll_dice(int dice [], int size);

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

//function name : void print_dice(int die_values[], int counter);
//description : prints each roll value to the console. 
//input parameters : address of the dice roll array, count of round
//output : none

void print_dice(int die_values[], int counter);


//function name : void roll_and_check(int die_values[]);
//description : asks the player if they want to reroll any dice.  
//input parameters : dice values (only neccessary to be sent to the rerolling function upon chosing to reroll. 
//output : none

void roll_and_check(int die_values[]);

//function name : void prompt_roll_again(char* go_again_ptr);
//description : asks if they want to reroll
//input parameters : address for user choice response
//output : none, indirectly modifies the go_again_choice variable

void prompt_roll_again(char* go_again_ptr);


//function name : void get_num_die(int die_values[], int num_die_values[])
//description : stores the frequency of each roll value 
//input parameters : final dice roll
//output : saves the frequency of each value to be used for scoring

void get_num_die(int die_values[], int num_die_values[]);

//function name : void score_roll(int die_values[], int num_die_values[], int upper[], int lower[], int check_score_option[])
//description : allows the user to choose scoring method after rolling. 
//input parameters : die values, frequency of die values (for choice validation), array to store scores of the upper region of the score card,
// array to store scores of the lower region of the score card, and integer coresponding to the users desired score type choice
//output : score of the roll, saves score type to prevent reuse

//function name : void score_roll(int die_values[], int num_die_values[], int upper[], int lower[], int check_score_option[])
//description :  determines score of round
//input parameters : rolled die values, frequency of values, upper score card values, lower score card value, array coresponding to which score options have already been chosen 
//output : updates all arrays for accurate round score, used to determine winner

void score_roll(int die_values[], int num_die_values[], int upper[], int lower[], int check_score_option[]);


//function name : void clear_dice(int num_die_values[])
//description :  clears the array coresponding to dice frequency, otherwise both player one and player two's roll frequencies are combined, messing up scoring
//input parameters : die value frequency array
//output : clears the frequency array for the next player

void clear_dice(int num_die_values[]);

//function name : void prompt_score_type(int *score_method, int check_score_option[])
//description :  prompts user to choose score type for round, type cannot be chosen more than once
//input parameters : array coresponding to chosen method and which methods have already been used up 
//output : updates which methods have been chosen, chosen method is used to determine score

void prompt_score_type(int* score_method, int check_score_option[]);

//function name : char clear_window()
//description :  allows the console to be cleared after each player has completed their round
//input parameters : n/a
//output : clears console if user enters 'x', I unfortunately couldn't figure out a way to clear it if the user simply hit the enter key, but i tried :(

char clear_window(void);

//function name : void score_update(int rounds, int player_one_uppers[], int player_one_lowers[], int player_two_uppers[], int player_two_lowers[], int* player_one_sum, int* player_two_sum)
//description :  keeps track of the current score after each round, used for determining winner and informing players of their score each round
//input parameters : round number, players upper and lower score card values and accumulated total sums
//output : prints current scores

void score_update(int rounds, int player_one_uppers[], int player_one_lowers[], int player_two_uppers[], int player_two_lowers[], int* player_one_sum, int* player_two_sum);

//function name : void determine_winner(int* player_one_sum, int* player_two_sum)
//description :  determines which player won after all rounds are completed
//input parameters : the sum of each player's scores
//output : prints to the console a message as to who won the game

void determine_winner(int* player_one_sum, int* player_two_sum);
