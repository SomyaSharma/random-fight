// RandomFight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Game.h"

int main()
{
	// Initialize game
	Game::Initialize();
	Game::Play();
	
	std::cin.get();
    return 0;
}

