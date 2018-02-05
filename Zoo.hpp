/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/

#ifndef ZOO_HPP
#define ZOO_HPP

// Custom vector class
#include "Cage.hpp"

// Animals
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"

#include <ctime> // random seed
#include <fstream> // output stuff to a file
#include <iostream>

enum feedType{cheap, standard, luxury};

class Zoo {
private:
	int numSpecies = 3;
	feedType foodStock = standard;

	int money, bonus;
	bool bankrupt;
	int days;

	Cage<Turtle> turtleExhibit;
	Cage<Tiger> tigerExhibit;
	Cage<Penguin> penguinExhibit;
	
public:
	Zoo();
	~Zoo();

	void printZoo();
	void ageZoo();

	void babyEvent();
	void randomEvent();
	int randomHandler();
	void sicknessEvent();
	void boomEvent();

	void buyAnimals();
	int getMoney();
	bool getBankruptcyStatus();
	void Play();


	double getFeedCost(feedType feed);
	double getProfit();
};

#endif // !ZOO_HPP
