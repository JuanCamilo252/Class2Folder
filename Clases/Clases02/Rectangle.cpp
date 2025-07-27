#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int height, int width)
	:_height(height), _width(width)
{
}

void Rectangle::PrintArea() {
	std::cout << _height * _width << "\n";
}
