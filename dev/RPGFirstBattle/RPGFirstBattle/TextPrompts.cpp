#include "TextPrompts.h"

void TextPrompts::DisplayMessage(std::string message)
{
    system("cls");//It clears the screen first then displays the next output (in this case the message below)
    std::cout << "==================================================================" << std::endl;
    std::cout << "    " << message << "" << std::endl;
    std::cout << "==================================================================\n\n" << std::endl;
    PressEnterToContinue();
    std::cout << "\n";
}

void TextPrompts::PressEnterToContinue()
{
    std::cout << "Press Enter to Continue..." << std::endl;
    std::cin.get();
}

void TextPrompts::GameIntro(Heroes& hero, std::string& heroName)
{
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
    hero.SetName(heroName);
}
