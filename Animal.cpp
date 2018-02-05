/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/

#include "Animal.hpp"

int Animal::getAge() { return age; }
int Animal::getCost() { return cost; }
int Animal::getBabies() { return babies; }
int Animal::getFoodCost() { return baseFoodCost; }
int Animal::getPayoff() { return payoff; }

void Animal::setAge(int a) { age = a; }
void Animal::setCost(int price) { cost = price; }
void Animal::setBabies(int babby) { babies = babby; }
void Animal::setFoodCost(int feed) { baseFoodCost = feed; }
void Animal::setPayoff(int payment) { payoff = payment; }