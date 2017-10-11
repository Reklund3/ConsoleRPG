#pragma once
#include "ITEMS.h"

class ItemList : public ITEMS <char*, char*, int, int, int, int, int>
{

	ITEMS <char*, char*, int, int, int, int, int> ChestofLight;								// instantiate the item Chest of Light
	ITEMS <char*, char*, int, int, int, int, int> BootsofDawn;								// instantiate the item Boots of Dawn
	ITEMS <char*, char*, int, int, int, int, int> GloveofJustice;							// instantiate the item Gloves of Justice
	ITEMS <char*, char*, int, int, int, int, int> PantsofDestiny;							// instantiate the item Pants of Destiny
	ITEMS <char*, char*, int, int, int, int, int> DullSword;								// instantiate the item Dull Sword
	ITEMS <char*, char*, int, int, int, int, int> ChestofDawn;								// instantiate the item Chest of Dawn

public:
	ItemList();
	std::vector <ITEMS <char*, char*, int, int, int, int, int>> gameItems;
	~ItemList();
};

