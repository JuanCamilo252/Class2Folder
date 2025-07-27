#include <iostream>
#include "Weapon.h"
#include "Player.h"
#include <array>
int main() {

	std::array<Weapon, 3> listOfWeapons;
	listOfWeapons[0].setName("Sword");
	listOfWeapons[0].setDamage(2);
	listOfWeapons[0].setDurability(50);
	listOfWeapons[1].setName("Spear");
	listOfWeapons[1].setDamage(3);
	listOfWeapons[1].setDurability(75);
	listOfWeapons[2].setName("Dagger");
	listOfWeapons[2].setDamage(1);
	listOfWeapons[2].setDurability(25);
	for (Weapon weapon : listOfWeapons) {
		weapon.DisplayWeapon();
	}

	listOfWeapons[0].ReduceDurability();
	listOfWeapons[1].ReduceDurability();
	listOfWeapons[1].ReduceDurability();
	listOfWeapons[2].ReduceDurability();
	listOfWeapons[2].ReduceDurability();
	listOfWeapons[2].ReduceDurability();

	for (Weapon weapon : listOfWeapons) {
		weapon.DisplayWeapon();
	}
	system("pause");
	system("cls");

	Player player("Juan",listOfWeapons);
	player.DisplayStats();
	player.UpdateScore();
	player.DisplayStats();


	return 0;


}