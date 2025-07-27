#pragma once
#include <string>


class Costumer {
public:
	Costumer(std::string name, int phoneNumber, std::string email);

private:
	std::string _name;
	int _phoneNumber;
	std::string _email;
};