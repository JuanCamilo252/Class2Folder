#pragma once

class Rectangle {

public:
	Rectangle() = default;

	Rectangle(int height, int width);
	
	void PrintArea();
	
private:
	int _height;
	int _width;
};