// RPGBattle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Character.h"
#include "Heroes.h"
#include "Enemy.h"

//Methods before main are foward declarations defined at the bottom
void DisplayMessage(std::string message);//Has a simple text box around the text, just for looks
void PressEnterToContinue(); //Instruct the user to hit Enter
std::string GameIntro();//Intro to the game 
Heroes mainCharacter;
Enemy enemy;
std::vector<Heroes> allyTeam = {mainCharacter};
std::vector<Enemy> enemyTeam;
std::vector<Potion> mainCharactersPotions = {mainCharacter.GetPotions()};


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
    
    std::string playerName = "";
    do
    { 
        switch (numMenuOption)
        {
        case NewGame:
            playerName = GameIntro(); //Loops at the moment
            //exitGame = true; //Exiting is an Option
            break;
        case Exit:
            exitGame = true;//closes the console
            break;
        default:
            break;
        }
        
    } while (!exitGame);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void DisplayMessage(std::string message)
{
    system("cls");//It clears the screen first then displays the next output (in this case the message below)
    std::cout << "==================================================================" << std::endl;
    std::cout << "    " << message << "" << std::endl;
    std::cout << "==================================================================\n\n" << std::endl;
    PressEnterToContinue();
    std::cout << "\n";
}

void PressEnterToContinue()
{
    std::cout << "Press Enter to Continue..." << std::endl;
    std::cin.get();
}

std::string GameIntro()
{
    DisplayMessage("Hello Player! Welcome to my first game!");
    DisplayMessage("Here you will fight monsters in several floors...");//
    DisplayMessage("Beat all of them and you beat the game!");
    DisplayMessage("However... If you lose, you will have to start all over again!");
    DisplayMessage("You will play as the hero and try to see if you can beat the floors.");
    DisplayMessage("Now press Enter and type in the name of your Hero...");
    system("cls");
    std::string heroName = "";
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
    
    /*mainCharacter.UsePotion(allyTeam, mainCharactersPotions);      //Tested just to see and works
    PressEnterToContinue();*/
    return heroName;
}
