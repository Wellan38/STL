//------------------- Réalistation de la classe Analyser (Analyser.cpp) --------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
#include <fstream>
//-------------------------------------------------------------Include personnel
#include "Analyser.h"
#include "Log.h"
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------PUBLIC

//------------------------------------------------------------Méthodes publiques
void Analyser::GenerateGraphViz ( string fileName, bool exclude, int time)
//Algorithm
//	We go through the whole logs and count the occurences of each destination URL
//	then we send the data wanted into a file under the graphviz syntax.
{

}
//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur
Analyser::Analyser (string inputLogFileName)
// Algorithme
//	We try to get all the logs from the file whose name is given as a parameter.
{
	ifstream input (inputLogFileName, ios::in);

	if (input)
	{	Log l;
		while ( input >> l)
		{	logList.push_back(l);
		}
	}
	else
	{	cerr << "Erreur à l'ouverture du fichier" << endl;
	}
}
//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
