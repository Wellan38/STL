//--------------------- Réalistation de la classe Launcher.cpp (Launcher.cpp.h) ------------------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
#include <string>
#include <exception>
#include <sstream>
//-------------------------------------------------------------Include personnel
//------------------------------------------------------------------- Constantes
const string TIME = string("-t");
const string EXCLUDE = string("-e");
const string GRAPH = string("-g");
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

	//No argument provided, showing the manual by default
	if ( argc == 1)
	{
		ShowManual();
	}
	else
	{	//We go through all the arguments to detect all the options
		int counter = 1;

		//default configuration
		bool exclude = false;		//value of option EXCLUDE
		bool graph = false;			//value of option GRAPH
		int time = -1;				//value of option TIME, -1 meaning no filter

		while (counter < argc -1 )	//while loop but keeping the the last argument as it is supposed to be the file to analyse.
		{
			if ( EXCLUDE.compare(argv[counter]) == 0 )
			{
#ifdef TEST
	cout << "Parameter " << EXCLUDE << " detected." << endl;
#endif
				exclude = true;
			}
			else if ( TIME.compare(argv[counter]) == 0 )
			{
#ifdef TEST
	cout << "Parameter "<< TIME <<" detected." << endl;
#endif
				exclude = true;
				counter ++;
				if ( counter < argc - 1 )
				{
					stringstream ss( argv[counter] );
					ss >> time;
#ifdef TEST
		cout << "The time constraint has a value of:" << time << endl;
#endif
					if ( time > 23 || time <0)
					{
						cerr << "Error: value not valid for " << TIME << " option:" << time;
						cerr << endl << "Value should be in the [0,23] interval" << endl;
					}
				}
				else
				{
					cerr << "Error: expecting a number after option " << TIME << endl;
					return 1;
				}
			}
			else if ( GRAPH.compare(argv[counter]) == 0)
			{
#ifdef TEST
	cout << "Parameter " << GRAPH << " detected." << endl;
#endif
				counter ++;
				if ( counter < argc - 1 )
				{
					//TODO get the file name / try to open the file and send it to launcher class.
				}
				else
				{
					cerr << "Error: a file for graphviz output was not provided" << endl;
					return 1;
				}
			}
			counter ++;
		}	//End of while loop to collect arguments.

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
