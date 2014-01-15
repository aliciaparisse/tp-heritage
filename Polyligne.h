//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Polyligne.h
//-----------------------------------

#ifndef POLYLIGNE_H
#define POLYLIGNE_H

#include "Forme.h"
#include "Point.h"
#include <list>
#include <iostream>

using namespace std;

class Polyligne
{
	private:
		list <Point> points;

	public: 
		Polyligne(list<Point> uneListe);
		virtual ~Polyligne();
		void deplacer(int dx, int dy); 


};



#endif
