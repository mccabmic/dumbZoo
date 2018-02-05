#ifndef TIGERCAGE_HPP
#define TIGERCAGE_HPP

#include <iostream>
#include "Tiger.hpp"
#include <stdexcept>
#include <algorithm> //std::remove

using std::cout;
using std::endl;

class tigerCage {

private:
	size_t cageSize = 0;
	size_t cageMax = 10;
	Tiger* cage = nullptr;

	void addMoreRoom(int extraRoom);

public:
	tigerCage();
	void addTiger(Tiger& newAnimal);
	void killTiger();
	void killTiger(int i);

	Tiger getTiger(int i);

	int getCageSize();
	int returnCageMax();

	Tiger& operator[] (const int i);
	~tigerCage();
};

#endif // !TIGERCAGE_HPP