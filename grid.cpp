#include <stdlib.h>	//	needed for srand(), rand()

#include "main.h"
#include "grid.h"

Grid::Grid( void ) {

	for( unsigned y = 0; y < GRID_SIZE; y++ ) {
		for( unsigned x = 0; x < GRID_SIZE; x++ ) {
			spot[y][x] = (char)(rand() % 26 + 97);
		}
	}

	resetChecked();

};

//	member function definitions

void Grid::sayHi( void ) const {
	cout << end2l << "Hello, World!" << end2l;
}

void Grid::display( void ) const {
	cout << "Current grid content:" << end2l;
	for( unsigned y = 0; y < GRID_SIZE; y++ ) {		//	for each row
		for( unsigned x = 0; x < GRID_SIZE; x++ ) {	//	for each item in the row
			cout << (x ? " " : "") << spot[y][x];
		}
	cout << endl;
	}
}

void Grid::displayChecked( void ) const {
	cout << "Current checked status:" << end2l;
	for( unsigned y = 0; y < GRID_SIZE; y++ ) {		//	for each row
		for( unsigned x = 0; x < GRID_SIZE; x++ ) {	//	for each item in the row
			cout << (x ? " " : "") << checked[y][x];
		}
	cout << endl;
	}
}

char Grid::getChar( unsigned y, unsigned x ) const {

	return spot[y][x];

}

bool Grid::checkSpot( unsigned y, unsigned x ) const {

	return checked[y][x];

}

void Grid::resetChecked( void ) {
	for( unsigned y = 0; y++ < GRID_SIZE; ) {
		for( unsigned x = 0; x++ < GRID_SIZE; ) {
			checked[y][x] = false;
		}
	}
}
