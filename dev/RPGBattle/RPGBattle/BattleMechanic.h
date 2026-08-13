#pragma once
#include <iostream>
#include <string>
class BattleMechanic
{
public:
	enum BattleCommand
	{
		Attack = 1,
		Defend,
		UseItem,
		Flee
	};

	std::string battleOption = "";
	int numBattleOption = 0;
	

};

