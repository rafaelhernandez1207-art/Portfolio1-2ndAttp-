#pragma once
#include <vector>
#include "Enemy.h"
#include "Heroes.h"
class TurnOrder
{
	bool mIsHero;
	int mIndex;

public:

	bool GetIsHero();
	void SetIsHero(bool isHero);

	int GetIndex();
	void SetIndex(int index);

	std::vector<TurnOrder> CreateTurnOrder(std::vector<Heroes>& heroes, std::vector<Enemy>& enemies);

};

