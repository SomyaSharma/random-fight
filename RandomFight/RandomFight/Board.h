#pragma once
#include <memory>
#include "Fighter.h"

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
	Square grid[6][6];

public:
	Board();
	std::pair<Player, std::shared_ptr<Fighter>> GetFighterAt(int x, int y);
	void SetFighterAt(int x, int y, Player player, std::shared_ptr<Fighter> fighter);
	void GetActiveFighters(Player player);
	void Render();
};

