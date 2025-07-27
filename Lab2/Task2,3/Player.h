#pragma once
#include "Weapon.h"
#include <string>
#include <array>
class Player
{
public:
	Player(std::string name,std::array<Weapon,3> inventory);
	void DisplayStats();
	void UpdateScore();
	int getScore();
private:
	std::string _name;
	int _score;
	std::array<Weapon, 3> _inventory;
};
