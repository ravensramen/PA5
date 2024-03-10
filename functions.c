#include "header.h"

void sort_array(int array[], int size) {
	int temp = 0;
	for (int i = 0; i < (size - 1); i++) {
		for (int j = 0; j < (size - i - 1); j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

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
	//for (int i = 0; i < size; i++)
	//{
	//	die_values[i] = rand() % 6 + 1;
	//	//don't need to return value, because arrays are pointers
	//}
}


//function name:void display_rules(void)
//description: displays the rules to the console
//input parametes: none
//output: displays menu

void display_rules(void) {
	printf("Here are the rules:\n\n");
	printf("Each player will take turns rolling six dice\n");
	printf("Your goal is to achieve high-scoring dice combinations.\n");
	printf("You can reroll any chosen dice a total of 3 times\n");
	printf("After that, you will be prompted to choose one of seven scoring combinations\n");
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
	int player_1_rolls[6] = { 0 };
	int player2_rolls[6] = { 0 };

	int die_values[6] = { 0 }; //dice rolls for each roll
	int num_die_values[6] = { 0 }; //stores each roll in an array, allows user to change rolls by assigning an index value for each dice value


	rounds = 1;
	while (rounds <= 13) {

		printf("ROUND %d\n", rounds);
		printf("It is player 1's turn: \n");
		roll_and_check(die_values);
		//function to organize values by frequency
		// 
		//function to choose and validate score type

		printf("It is player 2's turn: \n");
		

		++rounds;
	}

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


void prompt_roll_again(char* go_again_ptr) {
	char wanna_roll = '\0';
	printf("Want to reroll any dice? (Enter 'Y' for yes and 'N' for no: ");
	scanf(" %c", &wanna_roll);
	if (wanna_roll == 'y' || wanna_roll == 'Y') {
		*go_again_ptr = 'Y';
	}
	else {
		*go_again_ptr = '\0';
	}
}

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
