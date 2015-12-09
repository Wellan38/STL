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
//-------------------------------------------------------------Include personnel
#include "Analyser.h"
//------------------------------------------------------------------- Constantes

const string BASE_URL = "http://intranet-if.insa-lyon.fr";

const string CSS = ".css";
const string PNG = ".png";
const string JS = ".js";
const vector<string> EXTENSIONS = {CSS, PNG, JS}; // extensions to be excluded

//------------------------------------------------------------------------PUBLIC

//------------------------------------------------------------Méthodes publiques

void Analyser::DisplayTenMostVisited ( bool exclude, int time )
{
	Loglist::const_iterator debut = logList.begin();
	Loglist::const_iterator fin = logList.end();

	map<std::string, int> mapOccurences;

	for ( ; debut != fin; debut++)
	{
		//Filter the different logs according to the filters passed as parameter

		Log it = *debut;

		if (!(exclude && isToBeExcluded(it) && (time > 23 || time < 0)
			&& respectsTime(it, time)))
		{
			//We look into our temporary data if we have it already
			map<string,int>::iterator trouve = mapOccurences.find((*debut).urlDest);
			if (trouve == mapOccurences.end())
			{	//We add the entry to the map
				trouve = mapOccurences.begin();
				mapOccurences.insert(trouve, pair<string, int>((*debut).urlDest, 0));
			}

			//We increment the int value (occurence)
			(*trouve).second ++;
		}

		// We need to sort our temporary data to make the selection easier



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
		{	cout << l << endl;
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
		res = (aLog.hour == t) || (aLog.hour == t+1 && aLog.minute == 0);
	}
	else
	{
		res = (aLog.hour == t) || (aLog.hour == 0 && aLog.minute == 0);
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
