#include "TurnOrder.h"

bool TurnOrder::GetBoolCharacter()
{
    return mIsCharacter;
}

void TurnOrder::SetBoolCharacter(bool isCharacter)
{
    mIsCharacter = isCharacter;
}

int TurnOrder::GetIndex()
{
    return mIndex;
}

void TurnOrder::SetIndex(int index)
{
    mIndex = index;
}

std::vector<TurnOrder> TurnOrder::CreateTurnOrder(std::vector<Heroes> heroes, std::vector<Enemy> enemies)
{
    std::vector<TurnOrder> turnOrder; //will have a sorted vector of both vectors

    int totalCharacters = heroes.size() + enemies.size(); //size to use in one whole loop

    for (int i = 0; i < totalCharacters; i++)
    {
        int fastestIndex = -1; //this will store the index of the fastest character who hasnt acted yet this turn
        bool fastestIsCharacter = false;
        int fastestSpeed = -1; //In case for whatever reason a Character's speed is 0 (a Speed Comparison)

        for (int j = 0; j < heroes.size(); j++)
        {
            bool alreadyAdded = false; //So it doesnt add the same character twice

            for (int k = 0; k < turnOrder.size(); k++)
            {
                if (turnOrder[k].GetBoolCharacter() && turnOrder[k].GetIndex() == k)
                {
                    alreadyAdded = true;
                    break;
                }
            }
        }

    }

    return turnOrder;
}
