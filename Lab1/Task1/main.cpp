#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>
int Summ(std::array<int,5> arr) {
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}
	return sum;

}


int main() {
	srand(time(0));
	std::array<int, 5> integerArray;

	for (int& val : integerArray) {

		val = rand() % 51 + 50;
		std::cout << val<< "\n";

	}
	int summ = Summ(integerArray);

	std::cout << summ;
}