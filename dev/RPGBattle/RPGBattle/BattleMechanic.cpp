#include "BattleMechanic.h"

void BattleMechanic::PlayersBattleCommand(Heroes playersTurn, std::vector<Enemy> target)
{
	system("cls");
	std::cout << "===" << playersTurn.GetName() << "===" << std::endl;
	std::cout << "HP: " << playersTurn.GetHP() << "\n" << std::endl;

	for (int i = 0; i < target.size(); i++)
	{
		std::cout << "===" << target[i].GetName() << "===" << std::endl;
		std::cout << "HP: " << target[i].GetHP() << "\n" << std::endl;
	}

	std::cout << "\n<<<Battle Command>>>\n" << std::endl;
	std::cout << "1. Attack\n";
	std::cout << "2. Defend\n";
	std::cout << "3. Run away like your Life Depends on it! RETREAT!\n";

	std::string battleOption = "";//Variable outside for scoping reasons
	int numBattleOption = 0;
	bool exitBattle = false;

	while (true)
	{
		std::getline(std::cin, battleOption);
		try
		{
			numBattleOption = stoi(battleOption);

			if (numBattleOption > 0 && numBattleOption < 4)
			{
				break;
			}
			std::cout << "Invalid input, please enter 1 or 2: ";
		}
		catch (...)
		{
			std::cout << "Invalid input, please enter 1 or 2: ";
		}

	}
	do
	{
		switch(numBattleOption)
		{
		case Attack:
			
			break;
		case Defend:
			
			break;
		case Flee:
			
			break;
		default:
			break;
		}
	} while (!exitBattle);
}
