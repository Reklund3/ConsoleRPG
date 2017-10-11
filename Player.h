#pragma once
#ifndef PLAYER
#define PLAYER

#include <iostream>
#include "World.h"
using std::endl;
using std::cout;
using std::cin;

class Player:public World
{
	std::unordered_map <int, ITEMS <char*, char*, int, int, int, int, int >> PLAY_INV;
	ITEMS<char*, char*, int, int, int, int, int>* tempItem;
	Equipment equiped;
	std::string itemName;
	std::string itemSlot;

	int baseHealth;
	int baseAttackMin;
	int baseAttackMax;
	int baseArmorRating;
	int baseStrength;
	int baseVitality;
	float baseCrit;
	float baseParry;

	int level;
	int currentHealth;
	int totalExp;

	int attackMin;
	int attackMax;
	int armorRating;
	int strength;
	int vitality;

//************************************************************************************************************************
//          Private setter function for player object
//************************************************************************************************************************

	void checkLevel();


//************************************************************************************************************************
//          Private getter function for player object
//************************************************************************************************************************

public:
	Player();
//************************************************************************************************************************
//          Public setter functions for player object
//************************************************************************************************************************
	
	
	void earnEXP(const int& exp);
	void takeDamage(const int& damage);
	void setPlayerStats();
	void equipItem();


//************************************************************************************************************************
//          Public getter functions for player object
//************************************************************************************************************************


	int attack();
	void getTotalEXP();
	void getEquipedStats();
	void getStats();
	void lootEnemy(const ITEMS<char*, char*, int, int, int, int, int>& item);
	void getInventory();
	void inventoryMenu();
	virtual ~Player();
};

#endif // !PLAYER