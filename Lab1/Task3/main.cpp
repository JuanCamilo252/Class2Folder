#include "Person.h"
#include <iostream>
#include <array>


void PrintArray(Person arr[], int size) {

	for (int i = 0; i < size; i++)
	{
		std::cout << "Person " << i + 1 << "\n";
		std::cout << "Name: " << arr[i].name << "\n";
		std::cout << "Age: " << arr[i].age << "\n";
		std::cout << "Address: " << arr[i].address << "\n";
		std::cout << "Hobbies: \n";
		for (std::string val : arr[i].hobbies) {

			std::cout << val << "\n";

		}
	}

}

float AverageAge(Person arr[], int size) {
	float average = 0;
	for (int i = 0; i < size; i++)
	{
		average += arr[i].age;
	}
	return average /= size;

}

int main() {

	std::array<Person, 3> personArray;
	personArray[0].name = "Juan";
	personArray[0].age = 20;
	personArray[0].address = "Tisdall Street";
	personArray[0].hobbies.push_back("Video Games");
	personArray[0].hobbies.push_back("Hike");
	personArray[1].name = "Josue";
	personArray[1].age = 19;
	personArray[1].address = "Surrey";
	personArray[1].hobbies.push_back("Volleyball");
	personArray[1].hobbies.push_back("Video Games");
	personArray[1].hobbies.push_back("Learning");
	personArray[2].name = "Zinadine";
	personArray[2].age = 23;
	personArray[2].address = "UBC";
	personArray[2].hobbies.push_back("Nothing");
	personArray[2].hobbies.push_back("Breathing");
	personArray[2].hobbies.push_back("Sitting at Home");


	PrintArray(personArray.data(), personArray.size());
	std::cout << "\nAverage Age: "<< AverageAge(personArray.data(), personArray.size());
}