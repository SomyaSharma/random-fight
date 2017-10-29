#include "stdafx.h"
#include "Fighter.h"

using namespace std;

// Generate random number in given range
// This will be use to generate random numbers for steps, ammo and armor on every turn
int Fighter::RollDice(pair<int, int> range)
{
	return rand() % range.second + range.first;
}

// Return name of the fighter
string Fighter::GetName()
{
	return name;
}

// Get number of steps for a turn
int Fighter::GetSteps()
{
	return RollDice(stepsRange);
}
