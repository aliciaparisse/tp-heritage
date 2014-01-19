//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// ajoutForme.h
//-----------------------------------

#ifndef AJOUTFORME_H
#define AJOUTFORME_H
#include "Command.h"

using namespace std;

class ajoutForme : public Command
{
	protected:
	 	Modele modeleUtilise;
		formeEtId formeTraitee;

	public:
		ajoutForme(formeEtId &uneForme, Modele &unModele);
		~ajoutForme();
		void Do();
		void Undo();
};


#endif
