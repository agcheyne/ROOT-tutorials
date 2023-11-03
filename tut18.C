//learning compilation for performance (by typing <>.C+ or <>.C++)
//without compiling 23.3s
//with 5s

//need to add header files (by looking what couldnt be found)
#include "TStopwatch.h"
#include "TRandom2.h"

//stl header files from c++
#include <iostream>  //input/output stream  -- for cout and endl

using namespace std;

void tut18()
{
	TStopwatch t; //measures time


	TRandom2 *r = new TRandom2();
	
	double x = 0;
	
	for(int i=0; i<1e9; i++)
	{
		x += r->Rndm();
		
	}
	
	cout << x << endl;

	t.Print();
	
}
