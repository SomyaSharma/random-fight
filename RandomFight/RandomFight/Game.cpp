#include "stdafx.h"
#include "Game.h"
#include "ConsoleReaderWriter.h"
#include <iostream>

using namespace std;

Board Game::GBoard;

bool Game::DidAttackerWin(std::pair<int, int> attacker, std::pair<int, int> defender)
{
	if (attacker.first > defender.second)
	{
		return true;
	}
	else if (defender.first > attacker.second)
	{
		return false;
	}
	return false;
}

void Game :: Play()
{
	Player winner = Player::None;
	int maxTurns = 10;
	int i = 0;
	while (winner == Player::None && i<maxTurns)
	{
		i++;
		// Render board
		GBoard.Render();

		// For each player
		for (int player = 1; player < PLAYER_COUNT; player++)
		{
			Player currentPlayer = static_cast<Player>(player);

			// Get list of active fighters for current player
			vector<shared_ptr<Fighter>> activeFighters;
			vector<pair<int, int>> activePositions;
			GBoard.GetActiveFighters(currentPlayer, activePositions, activeFighters);

			// If no active fighters, player loses
			if (activeFighters.empty())
			{
				cout << "Player" << currentPlayer << " loses." << endl;
				break;
			}

			// Get user selection for fighter
			vector<string> fighterList;
			for (size_t fighterCount = 0; fighterCount < activeFighters.size(); fighterCount ++)
			{
				fighterList.push_back(activeFighters[fighterCount]->GetName());
			}
			int selectedFighterIndex = ConsoleReaderWriter::GetUserSelection(fighterList) - 1;
			shared_ptr<Fighter> selectedFighter = activeFighters[selectedFighterIndex];
			pair<int, int> selectedPos = activePositions[selectedFighterIndex];

			// Get list of valid moves
			vector<pair<int, int>> validMoves = selectedFighter->GetValidMoves(selectedPos.first, selectedPos.second);

			// If no valid moved, player misses turn
			if (validMoves.empty())
			{
				cout << "No valid moves for selected fighter" << endl;
				continue;
			}

			// Get user selection for move
			int moveSelection = ConsoleReaderWriter::GetUserSelection(validMoves);
			pair<int, int> selectedMove = validMoves[moveSelection - 1];

			// Check current occupant
			pair<Player, shared_ptr<Fighter>> currentOccupant = GBoard.GetFighterAt(selectedMove.first, selectedMove.second);
			if (currentOccupant.first == Player::None)
			{
				GBoard.SetFighterAt(selectedMove.first, selectedMove.second, currentPlayer, selectedFighter);
			}
			else
			{
				// Fight - if another player is already present
				bool attackerWins = DidAttackerWin(selectedFighter->Fight(), currentOccupant.second->Fight());
				if (attackerWins)
				{
					GBoard.Clear(selectedMove.first, selectedMove.second);
					GBoard.SetFighterAt(selectedMove.first, selectedMove.second, currentPlayer, selectedFighter);
				}
			}

			GBoard.Clear(selectedMove.first, selectedMove.second);
		}
	}
}