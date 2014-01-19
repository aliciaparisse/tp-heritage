//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Modele.h
//-----------------------------------

#ifndef MODELE_H
#define MODELE_H

#include "Forme.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Ligne.h"
#include "Polyligne.h"
#include "Agregat.h"
#include "Point.h"
#include <list>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct formeEtId
{
	int id;
	Forme* laForme;
};

class Modele
{
	private:
		vector <formeEtId*> formes;
		int dernierId;

	public:
		Modele();
		virtual ~Modele();
		void ajoutForme(formeEtId* unPtForme);
		void supprForme(int idFormeSuppr);
		void deplacerForme(int idFormeDep, int unDx, int unDy);
		int getDernierId();
};

#endif
