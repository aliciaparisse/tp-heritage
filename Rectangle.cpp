//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// Rectangle.cpp
//-----------------------------------

#include "Rectangle.h"

Rectangle::Rectangle(string& nom, int& unX1, int& unY1, int& unX2, int& unY2)
	: point1(unX1, unY1), point2(unX1, unY2), point3(unX2, unY2), point4(unX2, unY1), nomRec(nom)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::deplacer(int& dx, int& dy)
{
	this->point1.deplacer(dx,dy);
	this->point2.deplacer(dx,dy);
	this->point3.deplacer(dx,dy);
	this->point4.deplacer(dx,dy);
}
