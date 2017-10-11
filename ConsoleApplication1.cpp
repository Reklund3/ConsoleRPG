// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "Skeleton.h"
#include "Equipment.h"
#include "ITEMS.h"

using std::cin;
using std::cout;
using std::endl;

void battle(Player& voite) {
	int x;
	Skeleton* enemy;
	enemy = new Skeleton;
	do {
		system("CLS");
		cout << "A Skeleton has appeared" << endl;
		enemy->takeDamage(voite.attack());
		if (enemy->active == false) {
			voite.earnEXP(enemy->distEXP());
			voite.lootEnemy(enemy->lootItem);
			voite.getTotalEXP(); 
			Skeleton::destroySkeleton(enemy);
			break;
		}
		voite.takeDamage(enemy->enemyAttack());
		x = -1;
		cout << endl << "Battle Menu" << endl;
		cout << "1. Attack!" << endl;
		cout << "2. Run Away" << endl;
		cin >> x;
		if (x == 2) { break; }
	} while (true);
}


int main()
{
	int x = 0;
	bool gameState = true;
	int input;
	Player voite;
	while (gameState = true) {
		cout << "---------------------------" << endl;
		cout << "Main Menu" << endl;
		cout << "1. Inventory" << endl;
		cout << "2. Stats" << endl;
		cout << "3. Battle Skeleton" << endl;
		cout << "4. Exit Game" << endl;
		cout << "---------------------------" << endl;
		cin >> input;
		system("CLS");
		if (input == 1) {
			voite.getInventory();
			voite.inventoryMenu();
		}
		if (input == 2) {
			voite.getStats();
		}
		if (input == 3) {
			battle(voite);
		}
		if (input == 4) {
			break;
		}
	}
	return 0;
}

