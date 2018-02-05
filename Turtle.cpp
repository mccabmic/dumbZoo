/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/

#include "Turtle.hpp"

Turtle::Turtle() {
	isFed = false;

	setAge(1);
	setCost(100);
	setBabies(10);
	setFoodCost(base * .5);
	setPayoff(5);
}

Turtle::Turtle(int age) {
	isFed = false;

	setAge(age);
	setCost(100);
	setBabies(10);
	setFoodCost(base * .5);
	setPayoff(5);
}

Turtle& Turtle::operator=(const Turtle &right) {
	if (this != &right) {
		age = right.age;
		cost = right.cost;
		babies = right.babies;
		baseFoodCost = right.baseFoodCost;
		payoff = right.payoff;
	}
	return *this;
}

bool Turtle::checkHunger() {
	return isFed;
}

void Turtle::setFed(bool hunger) {
	isFed = hunger;
}

string Turtle::getSpecies() {
	return species;

}