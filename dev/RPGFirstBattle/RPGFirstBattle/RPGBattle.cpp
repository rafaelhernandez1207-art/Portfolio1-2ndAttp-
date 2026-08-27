// RPGBattle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Character.h"
#include "Heroes.h"
#include "Enemy.h"
#include "BattleMechanic.h"
#include "TurnOrder.h"

//Methods before main are foward declarations defined at the bottom
int main()
{
    Heroes mainCharacter;

    Enemy enemy;

    std::vector<Potion> mainCharactersPotions = { mainCharacter.GetPotions() };
    std::string heroName = "";

    Weapon sword(12);
    mainCharacter.EquippedWeapon(mainCharacter, sword); //default weapon for now

    std::vector<Heroes> allyTeam = { mainCharacter };
    std::vector<Enemy> enemyTeam = { enemy };
    //Enum for Menu Options
    //May add other options later (like a Load Game option)
    enum HomeScreenMenuChoice
    {
        NewGame = 1,
        Exit = 2
    };
    //Menu Loop 
        std::string menuOption = "";//Variable outside for scoping reasons
        int numMenuOption = 0;
        bool exitGame = false;

    
        system("cls");
        std::cout << "===================================\n" << "\tRPG Battle\n" << "===================================\n\n";
        std::cout << "1) New Game\n" 
                  << "2) Exit\n\n"
                  << "Type a number above then press Enter: ";

    while(true)
    {  
        std::getline(std::cin, menuOption);
        try
        {
            numMenuOption = stoi(menuOption);

                if (numMenuOption == 1 || numMenuOption == 2)
                {
                    break;
                }
                std::cout << "Invalid input, please enter 1 or 2: ";
        }
        catch(...)
        {
            std::cout << "Invalid input, please enter 1 or 2: ";
        }
        
    }
    
    do
    { 
        switch (numMenuOption)
        {
        case NewGame:
            BattleMechanic::Battle(allyTeam, enemyTeam);
            break;

        case Exit:
            exitGame = true;//closes the console
            std::cout << "Press Enter again to close the Game...\n\n\n";
            break;
        default:
            break;
        }
        
    } while (!exitGame);

}




