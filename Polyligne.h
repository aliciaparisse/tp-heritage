//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// Polyligne.h
//-----------------------------------

#ifndef POLYLIGNE_H
#define POLYLIGNE_H

#include "Forme.h"
#include "Point.h"
#include <list>
#include <iostream>

using namespace std;

class Polyligne : public Forme
{
	private:
		list<Point*> points;

	public:
		Polyligne(list<Point*> uneListe);
		virtual ~Polyligne();
		void deplacer(int& dx, int& dy);


};



#endif
