#include "TurnOrder.h"
#include <iostream>
#include "BattleMechanic.h"

bool TurnOrder::GetIsHero()
{
    return mIsHero;
}

void TurnOrder::SetIsHero(bool isCharacter)
{
    mIsHero = isCharacter;
}

int TurnOrder::GetIndex()
{
    return mIndex;
}

void TurnOrder::SetIndex(int index)
{
    mIndex = index;
}

void TurnOrder::CreateTurnOrder(std::vector<Heroes>& heroes, std::vector<Enemy>& enemies, std::vector<TurnOrder>& turn)
{
    std::vector<TurnOrder> turnOrder; //will have a sorted vector of both vectors

    int totalCharacters = heroes.size() + enemies.size(); //size to use in one whole loop

    for (int i = 0; i < totalCharacters; i++)
    {
        int fastestIndex = -1; //this will store the index of the fastest character who hasnt acted yet this turn
        bool fastestIsHero = false; //tells the difference between a Hero and an enemy
        int fastestSpeed = -1; //In case for whatever reason a Character's speed is 0 (a Speed Comparison)

        for (int j = 0; j < heroes.size(); j++)
        {
            bool alreadyAdded = false; //So it doesnt add the same character twice

            for (int k = 0; k < turnOrder.size(); k++)
            {
                if (!turnOrder[k].GetIsHero() && turnOrder[k].GetIndex() == j)
                {
                    
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded && heroes[j].GetHP() > 0) //loop between every hero until I get the fastest one
            {
                if (heroes[j].GetSpeed() > fastestSpeed || heroes[j].GetSpeed() == fastestSpeed && fastestIsHero == false)
                {
                    fastestSpeed = heroes[j].GetSpeed(); //replace fastestSpeed until another characters speed beats it
                    fastestIndex = j; //Store the index of the current fastest hero
                    fastestIsHero = true; //It is a hero
                }
                
            }
        }

        for (int l = 0; l < enemies.size(); l++)
        {
            bool alreadyAdded = false;

            for (int m = 0; m < turnOrder.size(); m++)
            {
                if (!turnOrder[m].GetIsHero() && turnOrder[m].GetIndex() == l)
                {
                   
                    alreadyAdded = true;
                    break;
                }
            }

            if ((!alreadyAdded) && (enemies[l].GetHP() > 0))
            {
                if (enemies[l].GetSpeed() > fastestSpeed)
                {
                    fastestSpeed = enemies[l].GetSpeed();
                    fastestIndex = l;
                    fastestIsHero = false; //Not a hero
                }
               
            }
        }
        if (fastestIndex != -1) //If vector is empty or everyone is dead
        {

            TurnOrder newTurn;
            newTurn.SetIsHero(fastestIsHero);//Overwrite both TurnOrder parameter to know the index of Characters and if they are ally or enemy
            newTurn.SetIndex(fastestIndex);

            turnOrder.push_back(newTurn);
            for (int n = 0; n < turnOrder.size(); n++)
            {
                if (turnOrder[n].GetIsHero() == true)
                {
                    BattleMechanic::PlayersBattleCommand(heroes[n], enemies);
                }
                if(turnOrder[n].GetIsHero() == false)
                {
                    BattleMechanic::EnemyAttack(enemies[n], heroes);
                }
            }
        }
    }
}
