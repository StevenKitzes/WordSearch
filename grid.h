//	[97, 122] <<< ASCII values of all lowercase letters

#ifndef _grid
#define _grid

#include <string>
#include <iostream>

#include "main.h"

using namespace std;

class Grid {
public:
	Grid( void );
	void sayHi( void );
	void display( void );
	
	char getChar( unsigned y, unsigned x );
private:
	char spot[GRID_SIZE][GRID_SIZE];
};

#endif
