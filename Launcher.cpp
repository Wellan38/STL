//--------------------- Réalistation de la classe Launcher.cpp (Launcher.cpp.h) ------------------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
#include <string>
//-------------------------------------------------------------Include personnel
//------------------------------------------------------------------- Constantes
const string HELP = string("-h");
const string TIME = string("-t");
const string EXCLUDE = string("-e");
//------------------------------------------------------------------------PUBLIC
//------------------------------------------------------------Méthodes publiques
extern void ShowManual ( );

int main ( int argc, char * argv[] )
// Algorithm:
//	Loops to get every possible option and parameter. then launches the
//	corresponding methods.
{
#ifdef TEST
	cout << argc << " arguments ont été passés en paramètre." << endl;

	int i;
	for ( i=0; i< argc; i++ )
	{	cout << argv[i] << endl;
	}
#endif

	//No argument provided, program cannot run
	if ( argc == 1)
	{
		cout << "This program requires at least one input argument. " << endl;
		cout << "Try option -h for help." << endl;
	}
	else
	{	//We go through all the arguments to detect all the options
		int counter = 1;

		//default configuration
		bool exclude = false;		//value of option -e
		int time = -1;				//value of option -t, -1 meaning no filter

		while (counter < argc)
		{
			if ( !HELP.compare(argv[counter]) )
			{
#ifdef TEST
				cout << "Parameter -h detected, showing manual." << endl;
#endif
				ShowManual();
			}
			else if ( !EXCLUDE.compare(argv[counter]) )
			{
#ifdef TEST
				cout << "Parameter -e detected, fancy files will be excluded from the computations." << endl;
#endif
				exclude = true;
			}
			else if ( !TIME.compare(argv[counter]) )
			{
#ifdef TEST
				cout << "Parameter -t detected, trying to read an integer as next argument." << endl;
#endif
			}

			counter ++;
		}
	}
	return 0;
}

void ShowManual ( )
{
	cout << "---- TP_STL manual ----" << endl;
	cout << "Apache log file analyser" << endl << endl;

	cout << "USAGE: ./TP_STL [OPTIONS]... FILE" << endl << endl;

	cout << "OPTIONS:" << endl << endl;
	cout << "   -e        :exclude the javascript, css an image files from the";
	cout << " analysis," << endl;
	cout << "                focusing the computations on the other files.";
	cout << endl << endl;

	cout << "   -t <hour> :focus the computations on the logs that took place in";
	cout << " the" << endl ;
	cout << "                [hour, hour+1] interval of time. " << endl;
	cout << "                The hour should be an integer in the range [0,23]";
	cout << endl << endl;

	cout << "   -g <file> :generate a graphviz file describing the travels from";
	cout << endl;
	cout << "                a page to another. file is the name of the file in ";
	cout << endl;
	cout << "                which the graph should be stored" << endl;
	cout << "                If it exists already, the file will be overwritten.";
	cout << endl << endl;

	cout << "FILE:" << endl << endl;
	cout << "   The file to analyse should be the last one to be given as parameter.";
	cout << endl << "   It has to be an APACHE log format file." << endl;
}
//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur

//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
