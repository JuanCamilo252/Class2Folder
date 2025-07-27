#include <iostream>
#include "GameCharacter.h"
#include <vector>

void FillArray(std::vector<GameCharacter>* listOfCharacters, int numberOfItems) {
	for (int i = 0; i < numberOfItems; i++)
	{
		GameCharacter character;
		character.name = "Character " + std::to_string(i);
		character.health = rand() % 50 + 50;
		character.level = rand() % 10 + 1;
		listOfCharacters->push_back(character);
	}
}
void DisplayAllObjects(GameCharacter listOfCharacters[], int size) {
	for (int i = 0; i < size; i++)
	{
		std::cout << "Name: "  << listOfCharacters[i].name<<"\n";
		std::cout << "Health: "  << listOfCharacters[i].health<<"\n";
		std::cout << "Level: "  << listOfCharacters[i].level<<"\n\n";
	}
}

void AverageHealth(GameCharacter listOfCharacters[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		count += listOfCharacters[i].health;
	}

	std::cout << "Average Health: " << (count / size);
}

int main(){
	srand(time(0));
	std::vector<GameCharacter> listOfCharacter;
	GameCharacter character;
	FillArray(&listOfCharacter, 3);
	DisplayAllObjects(listOfCharacter.data(), listOfCharacter.size());
	AverageHealth(listOfCharacter.data(), listOfCharacter.size());
	return 0;
}