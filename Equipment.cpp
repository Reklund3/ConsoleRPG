#include "stdafx.h"
#include <string>
#include <iostream>
#include "Equipment.h"


using std::string;
using std::cout;
using std::endl;

Equipment::Equipment()
{
	minDamage = 0;
	maxDamage = 0;

	armorRating = 0;
	strength = 0;
	vitality = 0;

	EquipedChest.setItem  ("Beginners Chest", "Chest", 0, 0, 0, 0, 0);							// define the attribute of Chest of Light item
	EquipedBoot.setItem  ("Beginners Boots", "Boot", 0, 0, 0, 0, 0);							// define the attribute of Dull Sword item
	EquipedGlove.setItem ("Beginners Gloves", "Glove", 0, 0, 0, 0, 0);							// define the attribute of Boots of Dawn item
	EquipedPant.setItem  ("Beginners Pants", "Legging", 0, 0, 0, 0, 0);							// define the attribute of Gloves of Justice item
	EquipedWeapon.setItem ("Broken Sword", "Weapon", 0, 0, 0, 0, 0);							// define the attribute of Pants of Destiny item


}


//************************************************************************************************************************
//          Private setter function for player object
//************************************************************************************************************************


void Equipment::updateStats() {
	this->armorRating	= EquipedChest.getArmorRating() + EquipedBoot.getArmorRating()  + EquipedGlove.getArmorRating()  	+ EquipedPant.getArmorRating()	+ EquipedWeapon.getArmorRating() ;
	this->strength		= EquipedChest.getStrength()	+ EquipedBoot.getStrength()	    + EquipedGlove.getStrength()		+ EquipedPant.getStrength()  	+ EquipedWeapon.getStrength()    ;
	this->vitality		= EquipedChest.getVitality()	+ EquipedBoot.getVitality()	    + EquipedGlove.getVitality()		+ EquipedPant.getVitality()	    + EquipedWeapon.getVitality()    ;
	this->minDamage		= EquipedChest.getMinDamage()	+ EquipedBoot.getMinDamage()	+ EquipedGlove.getMinDamage()		+ EquipedPant.getMinDamage()	+ EquipedWeapon.getMinDamage()   ;
	this->maxDamage		= EquipedChest.getMaxDamage()	+ EquipedBoot.getMaxDamage()	+ EquipedGlove.getMaxDamage()		+ EquipedPant.getMaxDamage()	+ EquipedWeapon.getMaxDamage()   ;
}


//************************************************************************************************************************
//          Private setter function for player object
//************************************************************************************************************************




//************************************************************************************************************************
//          Public setter function for player object
//************************************************************************************************************************


void Equipment::equipItem(const ITEMS<char*, char*, int, int, int, int, int>& item) {
	TempItem = new ITEMS<char*, char*, int, int, int, int, int>;
	*TempItem = item;
	cout << EquipedChest.getItemName();
	if (TempItem->getItemSlot() == "Chest")	{	
		returnItemToInventory = EquipedChest;
		cout << "Swaping Items" << endl;		
		EquipedChest = item; 
	}
	else if (TempItem->getItemSlot() == "Glove")	{	EquipedGlove = *TempItem;	}
	else if (TempItem->getItemSlot() == "Boot")	{	EquipedBoot  = *TempItem;	}
	else if (TempItem->getItemSlot() == "Legging")	{	EquipedPant  = *TempItem;	}
	else if (TempItem->getItemSlot() == "Weapon")	{	EquipedWeapon = *TempItem; }
	updateStats();
}

void Equipment::clearReturnItem() {
	returnItemToInventory.setItem("", "", 0, 0, 0, 0, 0);
}


//************************************************************************************************************************
//          Public getter function for player object
//************************************************************************************************************************


void Equipment::stats() {
	if (this->minDamage > 0 && this->maxDamage > 0) { std::cout << "Weapon Damage		: " << this->minDamage << " - " << this->maxDamage << std::endl; }
	if (this->armorRating > 0)						{ std::cout << "Armor Rating		: " << this->armorRating << std::endl;	}
	if (this->strength > 0)							{ std::cout << "Strength		: "		<< this->strength << std::endl; }
	if (this->vitality > 0)							{ std::cout << "Vitality		: "		<< this->vitality << std::endl; }
	std::cout << std::endl;
}

ITEMS <char*, char*, int, int, int, int, int> Equipment::returnEquipedItem() {
	return returnItemToInventory;
}

Equipment::~Equipment()
{
}

