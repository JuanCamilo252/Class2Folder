#pragma once
#include <string>

class Weapon
{
public:
	Weapon();
	int getDamage();
	void setName(std::string name);
	void setDamage(int damage);
	void setDurability(int durability);
	void DisplayWeapon();
	void ReduceDurability();


private:
	std::string _name;
	int _damage;
	int _durability;
};
