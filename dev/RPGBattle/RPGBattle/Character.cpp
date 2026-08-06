#include "Character.h"

std::string Character::GetName()
{
    return mName;
}

void Character::SetName(std::string name)
{
    mName = name;
}

int Character::GetHP()
{
    return mHP;
}

void Character::SetHP(int HP)
{
    mHP = HP;
}

int Character::GetMP()
{
    return mMP;
}

void Character::SetMP(int MP)
{
    mMP = MP;
}

int Character::GetAttack()
{
    return mAttack;
}

void Character::SetAttack(int attack)
{
    mAttack = attack;
}

int Character::GetDefense()
{
    return mDefense;
}

void Character::SetDefense(int defense)
{
    mDefense = defense;
}

int Character::GetMagic()
{
    return mMagic;
}

void Character::SetMagic(int magic)
{
    mMagic = magic;
}

int Character::GetMagicDefense()
{
    return mMagicDefense;
}

void Character::SetMagicDefense(int magicDefense)
{
    mMagicDefense = magicDefense;
}

int Character::GetSpeed()
{
    return mSpeed;
}

void Character::SetSpeed(int speed)
{
    mSpeed = speed;
}
