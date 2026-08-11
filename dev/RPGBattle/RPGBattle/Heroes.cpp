#include "Heroes.h"

Heroes::Heroes()
{
    for (int i = 0; i < 3; i++)
    {
        mPotions.push_back(Potion());
    }
}

std::vector<Potion> Heroes::GetPotions()
{
    return mPotions;
}

void Heroes::SetPotions(std::vector<Potion> potions)
{
    mPotions = potions;
}
