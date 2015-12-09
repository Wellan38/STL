using namespace std;

#include <iostream>
#include "Analyser.h"

StringIntPair pair1("pair1", 1);
StringIntPair pair2("pair2", 2);

if (pair1 < pair2)
{
	cout << "pair1 <= pair2" << endl;
}
else
{
	cout << "pair2 < pair1" << endl;
}
