#include "stdafx.h"
#include"Board.h"
#include "Fighter.h"
#include "Fighter1.h"

#include <iostream>

using namespace std;

Board::Board()
{
	// Initialize the board
	SetFighterAt(0, 0, Player::Player1, make_shared<Fighter1>());
	SetFighterAt(5, 0, Player::Player2, make_shared<Fighter1>());
}

pair<Player, shared_ptr<Fighter>> Board::GetFighterAt(int x, int y)
{
	return make_pair(grid[x][y].player, grid[x][y].fighter);
}

void Board::SetFighterAt(int x, int y, Player player, shared_ptr<Fighter> fighter)
{
	grid[x][y].player = player;
	grid[x][y].fighter = fighter;
}

void Board::GetActiveFighters(Player player)
{}

void Board::Render()
{
	for(int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			if (grid[x][y].fighter == nullptr)
			{
				cout << " _ ";
			}
			else
			{
				cout << grid[x][y].fighter->GetName() << grid[x][y].player;
			}
		}
		cout << endl;
	}
}