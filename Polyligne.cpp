//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Polyligne.cpp
//-----------------------------------

#include "Polyligne.h"

Polyligne::Polyligne(list<Point> uneListe)
{
	//Je sais pas du tout si ça marche, c'est juste pour dire qu'il faudrait le déclarer comme ça
	this->points = new list(uneListe);
	this->nouvelleForme();
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
