#include "tigerCage.hpp"

using std::cout;
using std::endl;

void tigerCage::addMoreRoom(int extraRoom) {
	Tiger* biggerCage = new Tiger[extraRoom];
	for (int i = 0; i < cageMax; i++) {
		biggerCage[i] = cage[i];
	}
	delete[] cage;
	cage = biggerCage;
	cageMax = extraRoom;
}

tigerCage::tigerCage() {
	cage = new Tiger[cageMax];
}

void tigerCage::addTiger(Tiger& newAnimal) {
	if (cageSize >= cageMax) {
		addMoreRoom(cageMax * 2);
	}
	cage[cageSize] = newAnimal;
	cageSize = cageSize + 1;
}

void tigerCage::killTiger() {
	if (cageSize > 0) {
		cageSize--;
		cage[cageSize].~Tiger();
		cout << "Tiger destroyed" << endl;
	}
}

void tigerCage::killTiger(int specific) {
	if (cageSize > 0) {
		for (int i = specific; i < cageSize; i++) {
			cage[i] = cage[i + 1];
		}

		killTiger();
	}
}

Tiger tigerCage::getTiger(int i) {
	if (i < 0 || i > cageSize) {
		throw std::out_of_range("Selected item not found");
	}
	return cage[i];
}

int tigerCage::getCageSize() {
	return cageSize;
}

int tigerCage::returnCageMax() {
	return cageMax;
}

Tiger& tigerCage::operator[] (const int i) {
	try {
		return cage[i];
	}
	catch (std::out_of_range &e) {
		cout << "Caught exception: " << e.what() << endl;
	}
}

tigerCage::~tigerCage() {
	if (cage != nullptr)
		delete[] cage;
}
