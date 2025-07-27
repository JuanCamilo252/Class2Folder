#pragma once
#include <string>

class Player 
{
public:
	void Attack();
	void Heal();
	int GetHealth() {
		return _health;
	}
	void SetHealth(int health) {
		_health = health;
	}
private:
	int _health;
	std::string name;

};