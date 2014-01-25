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
	 	string nom;
	 	infoFormes formeTraitee;
	 	Modele* modeleUtilise;

	public:
		ajoutForme(string& unNom, infoFormes& uneForme, Modele* unModele);
		~ajoutForme();
		void Do();
		void Undo();
};


#endif
