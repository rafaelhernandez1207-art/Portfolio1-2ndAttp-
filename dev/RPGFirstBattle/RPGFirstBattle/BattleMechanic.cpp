#include "BattleMechanic.h"



void BattleMechanic::PlayerAttack(Heroes playersTurn, std::vector<Enemy>& target)
{
	bool isAlive = true;
	while (isAlive == true)
	{
		if (target.size() == 1)
		{
			std::cout << playersTurn.GetName() << " attacks " << target[0].GetName()
				<< " for " << playersTurn.GetAttack() << " Damage!\n";
			target[0].SetHP(target[0].GetHP() - playersTurn.GetAttack());
			target[0].SetHP((target[0].GetHP() >= 0) ? target[0].GetHP() : 0); //Prevents HP from going below zero

			std::cout << "===" << playersTurn.GetName() << "===" << std::endl;
			std::cout << "HP: " << playersTurn.GetHP() << "\n" << std::endl;

			std::cout << "===" << target[0].GetName() << "===" << std::endl;
			std::cout << "HP: " << target[0].GetHP() << "\n" << std::endl; //LOOPS HERE
			if (target[0].GetHP() == 0)
			{
				isAlive = false;
			}
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
						target[numTargetInput - 1].SetHP((target[numTargetInput - 1].GetHP() >= 0) ? target[numTargetInput - 1].GetHP() : 0);
						if (target[numTargetInput - 1].GetHP() == 0)
						{
							isAlive = false;
						}
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
}

void BattleMechanic::EnemyAttack(Enemy enemiesTurn, std::vector<Heroes>& target)
{
	bool isAlive = true;
	while (isAlive == true)
	{
		if (target.size() == 1)
		{
			std::cout << enemiesTurn.GetName() << " attacks " << target[0].GetName()
				<< " for " << enemiesTurn.GetAttack() << " Damage!\n";
			target[0].SetHP(target[0].GetHP() - enemiesTurn.GetAttack());
			target[0].SetHP((target[0].GetHP() >= 0) ? target[0].GetHP() : 0);

			std::cout << "===" << enemiesTurn.GetName() << "===" << std::endl;
			std::cout << "HP: " << enemiesTurn.GetHP() << "\n" << std::endl;

			std::cout << "===" << target[0].GetName() << "===" << std::endl;
			std::cout << "HP: " << target[0].GetHP() << "\n" << std::endl; //LOOPS HERE
			if (target[0].GetHP() == 0)
			{
				isAlive = false;
			}
		}
		else
		{
			//int randNum = rand() % (max - min + 1) + min;
			int min = 0;
			int max = target.size();
			std::vector<Heroes> tempVariable;
			int index = 0;
			index = rand() % (target.size());

			target[index].SetHP(target[index].GetHP() - enemiesTurn.GetAttack());
			target[index].SetHP((target[index].GetHP() >= 0) ? target[index].GetHP() : 0);

			std::cout << enemiesTurn.GetName() << " attacks " << target[index].GetName()
				<< " for " << enemiesTurn.GetAttack() << " Damage!\n";
			target[index].SetHP(target[index].GetHP() - enemiesTurn.GetAttack());

			if (target[index].GetHP() == 0)
			{
				isAlive = false;
			}
		}
	}
}

void BattleMechanic::PlayersBattleCommand(Heroes& playersTurn, std::vector<Enemy>& enemies)
{
	system("cls");
	std::cout << "===" << playersTurn.GetName() << "===" << std::endl;
	std::cout << "HP: " << playersTurn.GetHP() << "\n" << std::endl;

	for (int i = 0; i < enemies.size(); i++)
	{
		std::cout << "===" << enemies[i].GetName() << "===" << std::endl;
		std::cout << "HP: " << enemies[i].GetHP() << "\n" << std::endl;
	}

	std::cout << "\n<<<Battle Command>>>\n" << std::endl;
	std::cout << "1. Attack\n";
	std::cout << "2. Defend\n";
	std::cout << "3. Use Item\n";
	std::cout << "4. Run away like your Life Depends on it! RETREAT!\n";

	std::string battleOption = "";//Variable outside for scoping reasons
	int numBattleOption = 0;
	bool exitBattle = false;

	while (true)
	{
		std::getline(std::cin, battleOption);
		try
		{
			numBattleOption = stoi(battleOption);

			if (numBattleOption > 0 && numBattleOption < 5)
			{
				break;
			}
			std::cout << "Invalid input, please enter 1 thru 4: ";
		}
		catch (...)
		{
			std::cout << "Invalid input, please enter 1 thru 4: ";
		}

	}
	do
	{
		switch(numBattleOption)
		{
		case Attack:
			PlayerAttack(playersTurn, enemies);
			exitBattle = true;
			break;
		case Defend:
			
			break;
		case UseItem:

			break;
		case Flee:
			std::cout << "You have successfully Fled!!\n";
			std::cin.get();
			std::cout << "\nPress Enter to continue...\n";
			exitBattle = true;
			break;
		default:
			break;
		}
	} while (!exitBattle);
}
