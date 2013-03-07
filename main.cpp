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

	srand(time(NULL));
	
	cout << endl;

	string line;
	ifstream dict ("dictionary.txt");
	/*
	while( dict.good() ) {
		getline( dict, line );

		if( line != "" )
			cout << line << " retrieved!" << end2l;
	}
	*/

	Grid test;

	test.sayHi();

	return 0;
}
