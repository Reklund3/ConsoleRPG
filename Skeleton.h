#pragma once
#ifndef SKELETON
#define SKELETON

#include <iostream>
#include "World.h"
using std::endl;
using std::cout;

class Skeleton:public World
{
	int currentHealth;
	int maxHealth;
	int attackMin;
	int attackMax;
	
	int experience;
	virtual ~Skeleton();
public:
	bool active;
	ITEMS<char*, char*, int, int, int, int, int> lootItem;
	Skeleton();

//************************************************************************************************************************
//          Public setter function for player object
//************************************************************************************************************************

	void takeDamage(const int &randAttack);


//************************************************************************************************************************
//          Public getter function for player object
//************************************************************************************************************************


	void enemyHealth();
	int enemyAttack();
	void displayLoot();
	inline int distEXP() { return experience; }
	
	static void destroySkeleton(Skeleton* instance);
	
};

#endif // ! SKELETON