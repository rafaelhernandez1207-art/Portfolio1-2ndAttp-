#pragma once
class Weapon
{
   int mWeaponDamage;

 public:


   Weapon();

   Weapon(int weaponDamage);

   int GetWeaponDamage()const;
   void SetWeaponDamage(int& wpnDamage);
    
};

