//This file contains all function definitions and descriptions neccessary to play yahtzee

#include "header.h"


//function name: void roll_dice(int* dice, int size)
//description: generates random values for dice rolls, each value is stored in an array
//input parameters: address for the dice array, size of the array
//output: random dice rolls stored in the array

void roll_dice(int die_values[], int size)
{

	for (int i = 0; i < size; i++) {
		int num = 0;
		num = rand() % 6 + 1;
		die_values[i] = num;
	}
}


//function name:void display_rules(void)
//description: displays the rules to the console
//input parametes: none
//output: displays menu

void display_rules(void) {
	printf("Here are the rules:\n\n");
	printf("Each player will take turns rolling five dice\n");
	printf("Your goal is to achieve high-scoring dice combinations.\n");
	printf("You can reroll any chosen dice a total of 3 times\n");
	printf("After that, you will be prompted to choose one of 13 scoring combinations, but you can only choose each one once!\n **note that if you are repeatedly asked to enter a score type, you've exausted that option, choose something else!\n\n");
	printf("Both players will take a total of 13 turns, the player with the highest sum wins! \n");
	printf("Without further ado, lets play!\n\n");
}

//function name : int determine_user_choice(void)
//description : determines the user's choice of main menu options
//input parameters : none
//output : integer coresponding to the user's choice

int determine_user_choice(void) {
	int user_choice = 0;
	printf("Enter 1 to see rules, 2 to play, 3 to exit \n");
	printf("Enter your choice: \n");
	scanf("%d", &user_choice);
	return user_choice;
}

//function name : void yahtzee_gameplay(void)
//description : contains all the neccessary functions to play a game of yahtzee with two players.
//input parameters : none
//output : none

void yahtzee_gameplay(void) {

	int rounds = 0;
	int player_1_rolls[6] = { 0 }, player_one_uppers[7] = { 0 }, player_one_lowers[7] = { 0 }, player_one_score_option[14] = { 0 }, player_one_score = 0;
	int player2_rolls[6] = { 0 }, player_two_uppers[7] = { 0 }, player_two_lowers[7] = { 0 }, player_two_score_option[14] = { 0 }, player_two_score = 0;

	int die_values[5] = { 0 }; //dice rolls for each roll
	int num_die_values[6] = { 0 }; //stores each roll in an array, allows user to change rolls by assigning an index value for each dice value

	char clear_console = '\0';

	//scoring variables

	int total_score_player_1 = 0;
	int total_score_player_2 = 0;

	rounds = 1;
	printf("\nROUND %d\n\n", rounds);

	while (rounds <= 13) {


		printf("It is player 1's turn: \n");
		roll_and_check(die_values);
		get_num_die(die_values, num_die_values); //function organizes values by frequency
		score_roll(die_values, num_die_values, player_one_uppers, player_one_lowers, player_one_score_option);

		clear_window(); //function to clear the window after the user hits "x"
		clear_dice(num_die_values); //clear out dice frequency sum (otherwise, the sum includes the frequency for both players for every round)


		printf("It is player 2's turn: \n");
		roll_and_check(die_values);
		get_num_die(die_values, num_die_values); 
		score_roll(die_values, num_die_values, player_two_uppers, player_two_lowers, player_two_score_option);

		clear_window();
		clear_dice(num_die_values);

		score_update(rounds, player_one_uppers, player_one_lowers, player_two_uppers, player_two_lowers, &total_score_player_1, &total_score_player_2);
		++rounds;

		printf("\nROUND %d\n\n", rounds);
	}

	determine_winner(&total_score_player_1, &total_score_player_2);
	printf("Gameover, thanks for playing! :P \n");
	return;
}

//function name : void print_dice(int die_values)
//description : prints the randomized dice rolls to the console. 
//input parameters : random dice roll values
//output : void, prints the die values to the console

void print_dice(int die_values[], int counter) {

	printf("Roll %d \n", counter);

	for (int i = 0; i < 5; ++i) {
		printf("%d", die_values[i]);
	}
	printf("\n");
}

//function name : void prompt_roll_again(char* go_again_ptr)
//description :  determines reroll
//input parameters : address to variable storing whether or not the user wants to reroll
//output : stores whether or not the user choose to reroll

void prompt_roll_again(char* go_again_ptr) {
	char wanna_roll = '\0';
	printf("Want to reroll any dice? (Enter 'Y' for yes and 'N' for no): ");
	scanf(" %c", &wanna_roll);
	if (wanna_roll == 'y' || wanna_roll == 'Y') {
		*go_again_ptr = 'Y';
	}
	else {
		*go_again_ptr = '\0';
	}
}

//function name : void roll_and_check(int die_values[])
//description :  rolls dice up to three times, stores result
//input parameters : array coresponding to dice rolls
//output : integer dice rolls

void roll_and_check(int die_values[]) {
	//Variables initialized
	int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, how_many = 0, counter = 1;
	char wanna_roll_again = '\0';

	//Die rolled and printed (first roll); User prompted to roll again
	roll_dice(die_values, 5);
	print_dice(die_values, counter);
	prompt_roll_again(&wanna_roll_again);

	//Second and third roll (if necessary)
	do {
		if (wanna_roll_again == '\0') {
			break;
		}
		//Prompts for how many die should be kept
		do {
			printf("How many do you want to keep? ");
			scanf("%d",&how_many);
		} while (how_many < 0 || how_many > 5);

		counter += 1;

		//Prompts for which ones should be kept; re-rolls the others
		switch (how_many) {
		case 0: roll_dice(die_values, 5);
			break;

		case 1: printf("Which one do you want to keep? (1-5, left to right):");     //Add while loops to make the user enter valid numbers
			scanf("%d",&i1);
			i1 = i1 - 1; //subtract 1 to consider the first address value of the array is 0 not 1
			for (int i = 0; i < 5; i++) {
				if (i == i1) {
					continue;
				}
				else {
					die_values[i] = rand() % 6 + 1;
				}
			}
			break;

		case 2: printf("Which ones do you want to keep? (1-5, left to right, press enter after each input):\n");
			scanf("%d%d",&i1,&i2);

			i1 = i1 - 1; //subtract 1 from each to consider the first address value of the array is 0 not 1
			i2 = i2 - 1;

			for (int i = 1; i < 6; i++) { 
				if (i == i1) {
					continue;
				}
				if (i == i2) {
					continue;
				}
				else {
					die_values[i] = rand() % 6 + 1;
				}
			}
			break;

		case 3: printf("Which ones do you want to keep? (1-5, left to right, press enter after each input):\n");
			scanf("%d%d%d",&i1,&i2,&i3);
			i1 = i1 - 1;
			i2 = i2 - 1;
			i3 = i3 - 1;
			for (int i = 1; i < 6; i++) {
				if (i == i1 || i == i2 || i == i3) {
					continue;
				}
				else {
					die_values[i] = rand() % 6 + 1;
				}
			}
			break;

		case 4: printf("Which ones do you want to keep? (1-5, left to right, press enter after each input):\n");
			scanf("%d%d%d%d",&i1,&i2,&i3,&i4);
				i1 = i1 - 1;
				i2 = i2 - 1; 
				i3 = i3 - 1;
				i4 = i4 - 1;

			for (int i = 1; i < 6; i++) {
				if (i == i1 || i == i2 || i == i3 || i == i4) {
					continue;
				}
				else {
					die_values[i] = rand() % 6 + 1;
				}
			}
			break;

		case 5: break;

		}
		//Prints the die, prompts for a 3rd roll
		print_dice(die_values, counter);
		if (counter < 3) {
			prompt_roll_again(&wanna_roll_again);
		}
		
	} while (wanna_roll_again == 'Y' && counter < 3);

}

//function name : void get_num_die(int die_values[], int num_die_values[])
//description :  stores the frequency of each integer roll
//input parameters : final roles, empty array to store frequency values
//output : the frequency of each integer roll

void get_num_die(int die_values[], int num_die_values[]) {
	for (int i = 0; i < 5; i++) {
		int x = die_values[i];
		num_die_values[x-1] += 1; //subtract 1 from x because there are 6 roll possibilities and 5 rolls
	}
}

//function name : void score_roll(int die_values[], int num_die_values[], int upper[], int lower[], int check_score_option[])
//description :  determines score of round
//input parameters : rolled die values, frequency of values, upper score card values, lower score card value, array coresponding to which score options have already been chosen 
//output : updates all arrays for accurate round score, used to determine winner

void score_roll(int die_values[], int num_die_values[], int upper[], int lower[], int check_score_option[]) {
	int score_method = 0; //used for switch statements
	int sum = 0; //initialize sum variable for case 13
	prompt_score_type(&score_method, check_score_option);

	////DUMMY VALUES USED FOR DEBUGGING
		//num_die_values[0] = 0;
		//num_die_values[1] = 0;
		//num_die_values[2] = 0;
		//num_die_values[3] = 0;
		//num_die_values[4] = 0;
		//num_die_values[5] = 0;

	switch (score_method) {
	case(1): upper[1] = num_die_values[0]; //address 0 of the num_dies_values array stores frequencies of 1s
		check_score_option[1] = 1; //check to validate that score method type is not yet used up
		printf("Sum of ones: %d\n", upper[1]); //the sum of ones is the score
		break;

	case(2): upper[2] = (num_die_values[1]) * 2; //address 1 of the num_dies_values array stores frequencies of 2s
		//multiply frequency by 2 because score is the sum of roles of twos
		check_score_option[2] = 1; //score method is now used up
		printf("Sum of twos: %d\n", upper[2]); //the sum of twos is the score
		break;

	case(3): upper[3] = (num_die_values[2]) * 3;
		check_score_option[3] = 1;
		printf("Sum of threes: %d\n", upper[3]); //the total sum of threes is the score
		break;

	case(4): upper[4] = (num_die_values[3]) * 4;
		check_score_option[4] = 1;
		printf("Sum of fours: %d\n", upper[4]); //the total sum of fours is the score
		break;

	case(5): upper[5] = (num_die_values[4]) * 5;
		check_score_option[5] = 1;
		printf("Sum of fives: %d\n", upper[5]); //the total sum of fives is the score
		break;

	case(6): upper[6] = (num_die_values[5]) * 6;
		check_score_option[6] = 1;
		printf("Sum of sixes: %d\n", upper[6]); //the total sum of sixes is the score
		break;

		//lower card scoring options
			//three of a kind
	case(7):
		check_score_option[7] = 1; //checks to make sure option has not been used yet
		for (int i = 0; i <= 5; i++) { //iterates through num_die_values to find a frequency of 3
			if (num_die_values[i] == 3) {
				lower[1] = ((i + 1) * 3); //score is equal to value * 3, because i starts at 0, need to add 1
			}
		}
		printf("Three of a kind sum: %d\n", lower[1]);
		break;
		//four of a kind
	case(8):
		check_score_option[8] = 1;
		for (int i = 0; i <= 5; i++) {
			if (num_die_values[i] == 4) {
				lower[2] = ((i + 1) * 4);
			}
		}
		printf("Four of a kind sum: %d\n", lower[2]);
		break;
		//full house
	case(9):
		check_score_option[9] = 1;
		int is_three = 0, is_pair = 0;
		for (int i = 0; i <= 5; i++) {
			if (num_die_values[i] == 3) {
				is_three = 1;
			}
			else if (num_die_values[i] == 2) {
				is_pair = 1;
			}
		}
		if (is_three == 1 && is_pair ==1) {
			lower[3] = 25;
			printf("Full house! score: %d\n", lower[3]);
		}
		else {
			lower[3] = 0;
			printf("Bad score choice... score: %d\n", lower[3]);
		}
		
		break;

		//small straight

	case(10):
		

		for (int i = 0; i <= 2; i++) { //only need to iterate through placement one and two, first sequence value must occur before or at placement two to satisfy a small stright
			if (num_die_values[i] > 0 && num_die_values[i + 1] > 0 && num_die_values[i + 2] > 0 && num_die_values[i + 3] > 0) {
				//frequency of four consecutive values must be greater than zero to satisfy small straight
				lower[4] = 30;
				printf("Small straight! score: %d\n", lower[4]);
			}

		}
		if (lower[4] != 30) { //After failing to satisfy small straight, assign score 0
			lower[4] = 0;
			printf("Bad score choice... score: %d\n", lower[4]);
		}
		break;

	case(11): // large straight

		for (int i = 0; i <= 1; i++) {
			if (num_die_values[i] > 0 && num_die_values[i + 1] > 0 && num_die_values[i + 2] > 0 && num_die_values[i + 3] > 0 && num_die_values[i + 4] > 0) {
				lower[5] = 40;
				printf("Large straight! score: %d\n", lower[5]);
			}
		 }
		if (lower[5] != 40) {
			lower[5] = 0;
			printf("Bad score choice... score: %d\n", lower[5]);
		}
		break;

	case(12): //yahtzee

		for (int i = 0; i <= 5; i++) {
			if (num_die_values[i] == 5) { //iterates through the frequency array to find if any value occured five times
				lower[6] = 50; //applies 50 to the score card if conditions are satisfied
				printf("Yahtzee!! score: %d\n", lower[6]);
			}
		}
		if (lower[6]!=50) {
			lower[6] = 0; //if yahtzee conditions aren't satisfied, return a score of zero
			printf("Bad score choice... score: %d\n", lower[6]);
		}
			break;
			//chance
	case(13): 
		
		for (int i = 0; i < 5; i++) {
			int value = die_values[i]; //find the value for each roll
			sum = sum + value; //add each consecutive roll to the sum
		}
		lower[7] = sum; //apply sum to the score card
		printf("Your score is %d\n", lower[7]);
		break; 
	}
}

//function name : void prompt_score_type(int *score_method, int check_score_option[])
//description :  prompts user to choose score type for round, type cannot be chosen more than once
//input parameters : array coresponding to chosen method and which methods have already been used up 
//output : updates which methods have been chosen, chosen method is used to determine score

void prompt_score_type(int *score_method, int check_score_option[]) {
	int method = 0;
	printf("Which score option do you choose?\n\n");
	printf("1: Sum of ones   2: Sum of twos\n");
	printf("3: Sum of threes 4: Sum of fours\n");
	printf("5: Sum of fives  6: Sum of sixes\n");
	printf("7: 3 of a kind   8: 4 of a kind\n");
	printf("9: Full house   10: Small straight\n");
	printf("11: Big straight 12: Yahtzee\n");
	printf("13: Chance\n\n");

	while ((method < 1 || method >13) || check_score_option[method] == 1)//insures that valid option is chosen, and score type is not reused
	{
		
		printf("Enter your choice: \n");
		scanf("%d", &method); 
		
	}
	check_score_option[method] = 1; //score method now used up
	
	*score_method = method; //updates score method to be used in score_roll function switch statements
}

//function name : char clear_window()
//description :  allows the console to be cleared after each player has completed their round
//input parameters : n/a
//output : clears console if user enters 'x', I unfortunately couldn't figure out a way to clear it if the user simply hit the enter key, but i tried :(

char clear_window() {

	printf("Hit 'x' to begin the next player's round: ");
		char clear_console = '\0';
		scanf(" %c", &clear_console); 
	if (clear_console == 'x' || clear_console == 'X') {
		system("cls"); // clears window if the user entered x, I couldn't figure out how to make it clear if the user hit the enter key :(
	}
	else {
		printf("You don't want to go on? Whatever...");
	}
}

//function name : void score_update(int rounds, int player_one_uppers[], int player_one_lowers[], int player_two_uppers[], int player_two_lowers[], int* player_one_sum, int* player_two_sum)
//description :  keeps track of the current score after each round, used for determining winner and informing players of their score each round
//input parameters : round number, players upper and lower score card values and accumulated total sums
//output : prints current scores

void score_update(int rounds, int player_one_uppers[], int player_one_lowers[], int player_two_uppers[], int player_two_lowers[], int* player_one_sum, int* player_two_sum) {
	// Sum player 1 uppers and lowers:
	int upper_sum = 0;
	int lower_sum = 0;

	for (int i = 1; i <= 6; i++) {
		upper_sum += player_one_uppers[i]; // Accumulate upper section scores
	}
	
	for (int i = 1; i <= 7; i++) {
		lower_sum += player_one_lowers[i]; // Accumulate lower section scores

		if (lower_sum < 0) { //for if the lower sum choice 7 is chosen, no choice 7 exists, so fills with a zero to prevent a weird negative value being used
			lower_sum = 0;
		}
	}

	// Check if upper section bonus is applicable
	if (upper_sum >= 63) {
		upper_sum += 35;
	}

	// Update player one's total score
	*player_one_sum = upper_sum + lower_sum;
	printf("Player 1 score: %d\n", *player_one_sum);

	// SAME THING FOR PLAYER 2

	int upper_sum_2 = 0;
	int lower_sum_2 = 0;

	for (int i = 1; i <= 6; i++) {
		upper_sum_2 += player_two_uppers[i]; // Accumulate upper section scores
	}

	for (int i = 1; i <= 7; i++) {
		lower_sum_2 += player_two_lowers[i]; // Accumulate lower section scores

		if (lower_sum_2 < 0) { //for if the lower sum choice 7 is chosen, no choice 7 exists, so fills with a zero to prevent a weird negative value being used
			lower_sum_2 = 0;
		}
	}

	// Check if upper section bonus is applicable
	if (upper_sum_2 >= 63) {
		upper_sum_2 += 35;
	}

	// Update player one's total score
	*player_two_sum = upper_sum_2 + lower_sum_2;
	printf("Player 2 score: %d\n", *player_two_sum);
}

//function name : void clear_dice(int num_die_values[])
//description :  clears the array coresponding to dice frequency, otherwise both player one and player two's roll frequencies are combined, messing up scoring
//input parameters : die value frequency array
//output : clears the frequency array for the next player

void clear_dice(int num_die_values[]) {
	for (int i = 0; i <= 6; i++) {
		num_die_values[i] = 0;
	}
}

//function name : void determine_winner(int* player_one_sum, int* player_two_sum)
//description :  determines which player won after all rounds are completed
//input parameters : the sum of each player's scores
//output : prints to the console a message as to who won the game

void determine_winner(int* player_one_sum, int* player_two_sum) {
	if (*player_one_sum > *player_two_sum) {
		printf("Player one wins! \n");
	}
	if (*player_one_sum < *player_two_sum) {
		printf("Player two wins! \n");
	}
}
