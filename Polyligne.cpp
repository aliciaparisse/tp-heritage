//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Polyligne.cpp
//-----------------------------------

#include "Polyligne.h"

Polyligne::Polyligne(list<Point> uneListe)
	: points(uneListe)
{
}

Polyligne:: ~Polyligne()
{
}

void Polyligne::deplacer(int dx, int dy)
{
	for (list<Point>::const_iterator it = points.begin(); it != point.end(); it++)
	{
		it.deplacer(dx, dy);
	}
}

void ajouter(Ligne nouvelleLigne)
{
	this->points.push_back(nouvelleLigne);
}	
