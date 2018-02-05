/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
	protected:
		int age = 0;
		int cost = 0;
		int babies = 0;
		int baseFoodCost = 0;
		int payoff = 0;
		int base = 10;

	public:
		int getAge();
		int getCost();
		int getBabies();
		int getFoodCost();
		int getPayoff();

		void setAge(int a);
		void setCost(int price);
		void setBabies(int babby);
		void setFoodCost(int feed);
		void setPayoff(int payment);
};

#endif // !ANIMAL_HPP
