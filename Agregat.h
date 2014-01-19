//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Agregat.h
//-----------------------------------

#ifndef AGREGAT_H
#define AGREGAT_H
#include "Forme.h"
#include <list>

class Agregat : public Forme
{

	public:
		Agregat(list <Forme*> uneListe);
		virtual ~Agregat();
		void deplacer(int& dx, int& dy);

	private:
		list <Forme*> formesA;
};




#endif
