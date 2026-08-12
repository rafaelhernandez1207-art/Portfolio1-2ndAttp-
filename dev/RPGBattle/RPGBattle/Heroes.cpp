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

void Heroes::UsePotion(std::vector<Heroes>& target, std::vector<Potion>& potions)
{
    if (!potions.empty())
    {
        std::cout << "Choose an ally to heal: \n";

        for (int i = 0; i < target.size(); i++)
        {
            std::cout << i + 1 << ". " << target[i].GetName() << std::endl;
        }

        int numInput = 0;
        std::string strInput = "";//Type 1
        
        std::cout << "\nType the number next to the Character you want to heal and press Enter: \n";
        while (true)
        {
            std::getline(std::cin, strInput);
            try
            {
                numInput = std::stoi(strInput);
                numInput -= 1; //1 becomes Index 0

                if(numInput >= 0 && numInput < target.size()) 
                {
                    target[numInput].SetHP(target[numInput].GetHP() + potions[potions.size() - 1].GetHeal());
                    std::cout << target[numInput].GetName() << " has healed by " << potions[potions.size() - 1].GetHeal();
                    std::cout << target[numInput].GetName() << ": " << target[numInput].GetHP();
                    potions.erase(potions.end() - 1);
                    
                    break;
                }
                std::cout << "Invalid input, please Enter a number between " << 1 << " and " << target.size() << "...\n";
            }
            catch(...)
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
