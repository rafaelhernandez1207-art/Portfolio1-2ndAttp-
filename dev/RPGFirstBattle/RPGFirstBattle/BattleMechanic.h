#pragma once
#include <iostream>
#include <string>
#include "Heroes.h"
#include "Enemy.h"

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

	static void PlayerAttack(Heroes playersTurn, std::vector<Enemy>& target);
	static void EnemyAttack(Enemy enemiesTurn, std::vector<Heroes>& target);

	//Take in a return type of bool for Flee command
	static bool PlayersBattleCommand(Heroes& playersTurn, std::vector<Heroes>& party, std::vector<Enemy>& target);
	static void Battle(std::vector<Heroes>& heroes, std::vector<Enemy>& enemies);
};

