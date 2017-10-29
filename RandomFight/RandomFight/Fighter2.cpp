#include "stdafx.h"
#include "Fighter2.h"

using namespace std;

Fighter2::Fighter2()
{
	// Set parameteres for Fighter 1
	name = "Ranger";
	stepsRange = make_pair(2, 2);
	ammoRange = make_pair(5, 15);
	armorRange = make_pair(1, 5);
}

// Fight capabilities for Fighter 1
// Return (ammo, armor)
std::pair<int, int> Fighter2::Fight()
{
	int ammo = RollDice(ammoRange);
	int armor = RollDice(armorRange);
	return make_pair(ammo, armor);
}