//Name: Sydnee Boothby
//Class: CptS 121
//Assignment: PA5
//Due Date: 03/20
//Instructor: Andy O'Fallon
//TA: Claire Monsoon
//Description: This program includes all the neccessary functions to play a game of yahtzee with two players.
//It includes the use of various used-based functions, loops, pointers, and arrays learned thus far in CptS 121. 

#include "header.h"

int main(void) {
	srand((time(NULL))); //allows for random dice rolls

	int user_choice = 0; //initialize variable for user menu choice

	printf("Welcome to the Yahtzee!\n\n");
	do {

		user_choice = determine_user_choice(); //stores user choice

		switch (user_choice) { 
		case 1: display_rules();
			break;
		case 2:
			yahtzee_gameplay();
			break;
		case 3:
			printf("\nGoodbye, thanks for playing :)\n");
			return 0;
		}
	} while (user_choice != 3); //repeats menu until user chooses to leave program

	return 0; //indicates program ran successfully
}
