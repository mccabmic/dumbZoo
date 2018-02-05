/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"
#include <string>

using std::string;

class Tiger : public Animal{

protected:
	bool isFed = false;
	string species = "TIGER";

public:
	Tiger();
	Tiger(int age);

	bool checkHunger();
	void setFed(bool fed);

	string getSpecies();
	Tiger& operator=(const Tiger& right);
};

#endif // !TIGER_HPP
