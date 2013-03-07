#include <stdlib.h>	//	needed for srand(), rand()

#include "main.h"
#include "grid.h"

Grid::Grid( void ) {

	name = "";
	for( int i = 0; i < 10; i++ ) {
		name += (char)(rand() % 26 + 97);
	}

	for( unsigned i = 0; i < GRID_SIZE; i++ ) {
		for( unsigned j = 0; j < GRID_SIZE; j++ ) {
			spot[i][j] = (char)(rand() % 26 + 97);
			cout << spot[i][j] << " to spot[" << i << "][" << j << "]";
		}
		cout << endl;
	}

};

void Grid::display( void ) {
	cout << "Current grid content:" << endl;
	for( unsigned i = 0; i < GRID_SIZE; i++ ) {		//	for each row
		for( unsigned j = 0; j < GRID_SIZE; j++ ) {	//	for each item in the row
			cout << (j ? " " : "") << spot[i][j];
		}
	cout << endl;
	}
};

void Grid::sayHi( void ) {
	cout << end2l << "Hi, Planethead! I'm " << name << end2l;
};
