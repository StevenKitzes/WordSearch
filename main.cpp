#include <cstdlib>
#include <string>
#include <iostream>

#include <fstream>		//	for file i/o

#include <stdlib.h>		//	for srand() and rand()
#include <time.h>		//	to seed srand()

#include "main.h"
#include "grid.h"

using namespace std;

int main() {

	srand(time(NULL));	//	seed rand by system time
	
	cout << endl;		//	for output prettiness

	Grid test;

	doSearch(test);

	return 0;
}

//	member function definitions

void doSearch( Grid & grid ) {

	unsigned found = 0;		//	how many words were found in the grid?

	string item;
	ifstream dict ("dictionary.txt");
	
	while( dict.good() ) {

		getline( dict, item );		//	get a line from dict (file) and set that to 'item'

		if( item == "" ) continue;	//	skip this item if it is empty

		grid.resetChecked();
		if( checkWord( item, grid ) ) {
			found++;
		}

	}

	cout << "Discovered " << found << " words in the grid!  Nice!" << end2l;

	return;

}

bool checkWord( const string & item, Grid & grid ) {

	//	run through the grid checking the first letter in 'item' can be found
	for( unsigned y = 0; y < GRID_SIZE; y++ ) {
		for( unsigned x = 0; x < GRID_SIZE; x++ ) {
			if( grid.getChar(y,x) == (char)item[0])
				return checkNextLetter( item, grid, 1 );
		}
	}
	return false;	//	if true is never returned, just return false
}

bool checkNextLetter( const string & item, Grid & grid, unsigned slot ) {
	
}
