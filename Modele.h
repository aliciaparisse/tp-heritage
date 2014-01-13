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

using namespace std; 

struct formeEtId
{
	int id;
	Forme laForme;
}

class Modele
{
	private:
		vector <formeEtId> formes;
		map<int,string> noms;
		int dernierId;
		
	public: 
		Modele(); 
		virtual ~Modele();
		ajouterForme(list <string> args); 
		supprimerForme(Forme formeObsolete);


};

#endif
