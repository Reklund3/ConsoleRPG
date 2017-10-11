#include "stdafx.h"
#include "ITEMS.h"

ITEMS<char*, char*, int, int, int, int, int>::~ITEMS() { }

void ITEMS<char*, char*, int, int, int, int, int>::displayItem() {
	std::cout << "-----------------------" << std::endl;
	std::cout << "   " << this->itemName << std::endl;
	std::cout << "   " << this->itemSlot << std::endl;
	std::cout << "-----------------------" << std::endl;
	if (this->minDamage > 0 && this->maxDamage > 0) { std::cout << "Weapon Damage  : " << this->minDamage << " - " << this->maxDamage << std::endl; }
	if (this->armorRating > 0) { std::cout << "Armor Rating   : " << this->armorRating << std::endl; }
	if (this->strength > 0) { std::cout << "Strength       : " << this->strength << std::endl; }
	if (this->vitality > 0) { std::cout << "Vitality       : " << this->vitality << std::endl; }
	std::cout << std::endl;
}

