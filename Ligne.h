//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// Ligne.h
//-----------------------------------

#ifndef LIGNE_H
#define LIGNE_H

#include <iostream>
#include "Forme.h"
#include "Point.h"

using namespace std;

class Ligne : public Forme
{

	private:
		Point point1;
		Point point2;
		string nomLigne;

	public:
		Ligne(string& nom,int& X1, int& X2, int& Y1, int& Y2);
		virtual ~Ligne();
		void deplacer(int& dx, int& dy);


};
#endif
