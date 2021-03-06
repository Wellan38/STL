//------------------- Réalistation de la classe Analyser (Analyser.cpp) --------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <algorithm>
#include <exception>
#include <set>
//-------------------------------------------------------------Include personnel
#include "Analyser.h"
//------------------------------------------------------------------- Constantes


//------------------------------------------------------------------------PUBLIC

//------------------------------------------------------------Méthodes publiques

void Analyser::DisplayTenMostVisited ( bool exclude, int time )
{
	Loglist::const_iterator debut = logList.begin();
	Loglist::const_iterator fin = logList.end();

	list<StringIntPair> listOccurences;

	for ( ; debut != fin; debut++)
	{
		//Filter the different logs according to the filters passed as parameter

		Log log = *debut;

		if (passesFilters(log, time, exclude))
		{

			// We check that the destination URL is correct
			string destination = log.urlDest;
			if (startsWith(destination, BASE_URL))
			{
				destination.erase(0, BASE_URL.length());
			}

			//We look into our temporary data if we have it already

			StringIntPair pair (destination, 1);
			list<StringIntPair>::iterator found = find(listOccurences.begin(), listOccurences.end(), pair);

			if (found == listOccurences.end())
			{
				#ifdef MAP
					cout << "The url " << (*debut).urlDest << " was not in the list." << endl;
				#endif
				listOccurences.push_back(pair);
			}
			else
			{
				(*found).nb ++;
			}
		}
	}
	// We need to sort our temporary data to make the top 10 selection easier
	listOccurences.sort();
	listOccurences.reverse();

	list<StringIntPair>::const_iterator begin = listOccurences.begin();
	int i;
	bool sameRank = false;	//Used to check if the i+1 item in the list has the same amount of views as the ith element.
							//In which case it has to be displayed.
	const int SIZE = listOccurences.size();
	for ( i=0; (i < NB_TOP_PAGES_TO_DISPLAY || sameRank) && i < SIZE; i++)
	{
		StringIntPair p = *(begin++);
		cout << p.aString << " (" << p.nb << " hits)" << endl;

		list<StringIntPair>::const_iterator next = begin;
		next ++;
		sameRank = (i+1 < SIZE) && (p.nb == (*(next)).nb);
	}
}

void Analyser::GenerateGraphViz ( ofstream &output, bool exclude, int time)
//Algorithm
//	We go through the whole logs and count the occurrences of each destination URL
//	then we send the data wanted into a file under the graphviz syntax.
{
	map<StringPair, int> occurences;		//Associates the travel from a page to an other to an int.
	Loglist::const_iterator begin = logList.begin();
	Loglist::const_iterator end = logList.end();

	for ( ; begin != end; begin ++)
	{
		Log log = (*begin);
		if (passesFilters(log, time, exclude))
		{
			string destination = log.urlDest;
			string origin = log.urlOrigin;

			if (startsWith(destination, BASE_URL))
			{
				destination.erase(0, BASE_URL.length());
			}
			if (startsWith(origin, BASE_URL))
			{
				origin.erase(0, BASE_URL.length());
			}

			StringPair key (destination, origin);
			map<StringPair, int>::iterator found = occurences.find(key);

			if ( found == occurences.end() )
			{
				occurences[key] = 1;
			}
			else
			{
				occurences[key]++;
			}

		}
	}

	//Writing out the file.
	output << "digraph {" << endl;
	map<StringPair, int>::const_iterator nodesIterator = occurences.begin();
	for ( ; nodesIterator != occurences.end() ; nodesIterator ++)
	{
		output << "<" << nodesIterator->first.s2 << "> -> <" <<nodesIterator->first.s1;
		output << "> [label=" << nodesIterator->second << "];" << endl;
	}

	output << "}" << endl;
}
//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur
Analyser::Analyser ( ifstream &input, string baseUrl ) : BASE_URL(baseUrl)
// Algorithme
//	We try to get all the logs from the file whose name is given as a parameter.
{
#ifdef MAP
	cout << "-------Construction de Analyser" << endl;
#endif


	if ( input )
	{	Log l;
		while ( input >> l )
		{
#ifdef MAP
			cout << l << endl;
#endif
			logList.push_back( l );
		}
	}
	else
	{	cerr << "Erreur à l'ouverture du fichier" << endl;
	}
}

Analyser::~Analyser ( )
//Algorithm
{
#ifdef MAP
	cout << "-------Destruction de Analyser" << endl;
#endif
}
//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE
void Analyser::displayAllLogs ( )
//Algorithm
{	Loglist::const_iterator debut = logList.begin();
	Loglist::const_iterator fin = logList.end();

	for ( ; debut != fin; debut ++)
	{	Log l = (*debut);
		cout << l << endl;
	}
}

ostream & operator << (ostream &os, const Analyser &an)
//Algorithm
{
	Loglist::const_iterator debut = an.logList.begin();
		Loglist::const_iterator fin = an.logList.end();

		for ( ; debut != fin; debut ++)
		{	Log l = (*debut);
			os << l << endl;
		}

		return os;
}

bool Analyser::passesFilters(Log &aLog, int time, bool exclude)
//Algorithm
{
	bool res = !(exclude && isToBeExcluded(aLog)) && respectsTime(aLog, time) && operationSuccessful(aLog);
	return res;
}

bool Analyser::isToBeExcluded(Log &aLog)
//Algorithm
{
	bool res = false;

	unsigned int i;
	string s = aLog.urlDest;

	for (i = 0; i < EXTENSIONS.size(); i++)
	{
		if (endsWith(s, EXTENSIONS[i]))
		{
			res = true;
		}
	}

	return res;
}

bool Analyser::respectsTime(Log &aLog, int t)
//Algorithm
{
	bool res;
	if (t == -1)
	{
		return true; //t = -1 => no constraints
	}
	else if (t != 23)
	{
		res = ((aLog.hour - aLog.diffGreenwich) == t) ||
			  ((aLog.hour - aLog.diffGreenwich) == t+1 &&
			   aLog.minute == 0 && aLog.second == 0);
	}
	else
	{
		res = ((aLog.hour - aLog.diffGreenwich) == t) ||
			  ((aLog.hour - aLog.diffGreenwich) == 0 &&
			   aLog.minute == 0 && aLog.second == 0);
	}

	return res;
}

bool Analyser::operationSuccessful(Log &aLog)
//Algorithm
{
	bool res = (aLog.statusCode == VALID_CODE);
	return res;
}

bool Analyser::startsWith(const string& s1, const string& s2)
//Algorithm
{
	bool res = s2.size() <= s1.size() && s1.compare(0, s2.size(), s2) == 0;
	return res;
}

bool Analyser::endsWith (const string &fullString, const string &ending)
//Algorithm
{
	bool res = false;
    if (fullString.length() >= ending.length())
    {
        res = (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    }
    return res;
}

//------------------------------------------------------------Méthodes protégées
