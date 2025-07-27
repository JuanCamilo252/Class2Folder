#include "Weapon.h"
#include <iostream>
Weapon::Weapon()
	:_name(""), _damage(0), _durability(0)
{
}
void Weapon::DisplayWeapon() {

	std::cout << "Name:" << _name << "\n";
	std::cout << "Damage:" << _damage << "\n";
	std::cout << "Durability:" << _durability << "\n\n";
}
void Weapon::setName(std::string name) {
	_name = name;
}
void Weapon::setDamage(int damage) {
	_damage = damage;
}
void Weapon::setDurability(int durability) {
	_durability = durability;
}
int Weapon::getDamage() { return _damage; }
void Weapon::ReduceDurability() {

	_durability--;
}