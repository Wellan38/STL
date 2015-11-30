using namespace std;

#include "Log.h"
#include <list>
#include <iostream>

int main()
{
	list<Log> logList;

	Log l;
	while ( cin >> l)
	{
		logList.push_back(l);
	}

	for(list<Log>::iterator it = logList.begin(); it != logList.end(); ++it)
	{
		cout << *it << endl;
	}

}
