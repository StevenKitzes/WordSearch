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

	srand((unsigned)time(NULL));	//	seed rand by system time
	
	cout << endl;		//	for output prettiness

	Grid test;

	doSearch(test);

	return 0;
}

//	member function definitions

void doSearch( Grid & grid ) {

	unsigned found = 0;		//	how many words were found in the grid?

	string item = "";
	string output = "Found: ";
	ifstream dict ("dictionary.txt");
	
	while( dict.good() ) {	//	while there are still good entries in the list

		getline( dict, item );		//	get a line from dict (file) and set that to 'item'

		if( item == "" ) continue;	//	skip this item if it is empty

		grid.resetChecked();		//	set grid of bools to false (not yet checked)
		if( checkWord( item, grid, output ) ) {
			found++;
		}

	}

	grid.display();

	cout << output << endl << "Total: " << found << " words!" << end2l;

	return;

}

bool checkWord( const string & item, Grid & grid, string & output ) {

	bool found = false;

	//	run through the grid checking the first letter in 'item' can be found
	for( unsigned y = 0; y < GRID_SIZE; y++ ) {
		for( unsigned x = 0; x < GRID_SIZE; x++ ) {
			if( grid.getChar(y,x) == (char)item[0]) {
				grid.setChecked(y,x);
				found = checkNextLetter( item, grid, output, y, x, 1 );
				if (found) return found;
			}
		}
	}
	return found;	//	if true is never returned, just return false
}

bool checkNextLetter( const string & item, Grid & grid, string & output, const unsigned & y, const unsigned & x, unsigned slot ) {
	bool chainAlive = false;
		
	if( slot == item.length() ) {
		output += (item + ", ");
		return true;
	}

	//	check above, if not already checked!
	if( y > 0 ) {	//	don't check above if we're already at the top!
		if( grid.getChar(y-1,x) == (char)item[slot] && !grid.checkSpot(y-1,x) ) {
			grid.setChecked(y-1,x);
			chainAlive = checkNextLetter( item, grid, output, y-1, x, slot+1 );
		}
	}
	//	check below, if not already checked!
	if( y < (GRID_SIZE-1) && !chainAlive) {	//	don't check below if we're already at the bottom!
		if( grid.getChar(y+1,x) == (char)item[slot] && !grid.checkSpot(y+1,x) ) {
			grid.setChecked(y+1,x);
			chainAlive = checkNextLetter( item, grid, output, y+1, x, slot+1 );
		}
	}
	//	check right, if not already checked!
	if( x < (GRID_SIZE-1) && !chainAlive) {	//	don't check right if we're already at the right!
		if( grid.getChar(y,x+1) == (char)item[slot] && !grid.checkSpot(y,x+1) ) {
			grid.setChecked(y,x+1);
			chainAlive = checkNextLetter( item, grid, output, y, x+1, slot+1 );
		}
	}
	//	check left, if not already checked!
	if( x > 0 && !chainAlive ) {	//	don't check left if we're already at the left!
		if( grid.getChar(y,x-1) == (char)item[slot] && !grid.checkSpot(y,x-1) ) {
			grid.setChecked(y,x-1);
			chainAlive = checkNextLetter( item, grid, output, y, x-1, slot+1 );
		}
	}
	return chainAlive;
}
