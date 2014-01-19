//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// Command.h
//-----------------------------------

#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <list>
#include <map>
#include "Modele.h"
#include "Forme.h"

using namespace std;

class Command
{
	protected:
	 	Modele modeleUtilise;
		formeEtId formeTraitee;
	public:
		Command(){}
		~Command(){}
		void virtual Do()=0;
		void virtual Undo()=0;
};

#endif
