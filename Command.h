//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Command.h
//-----------------------------------

#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <list>
#include <map>
#include "Forme.h"

using namespace std;

class Command
{
	protected:
	 	Modele modeleUtilise;	
		Forme formeTraitee;
	public: 
		Command(){}
		~Command(){}
		void Do()=0;
		void Undo()=0;
};

#endif
