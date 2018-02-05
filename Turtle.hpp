/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"
#include <string>

using std::string;

class Turtle : public Animal {

protected:
	bool isFed = false;
	string species = "TURTLE";

public:
	Turtle();
	Turtle(int age);

	bool checkHunger();
	void setFed(bool fed);

	string getSpecies();
	Turtle& operator=(const Turtle& right);
};


#endif // !TURTLE_HPP
