#pragma once
#include <array>
#include "Costumer.h"
#include "Product.h"
class Basket
{
public:
	Basket();
private:
	int id;
	Costumer costumer;
	std::string dateAndTime;
	std::array<Product, 8> listOfProducts;
};

