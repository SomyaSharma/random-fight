#include "stdafx.h"
#include "Fighter1.h"

using namespace std;

Fighter1::Fighter1()
{
	// Set parameteres for Fighter 1
	name = "Wizard";
	stepsRange = make_pair(1, 5);
	ammoRange = make_pair(5, 15);
	armorRange = make_pair(1, 5);
}

// Fight capabilities for Fighter 1
// Return (ammo, armor)
std::pair<int, int> Fighter1::Fight()
{
	int ammo = RollDice(ammoRange);
	int armor = RollDice(armorRange);
	return make_pair(ammo, armor);
}