//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// LoadFile.h
//-----------------------------------

#ifndef LOADFILE_H
#define LOADFILE_H
#include "Command.h"
#include "Executeur.h"
#include "CommandReader.h"
#include "Controleur.h"

#include <iostream>
#include <fstream>

using namespace std; 

class LoadFile : public Command 
{
	protected:
	 	Modele modeleUtilise;	
		formeEtId formeTraitee;

	public: 
		LoadFile(formeEtId &uneForme, Modele &unModele);
		~LoadFile(); 
		void Do();
		void Undo(); 
};


#endif
