#include <iostream>
#include "transition.h"
#include <vector>
#include <array>
int main() {
	int input;
	std::cout << "Provide a State";
	std::cin >> input;
	transition var = transition::Gameplay;
	switch (input)

	{
	case transition::MainMenu:
		std::cout << "You are in the Main Menu";
		break;
	case transition::Gameplay:
		std::cout << "This Gameplay is insane";
		break;
	case transition::Exit:
		std::cout << "Exiting...";
		break;
	default:
		break;
	}
	return 0;

}