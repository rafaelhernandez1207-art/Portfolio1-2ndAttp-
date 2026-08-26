#include "BattleMechanic.h"
#include "TurnOrder.h"



void BattleMechanic::PlayerAttack(Heroes playersTurn, std::vector<Enemy>& target)
{
	bool isAlive = true;
	
		if (target.size() == 1)
		{
			std::cout << playersTurn.GetName() << " attacks " << target[0].GetName()
				<< " for " << playersTurn.GetAttack() << " Damage!\n";
			target[0].SetHP(target[0].GetHP() - playersTurn.GetAttack());
			target[0].SetHP((target[0].GetHP() >= 0) ? target[0].GetHP() : 0); //Prevents HP from going below zero

			if (target[0].GetHP() == 0)
			{
				std::cout << target[0].GetName() << " is Defeated!\n";
				isAlive = false;
			}
		}
		else
		{
			for (int i = 0; i < target.size(); i++)
			{
				std::cout << i + 1 << ". " << target[i].GetName() << " HP: " << target[i].GetHP() << "\n";
				if (target.size() > 1)
				{
					if (target[i].GetHP() <= 0)
					{
						target.erase(target.begin() + i);
						i -= 1;
					}
				}
				
			}
			std::cout << "\nType a number next to the enemy you wish to Attack and press Enter: ";

			std::string targetInput = "";
			int numTargetInput = 0;


			
				std::getline(std::cin, targetInput);
				try
				{
					numTargetInput = stoi(targetInput);


					if (numTargetInput > 0 && numTargetInput <= target.size())
					{
						std::cout << playersTurn.GetName() << " attacks " << target[numTargetInput - 1].GetName()
							<< " for " << playersTurn.GetAttack() << " Damage!\n";

						target[numTargetInput - 1].SetHP(target[numTargetInput - 1].GetHP() - playersTurn.GetAttack());
						target[numTargetInput - 1].SetHP((target[numTargetInput - 1].GetHP() >= 0) ? target[numTargetInput - 1].GetHP() : 0);
						if (target[numTargetInput - 1].GetHP() == 0)
						{
							std::cout << target[numTargetInput - 1].GetName() << " is Defeaeted!";
							if (target.size() > 1)
							{
								target.erase(target.begin() + numTargetInput - 1);
							}
							
							isAlive = false;
						}
					}
					std::cout << "Invalid input, please enter a number between 1 or " << target.size() << ": ";
				}
				catch (...)
				{
					std::cout << "Invalid input, please enter a number between 1 or " << target.size() << ": ";
				}
			
		}
}

void BattleMechanic::EnemyAttack(Enemy enemiesTurn, std::vector<Heroes>& target)
{
	bool isAlive = true;
	
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
				std::cout << target[0].GetName() << " is Defeated!\n";
				isAlive = false;
			}
		}
		else
		{
			//int randNum = rand() % (max - min + 1) + min;
			for (int i = 0; i < target.size(); i++)
			{
				if (target[i].GetHP() <= 0)
				{
					target.erase(target.begin() + i);
					i -= 1;
				}
			}
			
			int min = 0;
			int max = target.size();
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

bool BattleMechanic::PlayersBattleCommand(Heroes& playersTurn, std::vector<Heroes>& party, std::vector<Enemy>& enemies)
{
		system("cls");

		std::cout << playersTurn.GetName() << std::endl;
		std::cout << "HP: " << playersTurn.GetHP() << "\n" << std::endl;
		
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i].GetHP() > 0)
			{
				std::cout << i + 1 << ") " << enemies[i].GetName() << std::endl;
				std::cout << "HP: " << enemies[i].GetHP() << "\n" << std::endl;
			}
		}
	
			std::cout << "\n<<<Battle Command>>>\n" << std::endl;
			std::cout << "1. Attack\n";
			std::cout << "2. Defend\n";
			std::cout << "3. Use Item\n";
			std::cout << "4. Run away like your Life Depends on it! RETREAT!\n";

			std::string battleOption = "";//Variable outside for scoping reasons
			int numBattleOption = 0;
		

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

			switch(numBattleOption)
			{
				case Attack:
					PlayerAttack(playersTurn, enemies);
					return false;

				case Defend:
			
					return false;

				case UseItem:
					Heroes::UsePotion(playersTurn, party);
					return false;

				case Flee:
					std::cout << "You have successfully Fled!!\n";
					std::cout << "\nPress Enter to continue...\n";
					std::cin.get();
					return true;

				default:
					std::cout << "Invalid option, try again...\n";
					return false;
			}
			
}

void BattleMechanic::Battle(std::vector<Heroes>& heroes, std::vector<Enemy>& enemies)
{
	bool fled = false;
	while (true)
	{
		bool heroesAlive = false;
		bool enemiesAlive = false;

		for (int i = 0; i < heroes.size(); i++)// Check if heroes living
		{
			if (heroes[i].GetHP() > 0)
			{
				heroesAlive = true;
				break;
			}
		}

		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i].GetHP() > 0)
			{
				enemiesAlive = true;
				break;
			}
		}

		if (!heroesAlive || !enemiesAlive)// Battle is over
		{
			break;
		}

		std::vector<TurnOrder> turnOrder;
		
		TurnOrder::CreateTurnOrder(heroes, enemies, turnOrder);

		std::cout << "\n========== NEW ROUND ==========\n\n";

		for (int i = 0; i < turnOrder.size(); i++)
		{
			TurnOrder currentTurn = turnOrder[i];

			if (currentTurn.GetIsHero())// HERO TURN
			{
				if (heroes[currentTurn.GetIndex()].GetHP() <= 0)// Will skip hero if dead
				{
					continue;
				}

				std::cout << "\n" << heroes[currentTurn.GetIndex()].GetName() << "'s turn!\n\n";
				 fled = PlayersBattleCommand(heroes[currentTurn.GetIndex()], heroes, enemies);

				if (fled)//Flee will make this true
				{
					break;
				}
			}
			else
			{
				if (enemies[currentTurn.GetIndex()].GetHP() <= 0)
				{
					continue;
				}
				EnemyAttack(enemies[currentTurn.GetIndex()], heroes);
			}

		}
		if (fled)
		{
			system("cls");
			std::cout << "You have successfully escaped!\n\n";
			break;
		}
	}

	bool heroesAlive = false;
	bool enemiesAlive = false;

	for (int i = 0; i < heroes.size(); i++)
	{
		if (heroes[i].GetHP() > 0)
		{
			heroesAlive = true;
			break;
		}
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].GetHP() > 0)
		{
			enemiesAlive = true;
			break;
		}
	}
	std::cout << "\n========== BATTLE OVER ==========\n\n";

	if (heroesAlive)
	{
		if (!fled)
		{
			std::cout << "Heroes win!\n";
		}
		else
		{
			system("cls");
			std::cout << "You have escaped the Tower!\n\n";
		}
	}
	else
	{
		std::cout << "Enemies win!\n";
	}
}
