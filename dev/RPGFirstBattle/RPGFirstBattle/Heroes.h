#pragma once
#include "Character.h"
#include <vector>
#include "Potion.h"
#include "Weapon.h"
class Heroes :
    public Character
{
    //Has a vector of items/potions
    std::vector<Potion> mPotions;

public:
    Heroes();

    std::vector<Potion> GetPotions();
    void SetPotions(std::vector<Potion> potions);

   static void UsePotion(Heroes playersTurn, std::vector<Heroes>& target);
   void EquippedWeapon(Character& self, Weapon wpnPower);

};

