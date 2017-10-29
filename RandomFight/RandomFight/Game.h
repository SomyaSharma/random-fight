#pragma once

#include "Board.h"

class Game
{
private:
	static bool DidAttackerWin(std::pair<int, int> attacker, std::pair<int, int> defender);
public:
	static Board GBoard;
	static void Play();
};
