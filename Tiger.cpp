/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/
#include <iostream>

#include "Tiger.hpp"

Tiger::Tiger() {
	isFed = false;

	setAge(1);
	setCost(10000);
	setBabies(1);
	setFoodCost(base * 5);
	setPayoff(2000);
}

Tiger::Tiger(int age) {
	isFed = false;

	setAge(age);
	setCost(10000);
	setBabies(1);
	setFoodCost(base * 5);
	setPayoff(2000);
}

Tiger& Tiger::operator=(const Tiger &right) {
	if (this != &right) {
		age = right.age;
		cost = right.cost;
		babies = right.babies;
		baseFoodCost = right.baseFoodCost;
		payoff = right.payoff;
	}
	return *this;
}

bool Tiger::checkHunger() {
	return isFed;
}

void Tiger::setFed(bool hunger) {
	isFed = hunger;
}

string Tiger::getSpecies(){
	return species;

}