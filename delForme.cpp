//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// delForme.cpp
//-----------------------------------
#include "delForme.h"

delForme::delForme(formeEtId& uneForme, Modele& unModele)
	: formeTraitee(uneForme), modeleUtilise(unModele)
{
}

delForme::~delForme()
{
}

void delForme::Do()
{
	modeleUtilise.supprForme(formeTraitee.id);
}
void delForme::Undo()
{
	formeEtId* pointeur = &formeTraitee;
	modeleUtilise.ajoutForme(pointeur);
}


