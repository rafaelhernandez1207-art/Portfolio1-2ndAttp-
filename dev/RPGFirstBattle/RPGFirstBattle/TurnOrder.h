#pragma once
#include <vector>
#include "Enemy.h"
#include "Heroes.h"
class TurnOrder
{
	bool mIsCharacter;
	int mIndex;

public:

	bool GetBoolCharacter();
	void SetBoolCharacter(bool isCharacter);

	int GetIndex();
	void SetIndex(int index);

	std::vector<TurnOrder> CreateTurnOrder(std::vector<Heroes> heroes, std::vector<Enemy> enemies);

};

