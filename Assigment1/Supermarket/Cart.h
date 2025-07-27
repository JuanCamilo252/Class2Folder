#pragma once
#include "Costumer.h"
#include "Product.h"
#include <vector>
class Cart
{
public:

private:
	int id;
	Costumer costumer;
	std::string dateAndTime;
	std::vector<Product> listOfProducts;
};