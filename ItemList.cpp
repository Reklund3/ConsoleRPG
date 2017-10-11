#include "stdafx.h"
#include "ItemList.h"


ItemList::ItemList()
{
	//                          Item Name			Item Slot	Min Damage	Max Damage	Armor Rating	Strength	Vitality
	ChestofLight   .setItem  ("Chest of Light",      "Chest",        0,          0,          2,             1,         1      );    // define the attribute of Chest of Light item
	DullSword      .setItem  ("Dull Sword",          "Weapon",       1,          4,          0,             0,         0      );    // define the attribute of Dull Sword item
	BootsofDawn    .setItem  ("Boots of Dawn",       "Boot",         0,          0,          1,             0,         0      );    // define the attribute of Boots of Dawn item
	GloveofJustice .setItem  ("Gloves of Justice",   "Glove",        0,          0,          1,             1,         0      );    // define the attribute of Gloves of Justice item
	PantsofDestiny .setItem  ("Pants of Destiny",    "Legging",      0,          0,          1,             0,         2      );    // define the attribute of Pants of Destiny item
	ChestofDawn    .setItem  ("Chest of Dawn",       "Chest",        0,          0,          3,             2,         2      );    // define the attribute of Chest of Dawn item


	gameItems.push_back(ChestofLight)      ;
	gameItems.push_back(DullSword)         ;
	gameItems.push_back(BootsofDawn)       ;
	gameItems.push_back(GloveofJustice)    ;
	gameItems.push_back(PantsofDestiny)    ;
	gameItems.push_back(ChestofDawn)       ;
}

ItemList::~ItemList()
{
}
