#pragma once
#include "Fighter.h"

class Fighter1 : public Fighter
{
public:
	Fighter1();
	std::pair<int, int> Fight();
};