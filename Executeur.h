<<<<<<< HEAD
//----------------------------------
// TP C++ 3 : TP HÃ©ritage et EntrÃ©es/Sorties
// RÃ©alisÃ© par : B3222 - Jean MARCHAL et Alicia PARISSE
=======
//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
>>>>>>> 2b17f5504d8c40b08321c5f7da483b4a881a6fb1
// Executeur.h
//-----------------------------------

#ifndef EXECUTEUR_H
#define EXECUTEUR_H

#include <iostream>
#include "Controleur.h"
#include  <list>

using namespace std;

class Executeur
{
	private:
		Controleur leControleur;
		map<int,string> noms;

	public:
		Executeur(Controleur unControleur);
		virtual ~Executeur();
		void executer(list<string> args);
		bool nomExiste(string leNom);
};

#endif
