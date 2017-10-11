#pragma once
#include "Equipment.h"
#include <vector>
#include <unordered_map>
#include <map>
#include <random>


class World
{

public:
	ItemList itemList;
	
	World();
	
//************************************************************************************************************************
//          Public getter function for player object
//************************************************************************************************************************

	int randNum(const int& one,const int& two);

	virtual ~World();


};

template <typename T>
void displayItem(const T& container) {
	std::cout << "-----------------------" << std::endl;
	std::cout << "   " << itemName << std::endl;
	std::cout << "   " << >itemSlot << std::endl;
	std::cout << "-----------------------" << std::endl;
	if (minDamage > 0 && maxDamage > 0) { std::cout << "Weapon Damage  : " << minDamage << " - " << maxDamage << std::endl; }
	if (armorRating > 0) { std::cout << "Armor Rating   : " << armorRating << std::endl; }
	if (strength > 0) { std::cout << "Strength       : " << strength << std::endl; }
	if (vitality > 0) { std::cout << "Vitality       : " << vitality << std::endl; }
	std::cout << std::endl;
}
