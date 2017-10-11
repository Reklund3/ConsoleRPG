#pragma once
#include "ITEMS.h"
#include "ItemList.h"

class Equipment
{
	std::string itemName;
	std::string itemSlot;
	int minDamage;
	int maxDamage;

	int armorRating;
	int strength;
	int vitality;

	ITEMS <char*, char*, int, int, int, int, int> EquipedWeapon;						// instantiate the item Weapon Slot
	ITEMS <char*, char*, int, int, int, int, int> EquipedChest;							// instantiate the item Chest Slot
	ITEMS <char*, char*, int, int, int, int, int> EquipedPant;							// instantiate the item Legging Slot
	ITEMS <char*, char*, int, int, int, int, int> EquipedGlove;						// instantiate the item Glove Slot
	ITEMS <char*, char*, int, int, int, int, int> EquipedBoot;							// instantiate the item Boot Slot
	ITEMS <char*, char*, int, int, int, int, int>* TempItem;							// instantiate the item Temp Item
	ITEMS <char*, char*, int, int, int, int, int> returnItemToInventory;				// instantiate the item Temp Item

	void updateStats();

public:
	Equipment();

//************************************************************************************************************************
//          Public setter function for player object
//************************************************************************************************************************

	void equipItem(const ITEMS<char*, char*, int, int, int, int, int>& item);
	void clearReturnItem();


//************************************************************************************************************************
//          Public getter function for player object
//************************************************************************************************************************

	void stats();
	ITEMS <char*, char*, int, int, int, int, int> returnEquipedItem();
	inline int getMinWeaponDamage() { return this->minDamage;   }
	inline int getMaxWeaponDamage() { return this->maxDamage;   }
	inline int getArmorRating()     { return this->armorRating; }
	inline int getStrength()        { return this->strength;    }
	inline int getVitality()        { return this->vitality;    }

	~Equipment();
};



