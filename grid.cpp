#include <stdlib.h>	//	needed for srand(), rand()

#include "main.h"
#include "grid.h"

Grid::Grid( void ) {

	name = "";
	for( int i = 0; i < 10; i++ ) {
		name += (char)(rand() % 26 + 97);
	}

};

void Grid::sayHi( void ) {
	cout << "Hi, Planethead! I'm " << name << end2l;
};
