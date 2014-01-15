//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Agregat.cpp
//-----------------------------------

#include "ajoutForme.h"


ajoutForme::ajoutForme(Forme uneForme, Modele unModele)
	: formeTraitee(uneForme), modeleUtilise(unModele)
{
}

ajoutForme::~ajoutForme() 
{
}

void ajoutForme::Do()
{
	//Doit-on vérifier que le pointeur existe ? 
	Forme* pointeur = &formeTraitee;
	modeleUtilise.formes.push_back(pointeur);
}
void ajoutForme::Undo() 
{
	formes.erase(formeTraitee->id);
}


