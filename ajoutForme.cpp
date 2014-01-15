//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Agregat.cpp
//-----------------------------------

#include "ajoutForme.h"


ajoutForme::ajoutForme(formeEtId uneForme, Modele unModele)
	: formeTraitee(uneForme), modeleUtilise(unModele)
{
}

ajoutForme::~ajoutForme() 
{
}

void ajoutForme::Do()
{
	formeEtId* pointeur = &formeTraitee;
}
void ajoutForme::Undo() 
{
	modeleUtilise.supprForme(formeTraitee->id);
}


