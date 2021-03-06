#ifndef main_h
#define main_h

#ifndef end2l
	#define end2l endl<<endl
#endif

#ifndef GRID_SIZE
	#define GRID_SIZE 10
#endif

#include "grid.h"

using namespace std;

void doSearch( Grid & grid );
bool checkWord( const string & item, Grid & grid, string & output );
bool checkNextLetter( const string & item, Grid & grid, string & output, const unsigned & y, const unsigned & x, unsigned slot );

#endif
