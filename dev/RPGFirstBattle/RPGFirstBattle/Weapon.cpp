#include "Weapon.h"
Weapon::Weapon()
{
	mWeaponDamage = 0;
}

Weapon::Weapon(int weaponDamage) : mWeaponDamage(weaponDamage)
{
}

int Weapon::GetWeaponDamage() const
{
	return mWeaponDamage;
}

void Weapon::SetWeaponDamage(int& wpnDamage)
{
	mWeaponDamage = wpnDamage;
}