//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Cercle.h
//-----------------------------------

#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include "Point.h"
#include "Forme.h"
using namespace std;

class Cercle: public Forme
{

	public:
		Cercle(string& nom, int& x, int& y,  int& rayon);
		virtual	~Cercle();
		void deplacer(int& dx, int& dy);
		string afficherCoord ();

	private:
		int rayon;
		Point centre;
		string nomCercle;

};

#endif


