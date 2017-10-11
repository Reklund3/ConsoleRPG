#pragma once
#include <string>
#include <iostream>
#include <vector>

template <typename itemsName, typename itemsSlot, typename minDamages, typename maxDamages, typename armorsRating, typename strengthStat, typename vitalityStat>
class ITEMS
{
	std::string itemName;
	std::string itemSlot;
	minDamages minDamage;
	maxDamages maxDamage;

	armorsRating armorRating;
	strengthStat strength;
	vitalityStat vitality;
	
public:
	
	void setItem(const itemsName& itemName, const itemsSlot& itemSlot, const minDamages& minDamage, const maxDamages& maxDamage, const armorsRating& armorRating, const strengthStat& strength, const vitalityStat& vitality) {
		this->itemName = itemName;
		this->itemSlot = itemSlot;
		this->minDamage = minDamage;
		this->maxDamage = maxDamage;
		this->armorRating = armorRating;
		this->strength = strength;
		this->vitality = vitality;
	}

	void displayItem();
	inline std::string getItemName()	{	return this->itemName;		}
	inline std::string getItemSlot()	{	return this->itemSlot;		}
	inline int getArmorRating()			{	return this->armorRating;	}
	inline int getStrength()			{	return this->strength;		}
	inline int getVitality()			{	return this->vitality;		}
	inline int getMinDamage()			{	return this->minDamage;		}
	inline int getMaxDamage()			{	return this->maxDamage;		}
	virtual ~ITEMS();

};
