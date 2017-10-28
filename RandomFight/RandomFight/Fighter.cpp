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

// Get the list of valid moves for a fighter
// 1. Roll a dice to get number of steps for the turn
// 2. Get possible moves for the number of steps from 1
vector<pair<int, int>> Fighter::GetValidMoves(int x, int y)
{
	// Get number of steps
	int steps = RollDice(stepsRange);

	// Calculate valid moves
	vector<pair<int, int>> validMoves;
	validMoves.push_back(make_pair(1, 1));

	return validMoves;
}
