#include "stdafx.h"
#include "Fighter2.h"
#include <algorithm>

using namespace std;

Fighter2::Fighter2()
{
	// Set parameteres for Fighter 2
	name = "Ranger";
	stepsRange = make_pair(1, 2);
	ammoRange = make_pair(11, 19);
	armorRange = make_pair(6, 10);
}

// Fight capabilities for Fighter 2
// Ammo : Roll dice thrice and pick the max
// Armor : Roll dice thrice and pick the max
// Return (ammo, armor)
std::pair<int, int> Fighter2::Fight()
{
	vector<int> ammoResults = RollDice(ammoRange, 3);
	int ammo = ammoResults.at(distance(ammoResults.begin(), max_element(ammoResults.begin(), ammoResults.end())));

	vector<int> armorResults = RollDice(armorRange, 3);
	int armor = armorResults.at(distance(armorResults.begin(), max_element(armorResults.begin(), armorResults.end())));

	return make_pair(ammo, armor);
}