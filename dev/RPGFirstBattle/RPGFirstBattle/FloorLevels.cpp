#include "FloorLevels.h"

void FloorLevels::StartGame() //Call floorlevel, then Game Intro
{
    Heroes mainPlayer;
    Enemy wolf;

    std::vector<Potion> potions;
    std::string heroName = "";
    Weapon sword(12);
    mainPlayer.EquippedWeapon(mainPlayer, sword);

    TextPrompts::GameIntro();
	
    TextPrompts::DisplayMessage("Now press Enter and please type in the name of your Hero...");
    system("cls");

    do {
        std::cout << "Type your Hero Name then press Enter: \n";
        std::getline(std::cin, heroName);
        if (heroName == "")
        {
            std::cout << "Name cannot be empty. Try again!\n\n";
            TextPrompts::PressEnterToContinue();
        }
    } while (heroName == "");

    TextPrompts::DisplayMessage("Welcome " + heroName + "! I wish you luck!");
    mainPlayer.SetName(heroName);
    TextPrompts::DisplayMessage("\n======Welcome to Floor 1======\n");
    
    std::vector<Heroes> heroes = {mainPlayer};
    std::vector<Enemy> floor1Enemies = {wolf};
	BattleResult result= BattleMechanic::Battle(heroes, floor1Enemies);

    if (result == BattleResult::Defeat)
    {
        std::cout << "\nGAME OVER!\n";
        return;
    }

    if (result == BattleResult::Fled)
    {
        TextPrompts::DisplayMessage("\nYou fled the dungeon.\n");
        return;
    }

    TextPrompts::DisplayMessage("\nCongrats!! You defeated Floor 1!\n");//Proceeda to floor 2

    std::vector<Enemy> floor2Enemies = {wolf, wolf};

    TextPrompts::DisplayMessage("\n======Welcome to Floor 2======\n");

    result = BattleMechanic::Battle(heroes, floor2Enemies);

    if (result == BattleResult::Defeat)
    {
        std::cout << "\nGAME OVER!\n";
        return;
    }

    if (result == BattleResult::Fled)
    {
        TextPrompts::DisplayMessage("\nYou fled the dungeon.\n");
        return;
    }

    TextPrompts::DisplayMessage("\nYou defeated Floor 2!\n");

    TextPrompts::DisplayMessage("\nCongratulations!\n");
    TextPrompts::DisplayMessage("You cleared the dungeon!\n");

}
