//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// delForme.h
//-----------------------------------

#ifndef DELFORME_H
#define DELFORME_H

using namespace std; 

class delForme : public Command 
{
	public: 
		delForme(Forme uneForme, Modele unModele);
		~delForme(); 
		void Do();
		void Undo(); 

};


#endif
