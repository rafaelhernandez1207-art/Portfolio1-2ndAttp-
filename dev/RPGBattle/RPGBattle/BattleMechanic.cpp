#include "BattleMechanic.h"

void BattleMechanic::PlayerAttack(Heroes playersTurn, std::vector<Enemy>& target)
{
	if (target.size() == 1)
	{
		std::cout << playersTurn.GetName() << " attacks " << target[0].GetName()
			<< " for " << playersTurn.GetAttack() << " Damage!\n";
		target[0].SetHP(target[0].GetHP() - playersTurn.GetAttack());

		std::cout << "===" << playersTurn.GetName() << "===" << std::endl;
		std::cout << "HP: " << playersTurn.GetHP() << "\n" << std::endl;

		std::cout << "===" << target[0].GetName() << "===" << std::endl;
		std::cout << "HP: " << target[0].GetHP() << "\n" << std::endl; //LOOPS HERE
	}
	else
	{
		for (int i = 0; i < target.size(); i++)
		{
			std::cout << i + 1 << ". " << target[i].GetName() << " HP: " << target[i].GetHP() << "\n";
		}
		std::cout << "\nType a number next to the enemy you wish to Attack and press Enter: ";
		
		std::string targetInput = "";
		int numTargetInput = 0;

		while (true)
		{
			std::getline(std::cin, targetInput);
			try
			{
				numTargetInput = stoi(targetInput);

				if (numTargetInput > 0 && numTargetInput < target.size() + 1)
				{
					std::cout << playersTurn.GetName() << " attacks " << target[numTargetInput - 1].GetName()
						<< " for " << playersTurn.GetAttack() << " Damage!\n";

					target[numTargetInput - 1].SetHP(target[numTargetInput - 1].GetHP() - playersTurn.GetAttack());
					break;
				}
				std::cout << "Invalid input, please enter a number between 1 or " << target.size() << ": ";
			}
			catch (...)
			{
				std::cout << "Invalid input, please enter a number between 1 or " << target.size() << ": ";
			}
		}
	}
}

void BattleMechanic::PlayersBattleCommand(Heroes& playersTurn, std::vector<Enemy>& target)
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
			PlayerAttack(playersTurn, target);
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
