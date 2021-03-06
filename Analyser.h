//--------------------- Inteface de la classe Analyser (Analyser.h) ----------------------
#if ! defined (Analyser_H)
#define Analyser_H


//--------------------------------------------------------- Interfaces utilisées
#include "Log.h"
#include <list>
#include <vector>
//------------------------------------------------------------------- Constantes

const string BASE_URL_DEFAULT = "http://intranet-if.insa-lyon.fr";

const string CSS = ".css";		//extensions of css files
const string PNG = ".png";		//extensions of image files
const string JS = ".js";		//extensions of javascript files
const string JPG = ".jpg";		//extensions of image file
const string GIF = ".gif";		//extensions of animated image file
const string ICO = ".ico";		//extensions of image file
const vector<string> EXTENSIONS = {CSS, PNG, JS, JPG, GIF, ICO}; // extensions to be excluded

const int VALID_CODE = 200;

const int NB_TOP_PAGES_TO_DISPLAY = 10;
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
	Analyser ( ifstream &input, string baseUrl = BASE_URL_DEFAULT);
	// Mode d'emploi:
	//	Allows to create a new analyser upon a default input file
	// Contrat:
	//	The log file should be present and in a readable state. It should also be
	//	a properly formated apache log file

	virtual ~Analyser ( );
	// Destructor:
	//	No contract.

	friend ostream & operator << (ostream &os, const Analyser &an);
	// Mode d'emploi:
		//	Displays all the logs one by one.
		// Contrat:
		//	No contract.

	//---------------------------------------------------------------------PRIVE
	private :
	//-----------------------------------------------------------Méthodes privées
	void displayAllLogs ( );
	// Mode d'emploi:
	//	Goes through the list of logs and displays them all on the standard output.
	// Contract:
	//	No contract

	bool passesFilters(Log &aLog, int time, bool exclude);
	// Mode d'emploi:
	//	Indicates if a log passes the filters of the file extension, the valid code
	//	and the time limit. This method's role is essentially to make the writing
	//	more compact as the different filters always apply and are used in every
	//	computation method.
	// Contract;
	//	No contract.

	bool isToBeExcluded(Log & aLog);
	// Mode d'emploi:
	//	Returns true if the extension of the destination URL is part of the list of
	//	the documents to be excluded. Returns false otherwise.
	// Contract:
	//	No contract

	bool respectsTime(Log &aLog, int t);
	// Mode d'emploi:
	//	Returns true if the time of the log is between t and t+1.
	//	Returns wrong otherwise.
	// Contract:
	//	t must be between 0 and 23.

	bool operationSuccessful(Log &aLog);
	// Mode d'emploi:
	//	Returns true if the code for the request is that of the const VALID_CODE
	//	False otherwise?
	// Contract:
	//	No contract.

	bool startsWith(const string& s1, const string& s2);
	// Mode d'emploi:
	//	Returns true if s1 starts with s2, wrong otherwise.
	// Contract:
	//	No contract

	bool endsWith (const string &fullString, const string &ending);
	// Mode d'emploi:
	//	Returns true if the full string ends with the ending, wrong otherwise.
	// Contract:
	//	No contract

	//-----------------------------------------------------------Attributs privés
	/*
	 * The list containing all the logs of the file the Analyser was created with.
	*/
	list<Log> logList;
	const string BASE_URL;

	//--------------------------------------------------------------Classes amies
};

//-------------------------------------Autres définitions dépendantes de Analyser

struct StringIntPair
{
	string aString;
	int nb;

	StringIntPair(string aString, int nb) : aString(aString), nb(nb) {}

	friend bool operator < (const StringIntPair &p1, const StringIntPair &p2)
	{
		if (p1.nb < p2.nb)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend bool operator == (const StringIntPair &p1, const StringIntPair &p2)
	{
		return p1.aString == p2.aString;
	}

	friend ostream& operator << (ostream& os, const StringIntPair& p)
	{
		return os << p.aString << ": " << p.nb;
	}

	inline StringIntPair& operator = (const StringIntPair &p)
	{
		aString = p.aString;
		nb = p.nb;

		return *this;
	}
};

struct StringPair
{
	string s1;
	string s2;

	StringPair( const string string1, const string string2 ) : s1(string1), s2(string2) {}

	friend bool operator < (const StringPair & p1, const StringPair & p2)
	{
		if (p1.s1 < p2.s1)
		{
			return true;
		}
		else if (p1.s1 == p2.s2)
		{
			return p1.s2 < p2.s2;
		}
		else
		{
			return false;
		}
	}

	friend bool operator == (const StringPair &p1, const StringPair &p2)
	{
		bool res = p1.s1 == p2.s1 && p1.s2 == p2.s2;
		return res;
	}
};

#endif // ! defined (XXX_H)
