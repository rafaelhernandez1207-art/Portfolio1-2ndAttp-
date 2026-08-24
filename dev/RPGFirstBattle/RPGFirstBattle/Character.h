#pragma once
#include <string>
class Character
{
	//private by default
	std::string mName;
	int mHP;
	int mMP;
	int mAttack;
	int mDefense;
	int mMagic;
	int mMagicDefense;
	int mSpeed;
	//A vector of Abilities(string name, int damage, int MPcost)

public:
	//Sort the order of characters by speed
	//Each character will have a turn
	Character();
	Character(std::string name, int HP, int MP, int attack, int defense, int magic, int magicDefense, int speed) :
		mName(name), mHP(HP), mMP(MP), mAttack(attack), mDefense(defense),
		mMagic(magic), mMagicDefense(magicDefense), mSpeed(speed) 
	{}

	std::string GetName();
	void SetName(std::string name);

	int GetHP();
	void SetHP(int HP);

	int GetMP();
	void SetMP(int MP);

	int GetAttack();
	void SetAttack(int attack);

	int GetDefense();
	void SetDefense(int defense);

	int GetMagic();
	void SetMagic(int magic);

	int GetMagicDefense();
	void SetMagicDefense(int magicDefense);

	int GetSpeed();
	void SetSpeed(int speed);

	
};

