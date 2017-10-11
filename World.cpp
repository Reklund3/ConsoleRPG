#include "stdafx.h"
#include "World.h"


World::World()
{
	
}

int World::randNum(const int& one, const int& two) {
	// Random device that will seed the generator
	std::random_device seeder;
	// Mersenne twister engine 
	std::mt19937_64 engine(seeder());
	// the distribution range random number generation
	std::uniform_int_distribution<int> dist(one, two);
	return dist(engine);
}


World::~World()
{

}
