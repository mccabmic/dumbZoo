#include "Zoo.hpp"

/*Zoo Constructor*/
Zoo::Zoo(){
	int money = 100000;
	bonus = 0;
	bankrupt = false;
	days = 0;

	/*srand(time(0));

	for (int i = 0; i < 15; i++) {
		int zooSeed = rand() % 100;

		if (zooSeed < 25) {
			Tiger newTiger;
			tigerExhibit.addAnimal(newTiger);
		}

		else if (zooSeed < 50) {
			Turtle newTurtle;
			turtleExhibit.addAnimal(newTurtle);
		}

		else {
			Penguin newPenguin;
			penguinExhibit.addAnimal(newPenguin);
		}
	}*/
}

void Zoo::buyAnimals() {

	if (days == 0) {
		cout << "new set up" << endl;
	}

	else {

	}
	Tiger newTiger;
	tigerExhibit.addAnimal(newTiger);

	Turtle newTurtle;
	turtleExhibit.addAnimal(newTurtle);

	Penguin newPenguin;
	penguinExhibit.addAnimal(newPenguin);
	// If Days is 0, then new Zoo setup
	
	// So add 1 day old animals
	// Otherwise add 3 day old animals.
}

void Zoo::Play() {
	
	menu MainMenu;
	// while prompt == go ahead and play
	MainMenu.prompt();
	buyAnimals();
	// BuyAnimals
	// AgeAnimals
	ageZoo();
	randomEvent();
	money = getProfit() + bonus;
	bonus = 0;
	// Calculate Profit and add it to the bank
	// loop back, ask if they want to buy ONE animal, adult.  3 days old.  
	// after that day official ends. ask them if they want to keep playing if they have money
	// if they dom't have money, end the game
}
bool Zoo::getBankruptcyStatus() {
	return (bankrupt);
}
/*Handles random events based on feed.  Ultimately, this function will return:
1 for Sickness Event
2 for a Boom Event
3 for a Baby Event
4 for Nothing

Extra credit: FeedType affects the chance of being sick
*/
int Zoo::randomHandler() {
	int eventToChoose = 0;
	
	if (foodStock == luxury) {
		// 1 in 8 chance instead of 1 in 4
		eventToChoose = rand() % 8 + 1;
		if (eventToChoose == 1)
			return 1;
		else
			return (rand() % 3 + 2); // return either 2, 3, or 4
	}

	else if (foodStock == cheap) {
		// Coin flip, 1 in 2 chance of getting sick
		eventToChoose = rand() % 2 + 1;
		if (eventToChoose == 1) {
			return 1;
		}

		else {
			eventToChoose = rand() % 4 + 1;
			if (eventToChoose != 1) {
				return 1;
			}
			// Nothing happens
			else {
				return 4;
			}
		}
	}

	else {
		return (rand() % 4 + 1);
	}

}

void Zoo::randomEvent() {
	int eventToChoose = randomHandler();
	
	bonus = 0;
	// Sickness
	if (eventToChoose == 1) {
		sicknessEvent();
	}
	// Boom
	else if (eventToChoose == 2) {
		boomEvent();
	}
	// Baby
	else if (eventToChoose == 3) {
		babyEvent();
	}
}

/*Picks an animal type at random then kills that specific animal.*/
void Zoo::sicknessEvent() {
	
	std::ofstream sicknessFile;
	sicknessFile.open("sicknessLog.txt", std::ios::app);

	int speciesToDie = rand() % numSpecies;
	int animalToDie;

	int totalTigers = tigerExhibit.getCageSize();
	int totalPenguins = penguinExhibit.getCageSize();
	int totalTurtles = turtleExhibit.getCageSize();

	if (speciesToDie == 0 && totalTigers != 0) {
		animalToDie = rand() % totalTigers;
		tigerExhibit.killAnimal(animalToDie);
		sicknessFile << "Tiger #" << animalToDie << " got sick and went to the animal hospital.\n";
	}
	else if (speciesToDie == 1 && totalPenguins!= 0) {
		animalToDie = rand() % totalPenguins;
		penguinExhibit.killAnimal(animalToDie);
		sicknessFile << "Penguin #" << animalToDie << " got sick and went to the animal hospital.\n";
	}
	else if (speciesToDie == 2 && totalTurtles != 0){
		animalToDie = rand() % totalTurtles;
		turtleExhibit.killAnimal(animalToDie);
		sicknessFile << "Turtle #" << animalToDie << " got sick and went to the animal hospital.\n";
	}
	else {
		cout << "No animal got sick today" << endl;
	}

	sicknessFile.close();
}
/* Calculates profit per animal.  Design will take into account if special animals have higher Payoffs*/
double Zoo::getProfit() {
	double tigerRevenue = 0;
	double turtleRevenue = 0;
	double penguinRevenue = 0;

	for (int i = 0; i < tigerExhibit.getCageSize(); i++) {
		tigerRevenue += tigerExhibit[i].getPayoff();
	}

	for (int i = 0; i < turtleExhibit.getCageSize(); i++) {
		turtleRevenue += turtleExhibit[i].getPayoff();
	}

	for (int i = 0; i < penguinExhibit.getCageSize(); i++) {
		penguinRevenue += penguinExhibit[i].getPayoff();
	}

	return (tigerRevenue + turtleRevenue + penguinRevenue);
}

/*Returns the feed cost for each animal. Uses FeedType to determine how to be fed*/
double Zoo::getFeedCost(feedType Feed) {

	foodStock = Feed;
	
	double tigerFeed = 0;
	double turtleFeed = 0;
	double penguinFeed = 0;

	for (int i = 0; i < tigerExhibit.getCageSize(); i++) {
		tigerFeed += tigerExhibit[i].getFoodCost();
	}

	for (int i = 0; i < turtleExhibit.getCageSize(); i++) {
		turtleFeed += turtleExhibit[i].getFoodCost();
	}

	for (int i = 0; i < penguinExhibit.getCageSize(); i++) {
		penguinFeed += penguinExhibit[i].getFoodCost();
	}


	if (foodStock == cheap) {
		return (0.5 * (tigerFeed + turtleFeed + penguinFeed));
	}

	else if (foodStock == standard) {
		return (1.0 * (tigerFeed + turtleFeed + penguinFeed));
	}

	else {
		return (2.0 * (tigerFeed + turtleFeed + penguinFeed));
	}
}

void Zoo::babyEvent() {

	std::ofstream babyEvent;
	babyEvent.open("babyEventLog.txt", std::ios::app);
	int randomSelection = rand() % numSpecies;
	int numBabies = 0;
	bool babyTime = false;

	// Random selection for Tigers
	if (randomSelection == 0) {
		// Check the ages of the animals, and get how many babies they would need
		for (int i = 0; i < tigerExhibit.getCageSize(); i++) {
			if (tigerExhibit[i].getAge() >= 3) {
				babyTime = true;
			}
		}

		// Add a baby
		if (babyTime == true) {
			Tiger newTiger(0);
			tigerExhibit.addAnimal(newTiger);
			babyEvent << "There are new Tiger babies!\n";
			babyEvent.close();
			return;
		}
	}

	// Penguins
	else if(randomSelection == 1) {
		// Check the ages of the animals, and get how many babies they would need
		for (int i = 0; i < penguinExhibit.getCageSize(); i++) {
			if (penguinExhibit[i].getAge() >= 3) {
				numBabies = penguinExhibit[i].getBabies();
				babyTime = true;
			}
		}

		// Add a baby
		if (babyTime == true) {
			Penguin baby(0);
			for (int i = 0; i < numBabies; i++)
				penguinExhibit.addAnimal(baby);

			babyEvent << "There are new Penguin babies!\n";
			babyEvent.close();
			return;
		}
	}
	
	// Turtles
	else {
		// Check the ages of the animals, and get how many babies they would need
		for (int i = 0; i < turtleExhibit.getCageSize(); i++) {
			if (turtleExhibit[i].getAge() >= 3) {
				numBabies = turtleExhibit[i].getBabies();
				babyTime = true;
			}
		}

		// Add a baby
		if (babyTime == true) {
			Turtle baby(0);
			babyEvent << "There are new Turtle babies!\n";
			for (int i = 0; i < numBabies; i++)
				turtleExhibit.addAnimal(baby);
		}

		babyEvent.close();
		return;
	}
}

Zoo::~Zoo(){
	turtleExhibit.~Cage();
	penguinExhibit.~Cage();
	tigerExhibit.~Cage();
}

/*Calculates and returns the bonus amount for the day - 0 if no tigers, up to 500 per tiger*/
void Zoo::boomEvent() {

	std::ofstream bonusFile;
	bonusFile.open("bonusLog.txt", std::ios::app);

	int randomBonus = rand() % 250 + 250;

	bonusFile << "Today is National Tiger Day! Tigers generate money today! You made: " << randomBonus << " extra dollars for each tiger you own!\n";
	bonus = randomBonus * tigerExhibit.getCageSize();
}

/*Prints the species and age of all the exhibits*/
void Zoo::printZoo() {
	for (int i = 0; i < tigerExhibit.getCageSize(); i++) {
		Tiger thisTiger = tigerExhibit.getAnimal(i);
		cout << tigerExhibit[i].getSpecies() << i << " Age: " << thisTiger.getAge()<< endl;
		}
	
	for (int i = 0; i < turtleExhibit.getCageSize(); i++) {
		Turtle thisTurtle = turtleExhibit.getAnimal(i);
		cout << turtleExhibit[i].getSpecies() << i << " Age: " << thisTurtle.getAge() << endl;
		}

	for (int i = 0; i < penguinExhibit.getCageSize(); i++) {
		Penguin thisPenguin = penguinExhibit.getAnimal(i);
		cout << penguinExhibit[i].getSpecies() << i << " Age: " << thisPenguin.getAge() << endl;
	}
}

/*Ages each animal object in the zoo*/
void Zoo::ageZoo() {

	days += 1;

	// Age Tigers
	for (int i = 0; i < tigerExhibit.getCageSize(); i++) {
		int age = tigerExhibit[i].getAge();
		tigerExhibit[i].setAge(age + 1);
	}

	// Age Penguins
	for (int i = 0; i < penguinExhibit.getCageSize(); i++) {
		int age = penguinExhibit[i].getAge();
		penguinExhibit[i].setAge(age + 1);
	}

	// Age Turtles
	for (int i = 0; i < turtleExhibit.getCageSize(); i++) {
		int age = turtleExhibit[i].getAge();
		turtleExhibit[i].setAge(age + 1);
	}
}

