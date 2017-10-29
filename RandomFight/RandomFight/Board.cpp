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
	if (fighter == nullptr)
	{
		grid[x][y].player = Player::None;
		grid[x][y].fighter.reset();
	}
	else
	{
		grid[x][y].player = player;
		grid[x][y].fighter = fighter;
	}
}

void Board::GetActiveFighters(Player player, vector<pair<int, int>> &activePositions, vector<shared_ptr<Fighter>> &activeFighters)
{
	for (int x = 0; x <= BOARD_SIZE; x++)
	{
		for (int y = 0; y <= BOARD_SIZE; y++)
		{
			if (grid[x][y].player == player)
			{
				activePositions.push_back(make_pair(x, y));
				activeFighters.push_back(grid[x][y].fighter);
			}
		}
	}
}

bool Board::CheckMove(int x1, int y1, int x2, int y2)
{
	if (grid[x1][y1].player == grid[x2][y2].player)
	{
		return false;
	}
	return true;
}

// Get the list of valid moves for a fighter
vector<pair<int, int>> Board::GetValidMoves(int x, int y, int steps)
{
	// List possible moves
	int possibleMoves[MOTION_RANGE][2] = {
		{ x + steps, y },
		{ x - steps, y },
		{ x, y + steps },
		{ x, y - steps }
	};

	// Check each possible move
	vector<pair<int, int>> validMoves;
	for (int i = 0; i < MOTION_RANGE; i++)
	{
		if (CheckMove(x, y, possibleMoves[i][0], possibleMoves[i][1]))
		{
			validMoves.push_back(make_pair(possibleMoves[i][0], possibleMoves[i][1]));
		}
	}
	return validMoves;
}

void Board::Clear(int x, int y)
{
	grid[x][y].player = Player::None;
	grid[x][y].fighter.reset();
}

void Board::Render()
{
	for(int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
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