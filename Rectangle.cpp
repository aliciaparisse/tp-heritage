//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Rectangle.cpp
//-----------------------------------

#include "Rectangle.h"

Rectangle::Rectangle(int unX1, int unY1, int unX2, int unY2)
{
	// La non plus je suis pas sure de la meilleure manière de faire ça.
	// Du coup, j'essaie comme ça, on verra si ça marche.
	point1 = new Point(unX1, unY1);
	point2 = new Point(unX1, unY2);
	point3 = new Point(unX2, unY2);
	point4 = new Point(unX2, unY1);
	//Essai d'incrémentation de nouvelle Forme
	this->nouvelleForme();
}

Rectangle::~Rectangle()
{
}

void Rectangle::deplacer(int dx, int dy)
{
	this->point1.deplacer(dx,dy);
	this->point2.deplacer(dx,dy);
	this->point3.deplacer(dx,dy);
	this->point4.deplacer(dx,dy); 
}
