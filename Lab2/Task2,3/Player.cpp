#include "Player.h"
#include <iostream>
Player::Player(std::string name, std::array<Weapon,3> inventory)
	:_name(name), _score(0), _inventory(inventory)
{
}

void Player::DisplayStats() {
	std::cout << "Name: "<<_name<<"\n";
	std::cout << "Score: "<<_score<<"\n";
	std::cout << "Inventory: "<<"\n\n";
	for (Weapon weapon : _inventory) {
		weapon.DisplayWeapon();
	}
}
int Player::getScore() { return _score; }
void Player::UpdateScore() {
	int count = 0;
	for (Weapon weapon : _inventory) {
		count += weapon.getDamage();
	}
	_score = count;
}
