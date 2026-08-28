#include "SaveAndLoad.h"

void SaveAndLoad::SavePlayer(std::vector<Heroes>& heroes)
{
    std::ofstream saveFile("playerFile.txt");

    if (!saveFile.is_open())
    {
        std::cout << "Error: Could not create save file.\n";
        return;
    }

    for (int i = 0; i < heroes.size(); i++)
    {
        saveFile << heroes[i].GetName() << "|" << heroes[i].GetHP() << "\n";
    }

    saveFile.close();

    std::cout << "Game saved successfully!\n";
}

void SaveAndLoad::LoadGame(std::vector<Heroes>& heroes)
{
    std::ifstream loadFile("playerFile.txt");

    if (!loadFile.is_open())
    {
        std::cout << "Error: Could not open save file.\n";
        return;
    }

    // Remove any heroes currently in the vector
    heroes.clear();

    std::string name;
    std::string healthString;

    while (getline(loadFile, name, '|'))
    {
        getline(loadFile, healthString);

        Heroes hero;

        hero.GetName() = name;
        hero.SetHP(stoi(healthString));

        heroes.push_back(hero);
    }

    loadFile.close();

    std::cout << "Game loaded successfully!\n";
}
