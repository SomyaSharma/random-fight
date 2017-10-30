// RandomFight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "ConsoleReaderWriter.h"
#include "Game.h"

int main()
{
	ConsoleReaderWriter::PrintWelcome();
	Game::Play();
	std::cin.get();
    return 0;
}

