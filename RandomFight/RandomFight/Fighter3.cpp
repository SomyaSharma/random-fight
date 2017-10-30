#include "stdafx.h"
#include "Fighter3.h"

using namespace std;

Fighter3::Fighter3()
{
	// Set parameteres for Fighter 3
	name = "Elf";
	stepsRange = make_pair(1, 5);
	ammoRange = make_pair(12, 14);
	armorRange = make_pair(6, 11);
}

// Fight capabilities for Fighter 3
// Ammo : Roll dice once
// Armor : Roll dice once
// Return (ammo, armor)
std::pair<int, int> Fighter3::Fight()
{
	int ammo = RollDice(ammoRange, 1).at(0);
	int armor = RollDice(armorRange, 1).at(0);

	return make_pair(ammo, armor);
}