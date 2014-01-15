//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Ligne.h
//-----------------------------------

#ifndef LIGNE_H
#define LIGNE_H

#include <iostream>
#include "Point.h"

using namespace std;

class Ligne 
{

	private: 
		Point point1;
		Point point2;

	public:
		Ligne(int X1, int X2, int Y1, int Y2);
		virtual ~Ligne();
		void deplacer(int dx, int dy);
		

};
#endif
