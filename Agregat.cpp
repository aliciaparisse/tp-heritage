//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Agregat.cpp
//-----------------------------------


#include "Agregat.h"

Agregat::Agregat (list <*Forme> uneListe)
	: formesA(uneListe)
{	 
}

Agregat::~Agregat()
{
}

Agregat::deplacer(int dx, int dy)
{
	for (list<Forme*>::const_iterator it = this->formesA.begin(); it = this->formesA.end() ; ++it)
	{
		*it->deplacer(dx, dy);
	}


}

