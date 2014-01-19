//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Agregat.cpp
//-----------------------------------


#include "Agregat.h"

Agregat::Agregat (list <Forme*> uneListe)
	: formesA(uneListe)
{
}

Agregat::~Agregat()
{
}

void Agregat::deplacer(int& dx, int& dy)
{
	for (list<Forme*>::iterator it = formesA.begin(); it != formesA.end() ; ++it)
	{
		(*it)->deplacer(dx, dy);
	}


}

