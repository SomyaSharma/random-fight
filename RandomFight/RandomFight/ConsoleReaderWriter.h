#pragma once

#include "Board.h"

// Functions to write to console and get user input
namespace ConsoleReaderWriter
{
	void PrintWelcome();
	void PrintWinnerMessage(Player player);
	void PrintMessage(Player player, std::string message);
	int GetUserSelection(std::vector<std::string> options);
	int GetUserSelection(std::vector<std::pair<int, int>> options);
	int GetUserInput(int numOptions);
}

