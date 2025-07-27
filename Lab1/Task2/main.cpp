#include <iostream>
#include <array>
#include "Person.h"

void PrintArray(Person arr[],int size) {

	for (int i = 0; i < size; i++)
	{
		std::cout << "Person " << i + 1 << "\n";
		std::cout << "Name: " << arr[i].name << "\n";
		std::cout << "Age: " << arr[i].age << "\n";
		std::cout << "Address: " << arr[i].address << "\n";
	}

}

int main() {

	std::array<Person, 3> personArray;
	personArray[0].name = "Juan";
	personArray[0].age = 20;
	personArray[0].address = "Tisdall Street";
	personArray[1].name = "Josue";
	personArray[1].age = 19;
	personArray[1].address = "Surrey";
	personArray[2].name = "Zinadine";
	personArray[2].age = 23;
	personArray[2].address = "UBC";


	PrintArray(personArray.data(), personArray.size());

}