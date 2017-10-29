#include "stdafx.h"
#include "Game.h"
#include "ConsoleReaderWriter.h"
#include <iostream>

using namespace std;

Board Game::GBoard;

bool Game::DidAttackerWin(std::pair<int, int> attacker, std::pair<int, int> defender)
{
	cout << "Attacker : Ammo(" << attacker.first << ") Armor(" << attacker.second << ")" << endl;
	cout << "Defender : Ammo(" << defender.first << ") Armor(" << defender.second << ")" << endl;
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

void Game::Play()
{
	Player winner = Player::None;
	int maxTurns = 10;
	int i = 0;
	while (winner == Player::None && i<maxTurns)
	{
		i++;
		// For each player
		for (int player = 1; player <= 2; player++)
		{
			// Render board
			GBoard.Render();

			Player currentPlayer = static_cast<Player>(player);
			ConsoleReaderWriter::PrintMessage(currentPlayer, "Turn begins");

			// Get list of active fighters for current player
			vector<shared_ptr<Fighter>> activeFighters;
			vector<pair<int, int>> activePositions;
			GBoard.GetActiveFighters(currentPlayer, activePositions, activeFighters);

			// If no active fighters, player loses
			if (activeFighters.empty())
			{
				ConsoleReaderWriter::PrintMessage(currentPlayer, "No active fighters.");
				winner = static_cast<Player>(3 - currentPlayer);
				break;
			}

			// Get user selection for fighter
			ConsoleReaderWriter::PrintMessage(currentPlayer, "Select Fighter");
			vector<string> fighterList;
			for (size_t fighterCount = 0; fighterCount < activeFighters.size(); fighterCount ++)
			{
				fighterList.push_back(activeFighters[fighterCount]->GetName());
			}
			int selectedFighterIndex = ConsoleReaderWriter::GetUserSelection(fighterList) - 1;
			shared_ptr<Fighter> selectedFighter = activeFighters[selectedFighterIndex];
			pair<int, int> selectedPos = activePositions[selectedFighterIndex];

			// Get list of valid moves
			int steps = selectedFighter->GetSteps();
			vector<pair<int, int>> validMoves = GBoard.GetValidMoves(selectedPos.first, selectedPos.second, steps);

			// If no valid moved, player misses turn
			if (validMoves.empty())
			{
				ConsoleReaderWriter::PrintMessage(currentPlayer, "No valid moves for selected fighter");
				continue;
			}

			// Get user selection for move
			ConsoleReaderWriter::PrintMessage(currentPlayer, "Steps : " + steps);
			ConsoleReaderWriter::PrintMessage(currentPlayer, "Select move");
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
				ConsoleReaderWriter::PrintMessage(currentPlayer, "attacks Player" + currentOccupant.first);
				bool attackerWins = DidAttackerWin(selectedFighter->Fight(), currentOccupant.second->Fight());
				if (attackerWins)
				{
					GBoard.Clear(selectedMove.first, selectedMove.second);
					GBoard.SetFighterAt(selectedMove.first, selectedMove.second, currentPlayer, selectedFighter);
				}
			}

			GBoard.Clear(selectedPos.first, selectedPos.second);
		}
	}

	ConsoleReaderWriter::PrintWinnerMessage(winner);
}