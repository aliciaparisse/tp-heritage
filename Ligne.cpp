//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Ligne.cpp
//-----------------------------------
#include "Ligne.h"

Ligne::Ligne(int& unX1, int& unY1, int& unX2, int& unY2)
	: point1(unX1, unY1), point2(unX2, unY2)
{
}

Ligne::~Ligne()
{
}

void Ligne::deplacer(int& dx, int& dy)
{
	this->point1.deplacer(dx, dy);
	this->point2.deplacer(dx, dy);

}
