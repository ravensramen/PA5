#include "header.h"

int main(void) {
	srand((time(NULL)));

	int user_choice = 0;

	printf("Welcome to the Yahtzee!\n\n");
	do {

		user_choice = determine_user_choice();

		switch (user_choice) {
		case 1: display_rules();
			break;
		case 2:
			yahtzee_gameplay();
			break;
		case 3:
			printf("goodbye");
			return 0;
		}
		//system('cls')
	} while (user_choice != 3);

	return 0;
}
