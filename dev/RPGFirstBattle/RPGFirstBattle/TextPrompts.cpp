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

void TextPrompts::GameIntro()
{
    DisplayMessage("Hello Player! Welcome to my first game!");
    DisplayMessage("As you play, you will need to press Enter to advance ahead...");
    DisplayMessage("Here you will fight monsters in several floors...");
    DisplayMessage("Beat all of them and you beat the game!");
    DisplayMessage("However... If you lose, you will have to start all over again!");
    DisplayMessage("You will play as the hero and try to see if you can beat the floors.");
}
