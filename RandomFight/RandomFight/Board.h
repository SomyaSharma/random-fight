#pragma once
#include <memory>
#include "Fighter.h"

#define BOARD_SIZE 6
#define FIGHTER_COUNT 6
#define PLAYER_COUNT 2

enum Player
{
	None = 0,
	Player1,
	Player2
};

class Board
{
	struct Square
	{
		Player player = Player::None;
		std::shared_ptr<Fighter> fighter = nullptr;
	};

private:
	Square grid[BOARD_SIZE][BOARD_SIZE];

public:
	Board();
	std::pair<Player, std::shared_ptr<Fighter>> GetFighterAt(int x, int y);
	void SetFighterAt(int x, int y, Player player, std::shared_ptr<Fighter> fighter);
	void GetActiveFighters(Player player, std::vector<std::pair<int, int>> &activePositions, std::vector<std::shared_ptr<Fighter>> &activeFighters);
	void Clear(int x, int y);
	void Render();
};

