//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Executeur.h
//-----------------------------------

#ifndef EXECUTEUR_H
#define EXECUTEUR_H

#include <iostream>
#include "Controleur.h"
#include "CommandReader.h"
#include  <list>

using namespace std;

class Executeur
{
	private:
		Controleur leControleur;
		commandReader leLecteur;
	
	public:	
		Executeur(Controleur unControleur, commandReader unLecteur);
		virtual ~Executeur();
		void executer(list<string> args);
};

#endif
