//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// Point.cpp
//-----------------------------------


#include "Point.h"


Point::Point(int& unX, int& unY)
	: x(unX), y(unY)
{
}

Point::~Point()
{
}

void Point::deplacer(int& dx, int& dy)
{
	this->x +=dx;
	this->y +=dy;
}


