//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Command.h
//-----------------------------------

#ifndef COMMAND_H
#define COMMAND_H

#include <list>
#include "Modele.h"
#include "Forme.h"

using namespace std;

class Command
{
	protected:
	 	Modele modeleUtilise;
	public:
		Command(){}
		~Command(){}
		void virtual Do()=0;
		void virtual Undo()=0;
};

#endif
