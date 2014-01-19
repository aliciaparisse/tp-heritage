//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Modele.cpp
//-----------------------------------

#include "Modele.h"

Modele::Modele() : dernierId(0)
{
}

Modele::~Modele()
{
}

void Modele::ajoutForme(formeEtId* unPtForme)
{
	formes.push_back(unPtForme);
	++dernierId;
}

void Modele::supprForme(int idFormeSuppr)
{
	formes.erase(formes.begin()+idFormeSuppr);
	--dernierId;
}

void Modele::deplacerForme(int idFormeDep, int unDx, int unDy)
{
	((formes.at(idFormeDep))->laForme)->deplacer(unDx,unDy);
}

int Modele::getDernierId()
{
	return dernierId;
}
