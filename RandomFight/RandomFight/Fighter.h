#pragma once

#include <string>
#include <vector>

// Base class for all fighter characters
// All characters have a name and ranges for steps, ammo and armor

class Fighter
{
protected:
	std::string name;
	std::pair<int, int> stepsRange;
	std::pair<int, int> ammoRange;
	std::pair<int, int> armorRange;

	int RollDice(std::pair<int, int> range);

public:
	std::string GetName();
	std::vector<std::pair<int, int>> GetValidMoves(int x, int y);
	virtual std::pair<int, int> Fight() = 0;
};