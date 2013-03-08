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

void doSearch( const Grid & grid ) {

	string item;
	ifstream dict ("dictionary.txt");
	
	while( dict.good() ) {
		getline( dict, item );

		if( item != "" )
			cout << item << " retrieved!" << end2l;
	}

	return;

}
