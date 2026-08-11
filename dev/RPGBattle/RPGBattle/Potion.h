#pragma once
#include "Item.h"
class Potion :
    public Item
{
    int mHeal;

public:
    Potion();

    int GetHeal();
    void SetHeal(int heal);
};

