/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
The menu creates an interface between the gameEngine and the user, but also helps me use some helpful things that I can use in future projects
**************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

#include <string> // used primarily for getInt
#include <sstream> // used primarily for getInt

#include <ctime> // random position for Ant
#include <cstdlib> // random position for Ant

enum state { greeting, settings, playable}; // prototype, basically to make the Menu into a tree

class menu {
private:
	
	// Generic menu variables
	state runState;

	void setState(state progress);
	void prompt(); // the outer loop
	void options(); // displays game specific options, but this is customizable
	int getInt(const std::string prompt); // takes a prompt, gets only positive integers
	
public:
	// Menu specific
	menu();
	void refresh(); // when you wrap a game in a loop, run refresh to set all member values back to their defaults
	state getState();

	
};
#endif // !MENU_HPP