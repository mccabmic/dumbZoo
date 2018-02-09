/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/

#include "menu.hpp"

/* Default constructor for menu initializes all values
and displays the prompt and sets the phase to greeting
*/
menu::menu() {	

	runState = greeting;
	prompt();
}

/* Refreshes the class variables and displays
the prompt and sets the phase to greeting
*/
void menu::refresh() {

	setState(greeting);
	prompt();
}

state menu::getState() {
	return runState;
}


void menu::setState(state status) {
	runState = status;
}

/*
Allows the user to set's the ant position.  If the board hasn't been set, the user should not be able to
set a random position until they tell us what board size they want.
*/

void menu::prompt() {
	int input;

	std::cout << "Welcome to Zoo Tychoon! Please make your selection below: " << std::endl;
	std::cout << "1: Play Zoo Tychoon" << std::endl;
	std::cout << "2: Quit " << std::endl;

	input = getInt("Please enter your selection: ");

	if (input == 1) {
		std::cout << "Continuing to options..." << std::endl;
		setState(settings);
		options();
	}
	else if (input == 2) {
		std::cout << "Quitting..." << std::endl;
	}
}

void menu::options() {

	int input;
	std::cout << "--------------------Options: ------------------" << std::endl;


	input = getInt("Please enter in your settings: ");
}

int menu::getInt(const std::string prompt) {
	int integer;
	std::string input;

	bool isValid = true;

	do {
		std::cout << prompt;
		std::getline(std::cin, input);

		// Loop through all characters and determine if they are a digit or not
		// TODO - make a flag for positive or negatives allowed
		for (int i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])){
				std::cout << "Invalid input" << std::endl;
				isValid = false;
				break;
			}

			else {
				isValid = true;
			}
		}
	} while (isValid == false);

	// After scrubbing, cast the input into an integer
	std::stringstream ss(input);
	ss >> integer;

	return integer;
}
