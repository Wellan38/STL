//------------------- Réalistation de la classe Analyser (Analyser.cpp) --------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <map>
//-------------------------------------------------------------Include personnel
#include "Analyser.h"
//------------------------------------------------------------------- Constantes

const string BASE_URL = "http://intranet-if.insa-lyon.fr";

const string CSS = ".css";
const string PNG = ".png";
const string JS = ".js";
const vector<string> EXTENSIONS {CSS, PNG, JS}; // extensions to be excluded

//------------------------------------------------------------------------PUBLIC

//------------------------------------------------------------Méthodes publiques

void Analyser::DisplayTenMostVisited ( bool exclude, int time )
{

}

void Analyser::DisplayTenMostVisited ( bool exclude, int time )
{

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
	{	//cout << logList << endl;
	}
}

bool Analyser::isToBeExcluded(Log aLog)
{
	bool res = false;

	int i;

	for (i = 0; i < )

	return res;
}

bool Analyser::startsWith(const string& s1, const string& s2)
{
    return s2.size() <= s1.size() && s1.compare(0, s2.size(), s2) == 0;
}

static bool Analyser::endsWith (string const &fullString, string const &ending)
{
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

//------------------------------------------------------------Méthodes protégées
