/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/


#include "Penguin.hpp"

Penguin::Penguin() {
	isFed = false;

	setAge(1);
	setCost(1000);
	setBabies(5);
	setFoodCost(base);
	setPayoff(100);
}

Penguin::Penguin(int age) {
	isFed = false;

	setAge(age);
	setCost(1000);
	setBabies(5);
	setFoodCost(base);
	setPayoff(100);
}

Penguin& Penguin::operator=(const Penguin &right) {
	if (this != &right) {
		age = right.age;
		cost = right.cost;
		babies = right.babies;
		baseFoodCost = right.baseFoodCost;
		payoff = right.payoff;
	}
	return *this;
}

bool Penguin::checkHunger() {
	return isFed;
}

void Penguin::setFed(bool hunger) {
	isFed = hunger;
}

string Penguin::getSpecies() {
	return species;

}