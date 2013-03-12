//	[97, 122] <<< ASCII values of all lowercase letters

#ifndef _grid
#define _grid

#include <string>
#include <iostream>

#include "main.h"

using namespace std;

struct Node {
	char c;
	bool checked;
};	//	node

class Grid {
public:
	Grid( void );
	void sayHi( void ) const;
	void display( void ) const;
	void displayChecked( void ) const;
	
	char getChar( unsigned y, unsigned x ) const;

	bool checkSpot( unsigned y, unsigned x ) const;

	void setChecked( unsigned y, unsigned x);
	void resetChecked( void );
private:
	Node spot[GRID_SIZE][GRID_SIZE];
};

#endif
