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
