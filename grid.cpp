#include <stdlib.h>	//	needed for srand(), rand()

#include "main.h"
#include "grid.h"

Grid::Grid( void ) {

	for( unsigned i = 0; i < GRID_SIZE; i++ ) {
		for( unsigned j = 0; j < GRID_SIZE; j++ ) {
			spot[i][j] = (char)(rand() % 26 + 97);
		}
	}

};

//	member function definitions

void Grid::display( void ) {
	cout << "Current grid content:" << endl;
	for( unsigned i = 0; i < GRID_SIZE; i++ ) {		//	for each row
		for( unsigned j = 0; j < GRID_SIZE; j++ ) {	//	for each item in the row
			cout << (j ? " " : "") << spot[i][j];
		}
	cout << endl;
	}
}

char Grid::getChar( unsigned y, unsigned x ) {

	return spot[y][x];

}

void Grid::sayHi( void ) {
	cout << end2l << "Hello, World!" << end2l;
}
