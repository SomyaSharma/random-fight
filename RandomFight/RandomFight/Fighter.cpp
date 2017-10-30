#include "stdafx.h"
#include "Fighter.h"

using namespace std;

// Generate random numbers in given range
// This will be use to generate random numbers for steps, ammo and armor on every turn
std::vector<int> Fighter::RollDice(pair<int, int> range, int numRolls)
{
	vector<int> results;
	for (int rollCount = 0; rollCount < numRolls; rollCount++)
	{
		results.push_back(rand() % range.second + range.first);
	}
	return results;
}

// Return name of the fighter
string Fighter::GetName()
{
	return name;
}

// Get number of steps for a turn
int Fighter::GetSteps()
{
	return RollDice(stepsRange, 1).at(0);
}
