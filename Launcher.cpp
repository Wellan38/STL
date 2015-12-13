//--------------------- Réalistation de la classe Launcher.cpp (Launcher.cpp.h) ------------------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
//-------------------------------------------------------------Include personnel
#include "Analyser.h"
//------------------------------------------------------------------- Constantes
const string TIME = string("-t");
const string EXCLUDE = string("-e");
const string GRAPH = string("-g");

const string CONFIG_FILE_NAME = string("TP_STL.cfg");
//------------------------------------------------------------------------PUBLIC
//------------------------------------------------------------Méthodes publiques
void ShowManual ( );

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

	//default configuration
	bool exclude = false;		//value of option EXCLUDE
	bool graph = false;			//value of option GRAPH
	int time = -1;				//value of option TIME, -1 meaning no filter
	char * outputName = {'\0'};	//name for the graphviz file to generate.

	if ( argc == 1)
	{
#ifdef TEST
		cout << "No argument provided, launching the manual." << endl;
#endif
		ShowManual();
	}
	else
	{	//We go through all the arguments to detect all the options
		int counter = 1;

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
						return 1;
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
					//Get the file name and try to open the file -> stream?
					outputName = argv[counter];
					graph = true;
				}
				else
				{
					cerr << "Error: a file for graphviz output was not provided" << endl;
					return 1;
				}
			}
			counter ++;
		}	//End of while loop to collect arguments.

		ifstream logFile(argv[argc-1]);

		if (logFile)
		{
#ifdef TEST
			cout << "Log file <" << argv[argc-1] << "> opening succeeded" << endl;
#else
			//trying to load the configuration file.
			ifstream config(CONFIG_FILE_NAME);
			string baseUrl = "";
			if (config)
			{
				config >> baseUrl;
			}

			Analyser analyser(logFile, baseUrl);
			if ( graph )
			{
				ofstream graphOutputStream;
				graphOutputStream.open(outputName, ios::out);
				analyser.GenerateGraphViz(graphOutputStream, exclude, time);
				graphOutputStream.close();
				cout << "Dot-file " << outputName << " generated." << endl;
			}
			analyser.DisplayTenMostVisited(exclude, time);

#endif

		}
		else
		{
			cerr << "Error: the file " << argv[argc-1] << " could not be opened" << endl;
		}
	}
	return 0;
}

void ShowManual ( )
//Algorithm
{
	cout << "---- TP_STL manual ----" << endl;
	cout << "Apache log file analyser" << endl;
	cout << "This program allows you to display the top ten most visited pages"<< endl;
	cout << "of your apache server. The computation is done by providing your "<< endl;
	cout << "apache log file." << endl;
	cout << "Several other options are listed below." << endl << endl;

	cout << "USAGE:     ./TP_STL [OPTIONS]... FILE" << endl << endl;

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
