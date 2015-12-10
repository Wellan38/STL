//------------------- Réalistation de la classe Analyser (Analyser.cpp) --------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>
#include <exception>
//-------------------------------------------------------------Include personnel
#include "Analyser.h"
//------------------------------------------------------------------- Constantes

const string BASE_URL = "http://intranet-if.insa-lyon.fr";

const string CSS = ".css";
const string PNG = ".png";
const string JS = ".js";
const string JPG = ".jpg";
const string GIF = ".gif";
const string ICO = ".ico";
const vector<string> EXTENSIONS = {CSS, PNG, JS, JPG, GIF, ICO}; // extensions to be excluded

const int NB_TOP_PAGES_TO_DISPLAY = 10;

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

		Log it = *debut;

		if (!(exclude && isToBeExcluded(it)))
		{

			if (!(time <= 23 && time >= 0 && respectsTime(it, time)))
			{
				//We look into our temporary data if we have it already

				StringIntPair pair ((*debut).urlDest, 1);
				list<StringIntPair>::iterator found = find(listOccurences.begin(), listOccurences.end(), pair);

				if (found == listOccurences.end())	//TO check
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
//	We go through the whole logs and count the occurences of each destination URL
//	then we send the data wanted into a file under the graphviz syntax.
{
	//map(string, int) occurences;

	Loglist::const_iterator debut = logList.begin();
	Loglist::const_iterator fin = logList.end();

	for ( ; debut != fin; debut ++)
	{

	}

}
//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur
Analyser::Analyser ( ifstream &input )
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
{
#ifdef MAP
	cout << "-------Destruction de Analyser" << endl;
#endif
}
//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE
void Analyser::displayAllLogs ( )
{	Loglist::const_iterator debut = logList.begin();
	Loglist::const_iterator fin = logList.end();

	for ( ; debut != fin; debut ++)
	{	Log l = (*debut);
		cout << l << endl;
	}
}

bool Analyser::isToBeExcluded(Log &aLog)
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
{
	bool res;

	if (t != 23)
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

bool Analyser::startsWith(const string& s1, const string& s2)
{
    return s2.size() <= s1.size() && s1.compare(0, s2.size(), s2) == 0;
}

bool Analyser::endsWith (const string &fullString, const string &ending)
{
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

//------------------------------------------------------------Méthodes protégées
