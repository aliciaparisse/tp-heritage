//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Agregat.cpp
//-----------------------------------

#include "ajoutForme.h"


ajoutForme::ajoutForme(string& unNom, infoFormes& uneForme, Modele* unModele)
	: nom(unNom), formeTraitee(uneForme), modeleUtilise(unModele)
{
}

ajoutForme::~ajoutForme()
{
}

void ajoutForme::Do()
{
	modeleUtilise->ajoutForme(nom,formeTraitee);
}

void ajoutForme::Undo()
{
	modeleUtilise->supprForme(nom);
}


