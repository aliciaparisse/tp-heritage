//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// Polyligne.cpp
//-----------------------------------

#include "Polyligne.h"

Polyligne::Polyligne(list<Point*> uneListe)
	: points(uneListe)
{
}

Polyligne::~Polyligne()
{
}

void Polyligne::deplacer(int& dx, int& dy)
{
	for (list<Point*>::iterator it = points.begin(); it != points.end(); it++)
	{
		Point* point = *it;
		point->deplacer(dx,dy);
	}
}


