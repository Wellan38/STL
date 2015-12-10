using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include "Analyser.h"

int main()
{
//	vector<StringIntPair> v;
//
//	v.push_back(StringIntPair("pair1", 2));
//	v.push_back(StringIntPair("pair2", 5));
//	v.push_back(StringIntPair("pair3", 1));
//	v.push_back(StringIntPair("pair4", 2));
//
//	vector<StringIntPair>::const_iterator it;
//
//	for (it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << endl;
//	}
//
//	cout << endl;
//
//	std::sort(v.begin(), v.end());
//
//	for (it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << endl;
//	}

	ifstream file("testIn.txt");

	Analyser an(file);

	an.DisplayTenMostVisited(true,9);

//	ifstream file("testIn.txt");
//
//	Analyser an(file);
//
//	an.testExclude();
//
//	return 0;



}
