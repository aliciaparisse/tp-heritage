//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// deplacerForme.cpp
//-----------------------------------

#include "deplacerForme.h"

deplacerForme::deplacerForme(formeEtId& uneForme, Modele& unModele, int& unDepX, int& unDepY)
	: formeTraitee(uneForme), modeleUtilise(unModele), depX(unDepX), depY(unDepY)
{
}

deplacerForme::~deplacerForme()
{
}

void deplacerForme::Do()
{
	modeleUtilise.deplacerForme((formeTraitee.id), depX, depY);
}

void deplacerForme::Undo()
{
	modeleUtilise.deplacerForme((formeTraitee.id), -depX, -depY);
}