/*************************
Author:Michael McCabe
Date: Janaury 19, 2018
IDE: Visual Studio
**************************/

#include <iostream>
#include <stdexcept>
#include <algorithm> //std::remove

using std::cout;
using std::endl;

template <class T>
class Cage {

private:
	size_t cageSize = 0;
	size_t cageMax = 10;
	T* cage;

	void addMoreRoom(int extraRoom);

public:
	Cage();
	void addAnimal(T newAnimal);
	void killAnimal();
	void killAnimal(size_t i);

	T getAnimal(size_t i);

	int getCageSize();
	int returnCageMax();

	T& operator[] (const int i);
	~Cage();
};

template <class T>
void Cage<T>::addMoreRoom(int extraRoom) {
	T* biggerCage = new T[extraRoom];
	for (size_t i = 0; i < cageMax; i++) {
		biggerCage[i] = cage[i];
	}
	delete[] cage;
	cage = biggerCage;
	cageMax = extraRoom;
}

template <class T>
Cage<T>::Cage() {
	cage = new T[cageMax];
}

template <class T>
void Cage<T>::addAnimal(T newAnimal) {
	if (cageSize >= cageMax) {
		addMoreRoom(cageMax * 2);
	}
	cage[cageSize] = newAnimal;
	cageSize = cageSize + 1;
}

template <class T>
void Cage<T>::killAnimal() {
	if (cageSize > 0) {
		cageSize--;
	}
}

template <class T>
void Cage<T>::killAnimal(size_t specific) {
	if (cageSize > 0) {
		for (size_t i = specific; i < cageSize; i++) {
			cage[i] = cage[i + 1];
		}
		killAnimal();
	}
}

template <class T>
T Cage<T>::getAnimal(size_t i) {
	if (i < 0 || i > cageSize) {
		throw std::out_of_range("Selected item not found");
	}
	if (cageSize > 0)
		return cage[i];
}

template <class T>
int Cage<T>::getCageSize() {
	return cageSize;
}

template <class T>
int Cage<T>::returnCageMax() {
	return cageMax;
}

template <class T>
T& Cage<T>::operator[] (const int i) {
	try {
		return cage[i];
	}
	catch (std::out_of_range &e) {
		cout << "Caught exception: " << e.what() << endl;
	}
}

template <class T>
Cage<T>::~Cage(){
	if (cage != nullptr) {
		delete[] cage;
		cageSize = 0;
		cageMax = 0;
		cage = nullptr;
	}

}