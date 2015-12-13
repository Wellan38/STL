using namespace std;

#include <iostream>
#include "Analyser.h"

int main (int argc, char* argv[])
{
	if (argc > 1)
	{
		ifstream file(argv[1]);

		if (file)
		{
			Analyser an(file);

			an.DisplayTenMostVisited(false, -1);
		}
		else
		{
			cerr << "An error happened when opening the input file" << endl;
		}
	}

	return 0;
}
