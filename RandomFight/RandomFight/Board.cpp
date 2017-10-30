#include "stdafx.h"
#include"Board.h"
#include "Fighter.h"
#include "Fighter1.h"
#include "Fighter2.h"
#include "Fighter3.h"
#include <iostream>

using namespace std;

Board::Board()
{
	// Initialize the board
	SetFighterAt(0, 0, Player::Player1, make_shared<Fighter1>());
	SetFighterAt(0, 1, Player::Player1, make_shared<Fighter2>());
	SetFighterAt(0, 2, Player::Player1, make_shared<Fighter3>());
	SetFighterAt(BOARD_SIZE - 1, BOARD_SIZE - 1, Player::Player2, make_shared<Fighter1>());
	SetFighterAt(BOARD_SIZE - 1, BOARD_SIZE - 2, Player::Player2, make_shared<Fighter2>());
	SetFighterAt(BOARD_SIZE - 1, BOARD_SIZE - 3, Player::Player2, make_shared<Fighter3>());
}

// Get fighter at board location
pair<Player, shared_ptr<Fighter>> Board::GetFighterAt(int x, int y)
{
	return make_pair(grid[x][y].player, grid[x][y].fighter);
}

// Set fighter to board location
// Clear location if empty
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

// Check if player is in game
// I.e. player has at least 1 fighter
bool Board::IsPlayerInGame(Player player)
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			if (grid[x][y].player == player)
			{
				return true;
			}
		}
	}
	return false;
}

// Get list of the player's active fighters i.e. fighters still on the board
// Return list of positions and list of fighters
void Board::GetActiveFighters(Player player, vector<pair<int, int>> &activePositions, vector<shared_ptr<Fighter>> &activeFighters)
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			if (grid[x][y].player == player)
			{
				activePositions.push_back(make_pair(x, y));
				activeFighters.push_back(grid[x][y].fighter);
			}
		}
	}
}

// Check if a move is valid
// 1. No fighter of the same player is present
// 2. The new position is within the board's dimensions
// 3. No fighters are present in the path from old to new position
bool Board::CheckMove(int x1, int y1, int x2, int y2)
{
	// Check if the player has another fighter at new position
	if (grid[x1][y1].player == grid[x2][y2].player)
	{
		return false;
	}

	// Check if new position is within the board's dimentions
	if ((x1 != x2 && (x2 < 0 || x2 >= BOARD_SIZE))
		|| (y1 != y2 && (y2 < 0 || y2 >= BOARD_SIZE)))
	{
		return false;
	}

	// Check if another fighter is present in the path from old to new position
	bool foundFighter = false;
	if (x1 != x2)
	{
		int xcount = x2 > x1 ? 1 : -1;
		int i = x1 + xcount;
		for (; i != x2 && !foundFighter; i = i + xcount)
		{
			foundFighter = Player::None != grid[i][y1].player;
		}
		if (foundFighter)
		{
			return false;
		}
	}
	else
	{
		foundFighter = false;
		int ycount = y2 > y1 ? 1 : -1;
		int j = y1 + ycount;
		for (; j != y2 && !foundFighter; j = j + ycount)
		{
			foundFighter = Player::None != grid[x1][j].player;
		}
		if (foundFighter)
		{
			return false;
		}
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

// Clear board position
void Board::Clear(int x, int y)
{
	grid[x][y].player = Player::None;
	grid[x][y].fighter.reset();
}

// Render board
void Board::Render()
{
	cout << endl << "\t";
	for (int header = 0; header < BOARD_SIZE; header++)
	{
		cout << header << "\t";
	}
	cout << endl;
	for(int x = 0; x < BOARD_SIZE; x++)
	{
		cout << x << "\t";
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			if (grid[x][y].fighter == nullptr)
			{
				cout << " _ " << "\t";
			}
			else
			{
				cout << grid[x][y].fighter->GetName() << grid[x][y].player << "\t";
			}
		}
		cout << endl;
	}
	cout << endl;
}