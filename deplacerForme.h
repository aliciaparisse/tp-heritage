//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// deplacerForme.h
//-----------------------------------

#ifndef DEPLACERFORME_H
#define DEPLACERFORME_H

using namespace std; 

class deplacerForme : public Command 
{
	private:
		int depX;
		int depY;
	public: 
		deplacerForme(Forme uneForme, Modele unModele, int unDepX, int unDepY);
		~deplacerForme(); 
		void Do();
		void Undo(); 

};


#endif
