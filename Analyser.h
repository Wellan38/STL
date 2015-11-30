//--------------------- Inteface de la classe Analyser (Analyser.h) ----------------------
#if ! defined (Analyser_H)
#define Analyser_H


//--------------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

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

	void GenerateGraphViz ( char * fileName, bool exclude, int time);
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
	Analyser ( char * inputLogFileName);
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
	//----------------------------------------------------------Attributs privées
	list<Log> logList;
	/*
	 * The list containing all the logs of the file the Analyser was created with.
	 */

};

//-------------------------------------Autres définitions dépendantes de Analyser

#endif // ! defined (XXX_H)
