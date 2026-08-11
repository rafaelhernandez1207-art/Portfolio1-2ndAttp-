#pragma once
#include "Character.h"
#include <vector>
#include "Potion.h"
class Heroes :
    public Character
{
    //Has a vector of items/potions
    std::vector<Potion> mPotions;

public:
    Heroes();

    std::vector<Potion> GetPotions();
    void SetPotions(std::vector<Potion> potions);
};

