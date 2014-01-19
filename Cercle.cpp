//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Cercle.cpp
//-----------------------------------


#include "Point.h"
#include "Cercle.h"


Cercle::Cercle (int& unX, int& unY, int& unRayon)
	: rayon (unRayon),	centre(unX, unY)
{
}

Cercle::~Cercle()
{
}

void Cercle::deplacer(int& dx, int& dy)
{
	this->centre.deplacer(dx, dy);
}
