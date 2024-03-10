#include "header.h"

//function name: void roll_dice(int* dice, int size)
//description: generates random values for dice rolls, each value is stored in an array
//input parameters: address for the dice array, size of the array
//output: random dice rolls stored in the array

void roll_dice(int* die_values)
{
	for (int index = 0; index < 6; ++index) 
	{
		die_values[index] = rand() % 6 + 1;
		//don't need to return value, because arrays are pointers
	}
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
	int player_1_rolls[7] = {0};
	int player2_rolls[7] = {0};

	int die_values[6] = {0}; //dice rolls for each roll
	int num_die_values[7] = { 0 }; //stores each roll in an array, allows user to change rolls by assigning an index value for each dice value


	rounds = 1;
	while (rounds <= 13) {

		printf("It is player 1's turn: \n");
		roll_again(die_values);
		prompt_roll_again(die_values);


		

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

	for (int i = 1; i < 6; ++i) {
		printf("%d", die_values[i]);
	}
	printf("\n");
}


void prompt_roll_again(char* go_again_ptr) {
	char wanna_roll = '\0';
	printf("Want to roll again? [Y/N]: ");
	scanf(" %c", &wanna_roll);
	if (wanna_roll == 'y' || wanna_roll == 'Y') {
		*go_again_ptr = 'Y';
	}
	else {
		*go_again_ptr = '\0';
	}
}

	void roll_again(int die_values[]) {
		//Variables initialized
		int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, how_many = 0, counter = 1;
		char wanna_roll_again = '\0';

		//Die rolled and printed (first roll); User prompted to roll again
		roll_dice(die_values);
		print_dice(die_values, counter);
		prompt_roll_again(&wanna_roll_again);
		counter += 1;

		//Second and third roll (if necessary)
		do {
			if (wanna_roll_again == '\0') {
				break;
			}
			//Prompts for how many die should be kept
			do {
				printf("How many do you want to keep? ");
				scanf("%d", &how_many);
			} while (how_many < 0 || how_many > 5);

			//Prompts for which ones should be kept; re-rolls the others
			switch (how_many) {
			case 0: roll_dice(die_values);
				break;

			case 1: printf("Which one do you want to keep? (1-5, left to right): ");     //Add while loops to make the user enter valid numbers
				scanf("%d", &i1);
				for (int i = 1; i < 6; i++) {
					if (i == i1) {
						continue;
					}
					else {
						die_values[i] = rand() % 6 + 1;
					}
				}
				break;

			case 2: printf("Which ones do you want to keep? (1-5, left to right): ");
				scanf("%d%d", &i1, &i2);
				for (int i = 1; i < 6; i++) {
					if (i == i1 || i == i2) {
						continue;
					}
					else {
						die_values[i] = rand() % 6 + 1;
					}
				}
				break;

			case 3: printf("Which ones do you want to keep? (1-5, left to right): ");
				scanf("%d%d%d", &i1, &i2, &i3);
				for (int i = 1; i < 6; i++) {
					if (i == i1 || i == i2 || i == i3) {
						continue;
					}
					else {
						die_values[i] = rand() % 6 + 1;
					}
				}
				break;

			case 4: printf("Which ones do you want to keep? (1-5, left to right): ");
				scanf("%d%d%d%d", &i1, &i2, &i3, &i4);
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
			printf("Here's your reroll bitch: ");
			print_dice(die_values, counter); //counter 
			if (counter < 3) {
				prompt_roll_again(&wanna_roll_again);
			}
			counter += 1;
		} while (wanna_roll_again == 'Y' && counter <= 3);

	}


	//function name : void roll_again(int die_values[])
//description : asks the user if they want to reroll any of their dice, max of 3 times
//input parameters : random dice roll values
//output : rerolls chosen dice and prints to console
//
//void roll_again(int die_values[]) {
//	int rerolls = 0;
//	char choice = '\0';
//	int i1=0, i2=0, i3=0, i4=0, i5=0, i6=0; //integer corresponding to each dice value in the array, allows for rerolling 
//
//	printf("do you want to reroll any dice?, enter 'Y' for yes and 'N' for no: \n"); //ADD CASE FUNCTION
//	scanf(" %c", &choice);
//	printf("choice = %c", choice);
//
//	do { //3
//
//		if (choice == 'Y') {
//			//function to choose which dice to reroll
//			printf("we do be rerolling XD\n"); 
//			int how_many = 0;
//
//			printf("So how many dice do you want to reroll?\n");
//			scanf("%d", &how_many);
//
//			switch (how_many) {
//			case 0:
//				break;
//			case 1:
//				printf("Which dice do you want to keep?\n");
//				scanf("%d", &i1);
//				for (int i = 1; i < 6; ++i) {
//					if (i == i1) {
//						continue; //retains original values
//					}
//					else {
//						die_values[i] = rand() % 6 + 1; //rolls values that player doesn't want to keep
//					}
//				}
//				break;
//			case 2:
//				printf("Which dice do you want to keep?\n");
//				scanf("%d%d", &i1, &i2);
//
//				for (int i = 1; i < 6; ++i) { //applies user input to the coresponding dice value in sequence
//					if (i == i1 || i == i2) { //retains original values
//						continue;
//					}
//					else {
//						die_values[i] = rand() % 6 + 1;
//					}
//				}
//				break;
//
//			case 3:
//				printf("Which dice do you want to keep?\n");
//				scanf("%d%d%d", &i1, &i2, &i3);
//
//				for (int i = 1; i < 6; ++i) { //applies user input to the coresponding dice value in sequence
//					if (i == i1 || i == i2 || i == i3) { //retains original values
//						continue;
//					}
//					else {
//						die_values[i] = rand() % 6 + 1;
//					}
//				}
//				break;
//
//			case 4:
//				printf("Which die do you want to keep?\n");
//				scanf("%d%d%d%d", &i1, &i2, &i3, &i4);
//
//				for (int i = 1; i < 6; ++i) { //applies user input to the coresponding dice value in sequence
//					if (i == i1 || i == i2 || i == i3 || i == i4) { //retains original values
//						continue;
//					}
//					else {
//						die_values[i] = rand() % 6 + 1;
//					}
//				}
//				break;
//			case 5: break; 
//
//			}
//
//			print_dice(die_values);
//
//			//printf("Your new roll looks like: ");
//			//for (int i = 1; i < 6; ++i) {
//			//	printf("%d", die_values[i]);
//			//}
//				
//				//reroll function
//				rerolls++;
//
//
//		}
//
//	} while (rerolls < 3 || choice == 'Y');
//
//
//		if (choice == 'N') {
//			printf("fine, keep your dice ig... \n");
//			return;
//		}
//		if (choice != 'N' && choice != 'Y') {
//			printf("Invalid option...\n");
//		}
//
//		
//	}