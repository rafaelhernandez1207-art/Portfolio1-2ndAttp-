#include "Heroes.h"
#include <iostream>

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

void Heroes::UsePotion(Heroes playersTurn, std::vector<Heroes>& target)
{
    if (!playersTurn.GetPotions().empty())
    {
        std::cout << "Choose an ally to heal: \n";

        for (int i = 0; i < target.size(); i++)
        {
            std::cout << i + 1 << ". " << target[i].GetName() << std::endl;
        }

        int numInput = 0;
        std::string strInput = "";
        
        std::cout << "\nType the number next to the Character you want to heal and press Enter: \n";
        
        while (true)
        {
            std::getline(std::cin, strInput);
            try
            {
                numInput = std::stoi(strInput);
                numInput -= 1; //1 becomes Index 0

                if (numInput >= 0 || numInput < target.size()) //3
                {
                    target[numInput].GetPotions();
                    target[numInput].SetHP(target[numInput].GetHP() + playersTurn.GetPotions()[playersTurn.GetPotions().size() - 1].GetHeal());
                    std::cout << "\n" << target[numInput].GetName() << " has healed by " << playersTurn.GetPotions()[playersTurn.GetPotions().size() - 1].GetHeal() << "!\n";
                    std::cout << target[numInput].GetName() << ": " << target[numInput].GetHP() << "\n";
                    playersTurn.GetPotions().pop_back();
                    break;
                }
                std::cout << "Invalid input, please Enter a number between " << 1 << " and " << target.size() << "...\n";
            }
            catch (...)
            {
                std::cout << "Invalid input, please Enter a number between " << 1 << " and " << target.size() << "...\n";
            }
        }
    }
    else
    {
        std::cout << "There is no potions in your bag...\n" << std::endl;
    }
}

void Heroes::EquippedWeapon(Character& self, Weapon wpnPower)
{
    self.SetAttack((self.GetAttack() + wpnPower.GetWeaponDamage()));
}

