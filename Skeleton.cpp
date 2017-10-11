#include "stdafx.h"
#include "Skeleton.h"
#include <random>

//************************************************************************************************************************
//          Skeleton Constructor, initializes attributes.
//************************************************************************************************************************


Skeleton::Skeleton()
{
	maxHealth = 100;              // Initializes the health of the skeleton to 100
	currentHealth = maxHealth;    // Sets the initial value for current health to that of maxHealth
	attackMin = 1;                // Skeletons minimum damage
	attackMax = 5;                // Skeletons maximum damage
	experience = randNum(20, 35); // Generate a random amount of experience between 20 and 35
	active = true;                // bool value that is initialized to true and is changed to false if the player defeats the skeleton
	
	if (randNum(0, 100) <= 2) {   // condition to determine if the skeleton will have loot or not.
		lootItem = itemList.gameItems[randNum(0, itemList.gameItems.size() - 1)];
	}                             // if the condition is met then a random item is selected from the item list in the Item List class
}

//************************************************************************************************************************
//          Public setter function for player object
//************************************************************************************************************************


void Skeleton::takeDamage(const int& damage) {	
	this->currentHealth = this->currentHealth - damage;
	if (currentHealth <= 0) {
		cout << "You have slain the skeleton!" << endl << "You have gained : " << experience << " experience." << endl;
		if (lootItem.getItemName() == "") {
			cout << "The Skeleton dropped nothing!" << endl;
		}
		if (lootItem.getItemName() != "") {
			cout << "The Skeleton dropped" << endl << endl; displayLoot();
		}
		active = false;
	}
	else
	{
		cout << "Skeletons health : " << currentHealth << " / " << maxHealth << endl;
	}
}


//************************************************************************************************************************
//          Public getter function for player object
//************************************************************************************************************************


void Skeleton::enemyHealth() {
	cout << "Skeletons Health : " << currentHealth << " / " << maxHealth << endl;
}

int Skeleton::enemyAttack() {
	return randNum(attackMin, attackMax);
}


void Skeleton::displayLoot() {
	lootItem.displayItem();
}

void Skeleton::destroySkeleton(Skeleton* instance) {
	delete instance;
}

Skeleton::~Skeleton()
{
	
}