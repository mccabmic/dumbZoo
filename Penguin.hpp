/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"
#include <string>

using std::string;

class Penguin : public Animal {

protected:
	bool isFed = false;
	string species = "PENGUIN";

public:
	Penguin();
	Penguin(int age);

	bool checkHunger();
	void setFed(bool fed);

	string getSpecies();
	Penguin& operator=(const Penguin& right);
};


#endif // !PENGUIN_HPP
