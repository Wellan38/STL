//--------------------- Réalistation de la classe Launcher.cpp (Launcher.cpp.h) ------------------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
//-------------------------------------------------------------Include personnel
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------PUBLIC
//------------------------------------------------------------Méthodes publiques
int main ( int argc, char * argv[] )
{
#ifdef TEST
	cout << argc << " arguments were passed as parameter" << endl;

	int i;
	for ( i=0; i< argc; i++ )
	{	cout << argv[i] << endl;
	}
#endif
	if ( argc == 1)
	{
		cout << "This program requires at least one input argument. " << endl;
		cout << "Try option -h for help." << endl;
	}


	return 0;
}
//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur

//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
