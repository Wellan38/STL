/*************************************************************************
                           Log  -  description
                             -------------------
    début                : 30 nov. 2015
    copyright            : (C) 2015 par abento
*************************************************************************/

//---------- Réalisation de la classe <Log> (fichier Log.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Log.h"

//------------------------------------------------------------- Constantes

const char SEP_SPACE = ' ';
const char SEP_OPEN = '[';
const char SEP_CLOSE = ']';
const char SEP_COLON = ':';
const char SEP_QUOTE = '"';
const char SEP_SLASH = '/';

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

istream & Log::operator >> ( istream &is, Log &aLog )
// Algorithme :
//
{
	string temp;
	stringstream ss;

	getline(is, aLog.IpAddress, SEP_SPACE);
	getline(is, aLog.userLogName, SEP_SPACE);
	getline(is, aLog.authenticatedUser, SEP_SPACE);
	is.ignore();
	getline(is, temp, SEP_SLASH);

	ss.str(temp);
	ss >> aLog.day;
	ss.clear();

	getline(is, aLog.month, SEP_SLASH);
	getline(is, temp, SEP_COLON);

	ss.str(temp);
	ss >> aLog.year;
	ss.clear();

	getline(is, temp, SEP_COLON);

	ss.str(temp);
	ss >> aLog.hour;
	ss.clear();

	getline(is, temp, SEP_COLON);

	ss.str(temp);
	ss >> aLog.minute;
	ss.clear();

	getline(is, temp, SEP_SPACE);

	ss.str(temp);
	ss >> aLog.second;
	ss.clear();

	getline(is, temp, SEP_CLOSE);

	int coeff;
	if (temp[0] == '+')
	{
		coeff = 1;
	}
	else
	{
		coeff = -1;
	}

	temp.erase(0,1);

	ss.str(temp);
	ss >> aLog.diffGreenwich;
	ss.clear();

	is.ignore(2);

	getline(is, aLog.actionType, SEP_SPACE);

	return is;
} //----- Fin de operator >>

//----------------------------------------------------- Méthodes publiques
// type Log::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Log::Log ( const Log & aLog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Log>" << endl;
#endif
} //----- Fin de Log (constructeur de copie)


Log::Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Default constructor of <Log>" << endl;
#endif

    	IpAddress = "";
        userLogName = "";
        authenticatedUser = "";

        day = 0;
        month = "";
        year = 0;
        hour = 0;
        minute = 0;
        second = 0;
        diffGreenwich = 0;

        actionType = "";
        urlDest = "";
        urlOrigin = "";

        statusCode = 0;
        dataSize = 0;

        navigatorId = "";
} //----- Fin de Log


Log::~Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Log>" << endl;
#endif
} //----- Fin de ~Log


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
