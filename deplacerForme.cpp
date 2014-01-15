//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// deplacerForme.cpp
//-----------------------------------

#include "deplacerForme.h"

deplacerForme::deplacerForme(Forme uneForme, Modele unModele, int unDepX, int unDepY)
	: formeTraitee(uneForme), modeleUtilise(unModele), depX(unDepX), depY(unDepY)
{
}

deplacerForme::deplacerForme() 
{
}

void deplacerForme::Do()
{
	for(vector<formesEtId>:: const_iterator it=formes.begin(); it!=formes.end(); ++it)
	{
		//Pointe sur la forme ou sur le pointeur de Forme ? 
		it->laForme.deplacer(depX,depY);
	}
}

void deplacerForme::Undo()
{
	for(vector<formesEtId>:: const_iterator it=formes.begin(); it!=formes.end(); ++it)
	{
		//Pointe sur la forme ou sur le pointeur de Forme ? 
		it->laForme.deplacer(-depX,-depY);
	}
}
