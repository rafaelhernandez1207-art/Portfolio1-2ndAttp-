#pragma once
#include "Item.h"
class Potion :
    public Item
{
    int mHeal;

public:

    int GetHeal();
    void SetHeal(int heal);
};

