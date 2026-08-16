#include "Item.h"

Item::Item()
{
    mItemName = "Potion";
}

std::string Item::GetName()
{
    return mItemName;
}

void Item::SetName(std::string itemName)
{
    mItemName = itemName;
}
