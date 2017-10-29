#include "stdafx.h"
#include "Game.h"
#include "ConsoleReaderWriter.h"

Board Game::GBoard;

void Game::Initialize()
{
	ConsoleReaderWriter::PrintWelcome();
	GBoard.Render();
}

void Game :: Play()
{

}