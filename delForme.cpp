//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// delForme.cpp
//-----------------------------------
#include "delForme.h"


delForme::delForme(Forme uneForme, Modele unModele)
	: formeTraitee(uneForme), modeleUtilise(unModele)
{
}

delForme::~delForme() 
{
}

void delForme::Do()
{
	//est-ce que ça marche en accèdant à l'id de la forme ?
	formes.erase(formeTraitee->id);
}
void delForme::Undo() 
{	
	//Doit-on vérifier que le pointeur existe ? 
	Forme* pointeur = &formeTraitee;
	modeleUtilise.formes.push_back(pointeur);
}


