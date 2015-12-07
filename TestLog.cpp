using namespace std;

#include "Log.h"
#include <vector>
#include <iostream>

int main()
{
	std::vector<Log> logVector;

	Log l;

	while(cin >> l)
	{
		logVector.push_back(l);
	}

	std::vector<Log>::iterator it;

	for (it = logVector.begin(); it != logVector.end(); it++)
	{
		cout << *it << endl;
	}

}
