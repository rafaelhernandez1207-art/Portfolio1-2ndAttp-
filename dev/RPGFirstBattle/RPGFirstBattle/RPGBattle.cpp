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
void DisplayMessage(std::string message);//Has a simple text box around the text, just for looks
void PressEnterToContinue(); //Instruct the user to hit Enter
void GameIntro();//Intro to the game 

int main()
{
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
            GameIntro(); //Loops at the moment
            //TurnOrder::CreateTurnOrder(allyTeam, enemyTeam, turn);
           
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

void DisplayMessage(std::string message)
{
    system("cls");//It clears the screen first then displays the next output (in this case the message below)
    std::cout << "==================================================================" << std::endl;
    std::cout << "    " << message << "" << std::endl;
    std::cout << "==================================================================\n\n" << std::endl;
    PressEnterToContinue();
    std::cout << "\n";
}

static void PressEnterToContinue()
{
    std::cout << "Press Enter to Continue..." << std::endl;
    std::cin.get();
}

void GameIntro()
{
    Heroes mainCharacter;
    std::string heroName = "";
    Enemy enemy;
    
    std::vector<Potion> mainCharactersPotions = { mainCharacter.GetPotions() };
    
    DisplayMessage("Hello Player! Welcome to my first game!");
    DisplayMessage("Here you will fight monsters in several floors...");//
    DisplayMessage("Beat all of them and you beat the game!");
    DisplayMessage("However... If you lose, you will have to start all over again!");
    DisplayMessage("You will play as the hero and try to see if you can beat the floors.");
    DisplayMessage("Now press Enter and type in the name of your Hero...");
    system("cls");
    
    do {
        std::cout << "Type your Hero Name then press Enter: \n";
        std::getline(std::cin, heroName);
        if (heroName == "")
        {
            std::cout << "Name cannot be empty. Try again!\n\n";
            PressEnterToContinue();
        }
    } while (heroName == "");
    
    DisplayMessage("Welcome " + heroName + "! I wish you luck!");
   
    mainCharacter.SetName(heroName);
    Weapon sword(12);
    mainCharacter.EquippedWeapon(mainCharacter, sword); //default weapon for now

    std::vector<Heroes> allyTeam = { mainCharacter };
    std::vector<Enemy> enemyTeam = { enemy };
    std::vector<TurnOrder> turn;
    TurnOrder::CreateTurnOrder(allyTeam, enemyTeam, turn);
    
    //PressEnterToContinue();
    
}
