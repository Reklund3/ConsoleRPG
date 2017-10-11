#pragma once
#include "Equipment.h"

class INVENTORY
{
public:
	INVENTORY();
	INVENTORY(const INVENTORY& item);
	void pickUpItem(const Equipment& item);
	~INVENTORY();
};

