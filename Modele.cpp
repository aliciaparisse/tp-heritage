//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Modele.cpp
//-----------------------------------

#include "Modele.h"

Modele::Modele()
{
}

Modele::~Modele()
{
}

void Modele::ajouterForme(list <string> args)
{
	list<string>:: const_iterator it = args.begin();
	if (strcmp(*it, "C") == 0)
	{
		nom=cerclejoli
		x=4
		y=6
		r=12
		Cercle nom=new Cercle(x,y,r);
	}
	


	
}

void Modele::supprimerForme(Forme obsoleteForme)
{
	formes.remove(obsoleteForme);
}
