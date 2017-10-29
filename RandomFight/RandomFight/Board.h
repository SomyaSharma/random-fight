#pragma once
#include <memory>
#include "Fighter.h"

#define BOARD_SIZE 6
#define FIGHTER_COUNT 6
#define MOTION_RANGE 4

class Board
{
	struct Square
	{
		Player player = Player::None;
		std::shared_ptr<Fighter> fighter = nullptr;
	};

private:
	Square grid[BOARD_SIZE][BOARD_SIZE];

	bool CheckMove(int x1, int y1, int x2, int y2);

public:
	Board();
	std::pair<Player, std::shared_ptr<Fighter>> GetFighterAt(int x, int y);
	void SetFighterAt(int x, int y, Player player, std::shared_ptr<Fighter> fighter);
	void GetActiveFighters(Player player, std::vector<std::pair<int, int>> &activePositions, std::vector<std::shared_ptr<Fighter>> &activeFighters);
	std::vector<std::pair<int, int>> GetValidMoves(int x, int y, int steps);
	void Clear(int x, int y);
	void Render();
};

