#include "stdafx.h"
#include "Fighter1.h"
#include <numeric> 

using namespace std;

Fighter1::Fighter1()
{
	// Set parameteres for Fighter 1
	name = "Wizard";
	stepsRange = make_pair(1, 5);
	ammoRange = make_pair(8, 12);
	armorRange = make_pair(13, 17);
}

// Fight capabilities for Fighter 1
// Ammo : Roll dice thrice and pick the average
// Armor : Roll dice thrice and pick the average
// Return (ammo, armor)
std::pair<int, int> Fighter1::Fight()
{
	vector<int> ammoResults = RollDice(ammoRange, 3);
	int ammo = (int)floor(accumulate(ammoResults.begin(), ammoResults.end(), 0.0) / ammoResults.size());

	vector<int> armorResults = RollDice(armorRange, 3);
	int armor = (int)floor(accumulate(armorResults.begin(), armorResults.end(), 0.0) / armorResults.size());

	return make_pair(ammo, armor);
}