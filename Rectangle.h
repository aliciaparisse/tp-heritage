//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Rectangle.h
//-----------------------------------

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Point.h"
#include "Forme.h"
using namespace std;

class Rectangle : public Forme
{

	public:
		Rectangle(int& x1, int& y1, int& x2, int& y2);
		virtual	~Rectangle();
		void deplacer(int& dx, int& dy);

	private:
		Point point1;
		Point point2;
        Point point3;
		Point point4;

};

#endif

