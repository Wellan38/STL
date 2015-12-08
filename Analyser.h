//--------------------- Inteface de la classe Analyser (Analyser.h) ----------------------
#if ! defined (Analyser_H)
#define Analyser_H


//--------------------------------------------------------- Interfaces utilisées
#include "Log.h"
#include <list>
//------------------------------------------------------------------- Constantes
//------------------------------------------------------------------------ Types
using namespace std;
typedef list<Log> Loglist;
//------------------------------------------------------------------------------
// Rôle de la classe Analyser
// The Analyser class is capable of computing several stats on a how to declare a C++ chained listapache log file.
//------------------------------------------------------------------------------

class Analyser
{
	//--------------------------------------------------------------------PUBLIC
	public : 
	//--------------------------------------------------------Méthodes publiques
	void DisplayTenMostVisited ( bool exclude, int time );
	// Mode d'emploi:
	//	Allows to get the ten most visited pages of a log file
	//	The exclude parameter allows to exclude all javascript, image and css
	//	files
	//	The time parameter allows to restrict the time lapse to hour [t,t+] with
	//	t in [0,23]. If t isn't in the range, no time restriction is set.
	// Contrat:
	//	No contract

	void GenerateGraphViz ( ofstream &output, bool exclude, int time );
	// Mode d'emploi:
	//	Allows to generate a graphviz file that represent the travels inside the
	//	server pages.
	//	The fileName indicates the name of the file under which the graphviz file
	//	is to be stored.
	//	The exclude parameter allows to exclude all javascript, image and css
	//	files
	//	The time parameter allows to restrict the time lapse to hour [t,t+] with
	//	t in [0,23]. If t isn't in the range, no time restriction is set.
	//----------------------------------------------------Surcharge d'opérateurs
	//-----------------------------------------------Constructeurs - Destructeur
	Analyser ( ifstream &input);
	// Mode d'emploi:
	//	Allows to create a new analyser upon a default input file
	// Contrat:
	//	The log file should be present and in a readable state. It should also be
	//	a properly formated apache log file

	virtual ~Analyser ( );
	// Destructor:
	//	No contract.
	//---------------------------------------------------------------------PRIVE
	private :
	//-----------------------------------------------------------Méthodes privées
	void displayAllLogs ( );
	// Mode d'emploi:
	//	Goes through the list of logs and displays them all on the standard output.
	// Contract:
	//	No contract

	bool isToBeExcluded(Log aLog);
	// Mode d'emploi:
	//	Returns true if the extension of the destination URL is part of the list of
	//	the documents to be excluded. Returns false otherwise.
	// Contract:
	//	No contract

	bool startsWith(const string& s1, const string& s2);
	// Mode d'emploi:
	//	Returns true if s1 starts with s2, wrong otherwise.
	// Contract:
	//	No contract

	static bool endsWith (string const &fullString, string const &ending);
	// Mode d'emploi:
	//	Returns true if the full string ends with the ending, wrong otherwise.
	// Contract:
	//	No contract

	//----------------------------------------------------------Attributs privées
	list<Log> logList;
	/*
	 * The list containing all the logs of the file the Analyser was created with.
	 */
};

//-------------------------------------Autres définitions dépendantes de Analyser

#endif // ! defined (XXX_H)
