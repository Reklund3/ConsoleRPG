#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	baseHealth = 200;
	baseAttackMin = 20;
	baseAttackMax = 40;
	baseArmorRating = 0;
	baseStrength = 0;
	baseVitality = 0;
	baseCrit = 10;
	baseParry = 5;

	level = 0;
	currentHealth = 200;
	totalExp = 999;

	attackMin = baseAttackMin;
	attackMax = baseAttackMax;
	armorRating = baseArmorRating;
	strength = baseStrength;
	vitality = baseVitality;

	PLAY_INV.insert(std::make_pair(1, itemList.gameItems[0]));	
	PLAY_INV.insert(std::make_pair(2, itemList.gameItems[5]));
	getInventory();
	equipItem();

}

//************************************************************************************************************************
//          Private setter functions for player object
//************************************************************************************************************************

//    Check Level function is called when player earns experience to check if the player has leveled up
//    If the condition is met then 1000 experience points are removed from the players total experience points
//    and adding one level to the players level
void Player::checkLevel() {
	if (this->totalExp >= 1000) {
		level++;
		totalExp = totalExp - 1000;
		cout << "Congratulation, you are now level " << level << "!" << endl;
	}
}


//************************************************************************************************************************
//          Private getter functions for player object
//************************************************************************************************************************


//************************************************************************************************************************
//          Public setter functions for player object
//************************************************************************************************************************


void Player::earnEXP(const int& exp) {
	totalExp = totalExp + exp;
	this->checkLevel();
}

void Player::takeDamage(const int& damage) {
	if (randNum(0, 100) <= baseParry) {
		cout << "You have parried and take 0 damage" << endl;
	}
	else {
		cout << "Skeleton attacks for :  " << damage << " damage!" << endl;
		currentHealth = currentHealth - damage;
	}
	cout << "Player health : " << currentHealth << " / " << baseHealth << endl;
}

void Player::setPlayerStats() {
	attackMin = baseAttackMin + equiped.getMinWeaponDamage();
	attackMax = baseAttackMax + equiped.getMaxWeaponDamage();
	armorRating = baseArmorRating + equiped.getArmorRating();
	strength = baseStrength + equiped.getStrength();
	vitality = baseVitality + equiped.getVitality();
}

void Player::equipItem() {
	int x;
	cout << endl << "Which item slot would you like to equip?";
	cin >> x;
	cout << endl;
	equiped.equipItem(PLAY_INV.find(x)->second);
	PLAY_INV[x] = equiped.returnEquipedItem();
	equiped.clearReturnItem();
	setPlayerStats();
}

//************************************************************************************************************************
//          Public getter functions for player object
//************************************************************************************************************************


int Player::attack() {
	int randAttack = randNum(attackMin, attackMax);
	if (randNum(0, 100) <= this->baseCrit) {
		randAttack = randAttack * 1.5;
		cout << "YOU HAVE SCORED A CRITICAL HIT!" << endl;
	}
	cout << "Player attacks for :  " << randAttack << " damage!" << endl;
	return randAttack;
}

void Player::getTotalEXP() { 
	cout << "Your current exp is : " << totalExp << endl;
}

void Player::getEquipedStats() {
	equiped.stats();
}

void Player::getStats() {
	std::cout << "Health            : " << this->currentHealth << " / " << this->baseHealth << std::endl;
	std::cout << "Weapon Damage     : " << this->attackMin << " - " << this->attackMax << std::endl;
	std::cout << "Armor Rating      : " << this->armorRating << std::endl;
	std::cout << "Strength          : " << this->strength << std::endl;
	std::cout << "Vitality          : " << this->vitality << std::endl;
	std::cout << std::endl;
	std::cout << "experience : " << this->totalExp << " / 1000" << std::endl;
	std::cout << std::endl;
}

void Player::lootEnemy(const ITEMS<char*, char*, int, int, int, int, int>& item) {
	tempItem = new ITEMS<char*, char*, int, int, int, int, int>;
	*tempItem = item;
	if (tempItem->getItemName() == "") {
		cout << endl << endl;
	}
	else {
		//playerInventory.push_back(item);
		cout << "Looted!" << std::endl;
	}
	tempItem->~ITEMS();
}

void Player::getInventory() {
	tempItem = new ITEMS<char*, char*, int, int, int, int, int>;
	cout << "Player Inventory" << endl << "---------------" << endl;
	for (auto element = PLAY_INV.cbegin(); element != PLAY_INV.cend(); element++) {
		cout << "Inventory Slot : " << element->first << endl;
		*tempItem = element->second;
		tempItem->displayItem();
		cout << endl;
	}
	tempItem->~ITEMS();
}

void Player::inventoryMenu() {
	int x = 0;
	cout << "---------------------------" << endl;
	cout << "Inventory Menu" << endl;
	cout << "1. Equip Item" << endl;
	cout << "2. Exit Inventory" << endl;
	cout << "---------------------------" << endl;
	cout << "What action would you like to take? ";
	cout << endl;
	cin >> x;
	if (x == 1) {
		this->equipItem();
	}
	else if (x == 2) {
		system("CLS");
	}
}

Player::~Player()
{
}
