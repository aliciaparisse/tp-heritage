//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Point.cpp
//-----------------------------------


#include "Point.h"


Point:: Point(int unX, int unY)
	: x(unX), y(unY)
{
}


Point::~Point()
{
}


void Point::deplacer(int dx, int dy)
{
	this->x +=dx;
	this->y +=dy;
}


