#include <iostream>
#include "Zoo.hpp"
using namespace std;

int main(){

	cout << "Before Creation" << endl;
	Zoo LincolnParkZoo;
	char input;

	LincolnParkZoo.printZoo();
	cout << "Start the loop?" << endl;
	cin >> input;

	// While not bankrupt, progress the game.  So it'll just loop Zoo.Play(). Zoo.Play will ask the user to buy animals.

	while (input == 'y'){

				
	}
	
	LincolnParkZoo.~Zoo();
	cout << "Ending..." << endl;

	cin.get();
}