#include <iostream>
#include "Player.h"

struct P
{
	//Constructor
	P() {
		health = 100;
		dynamicHealth = (int*)malloc(sizeof (int));
	}
	//Destructor
	~P() {
		free(dynamicHealth);
	}	
	int health;
	int* dynamicHealth;
};
int main() {
	
	P player();


	
	return 0;
}