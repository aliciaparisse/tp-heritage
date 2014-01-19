//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
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
