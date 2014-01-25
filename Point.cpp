//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Point.cpp
//-----------------------------------


#include "Point.h"
#include <sstream>
#include <iostream>
using namespace std;


Point::Point(int& unX, int& unY)
	: x(unX), y(unY)
{
}

Point::~Point()
{
}

void Point::deplacer(int& dx, int& dy)
{
	cout << "appel Point" << endl;
	this->x +=dx;
	this->y +=dy;
}

string Point::getCoord ()
{
    ostringstream oss1;
    oss1 << x;
    string X = oss1.str();
    ostringstream oss2;
    oss2 << y;
    string Y = oss2.str();
    string coord = X + " " + Y;
    return coord;
}


