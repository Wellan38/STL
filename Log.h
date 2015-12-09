/*************************************************************************
                           Log  -  description
                             -------------------
    début                : 30 nov. 2015
    copyright            : (C) 2015 par abento
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ------
#if ! defined ( LOG_H )
#define LOG_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;

#include <string>
#include <fstream>
#include <sstream>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Log>
//
//
//------------------------------------------------------------------------ 

class Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    friend istream & operator >> ( istream &is, Log &aLog );
    // Mode d'emploi :
    //		Allows to store in a new log instance a log from a file.
    //
    // Contrat :
    //		The log file should be well formated.


    friend ostream & operator << ( ostream &os, Log &aLog );
        // Mode d'emploi :
        //		Displays all the attributes of the Log, line by line.
        //
        // Contrat :
        //		aLog should be at least initialized properly.


//-------------------------------------------- Constructeurs - destructeur
    Log ( const Log & aLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Log ( );
    // Mode d'emploi :
    //		Default constructor, initializes all the attributes to default values.
    //
    // Contrat :
    //		No contract.

    virtual ~Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

    string IpAddress;
    string userLogName;
    string authenticatedUser;

    int day;
    string month;
    int year;
    int hour; // GMT time
    int minute;
    int second;
    int diffGreenwich; // Difference between the GMT time and the local time

    string actionType;
    string urlDest; // Destination URL
    string urlOrigin;

    int statusCode;
    int dataSize;

    string navigatorId;

//---------------------------------------------------------- Classes amies

    friend class Analyser;

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Log>

#endif // LOG_H
