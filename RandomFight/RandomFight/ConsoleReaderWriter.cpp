#include "stdafx.h"
#include <iostream>
#include "ConsoleReaderWriter.h"

using namespace std;

// Print welcome message
void ConsoleReaderWriter::PrintWelcome()
{
	cout << "Welcome to Random Fight!" << endl
		<< "Rules:" << endl
		<< "- Each player starts with 6 identical fighters. Each figher has fixed ranges for steps, ammo and armor." << endl
		<< "- At each turn, the player will select a fighter" << endl
		<< "- A dice roll will decide how many steps the selected fighter can take." << endl
		<< "- The player will be given a list of possible moves to choose from." << endl
		<< "- If the player chooses to land at a position where the other player's fighter is present. They'll fight." << endl
		<< "- Each fighter will get an (ammo, armor) pair based on its fighting technique and dice rolls. The losing fighter is removed from the board." << endl
		<< "- Last player standing wins!" << endl;
}

// Print winner message
void ConsoleReaderWriter::PrintWinnerMessage(Player player)
{
	cout << "Congratulation!" << endl
		<< "Player " << player << " wins!" << endl;
}

// Get user selection for fighter
int ConsoleReaderWriter::GetUserSelection(std::vector<std::string> options)
{
	cout << "Make a selection:" << endl;

	int numOptions = static_cast<int>(options.size());
	for (int i = 1; i <= numOptions; i++)
	{
		cout << i << ". " << options[i - 1] << endl;
	}
	return GetUserInput(numOptions);
}

// Get user selection for moves
int ConsoleReaderWriter::GetUserSelection(std::vector<std::pair<int, int>> options)
{
	cout << "Make a selection:" << endl;

	int numOptions = static_cast<int>(options.size());
	for (int i = 1; i <= numOptions; i++)
	{
		cout << i << ". [" << options[i - 1].first << ", " << options[i - 1].second << "]" << endl;
	}
	return GetUserInput(numOptions);
}


// Get valid user selection
int ConsoleReaderWriter::GetUserInput(int numOptions)
{
	int selection = 0;
	while (selection <= 0 || selection > numOptions)
	{
		cout << "Select an option: ";
		cin >> selection;
		cout << endl;
	}
	return selection;
}