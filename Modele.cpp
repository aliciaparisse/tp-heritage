//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// Modele.cpp
//-----------------------------------

#include "Modele.h"

int Modele::dernierId = 0;

Modele::Modele()
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
