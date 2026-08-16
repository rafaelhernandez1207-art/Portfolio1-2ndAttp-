#include "Potion.h"

Potion::Potion()
{
    mHeal = 20;
}

int Potion::GetHeal()
{
    return mHeal;
}

void Potion::SetHeal(int heal)
{
    mHeal = heal;
}
