//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
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
#include <map>
#include <iostream>

using namespace std;

struct infoFormes
{
	Forme* laForme;
	string codeForme;
};

struct infoUndo
{
	string nomFormeUndo;
	string actionUndo;
};
typedef infoUndo infoUndo;

class Modele
{
	private:
		map <string,infoFormes> formes;
		int nbFormes;
		infoUndo infosUndo;

	public:
		Modele();
		virtual ~Modele();
		void ajoutForme(string& nom, infoFormes& formes);
		void supprForme(string& nomFormeSuppr);
		void deplacerForme(string& nomFormeDep, int& unDx, int& unDy);
		string afficherElements (string& nom);
		int getNbFormes();
		infoFormes getInfoFormes(string& nom);
		void modifVectExecuteur(string& nom, int& expediteur);
		infoUndo getInfoUndo();
};

#endif
