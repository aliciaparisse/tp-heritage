//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// delForme.h
//-----------------------------------

#ifndef DELFORME_H
#define DELFORME_H
#include "Command.h"
using namespace std; 

class delForme : public Command 
{
	protected:
	 	Modele modeleUtilise;	
		formeEtId formeTraitee;

	public: 
		delForme(formeEtId uneForme, Modele unModele);
		~delForme(); 
		void Do();
		void Undo(); 

};


#endif
