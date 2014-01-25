//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// deplacerForme.cpp
//-----------------------------------

#include "deplacerForme.h"

deplacerForme::deplacerForme(string& unNom, Modele* unModele, int& unDepX, int& unDepY)
	: nomFormeTraitee(unNom), modeleUtilise(unModele), depX(unDepX), depY(unDepY)
{
}

deplacerForme::~deplacerForme()
{
}

void deplacerForme::Do()
{
	cout << "do deplacer" << endl;
	modeleUtilise->deplacerForme(nomFormeTraitee, depX, depY);
}

void deplacerForme::Undo()
{
	depX=-depX;
	depY=-depY;
	modeleUtilise->deplacerForme(nomFormeTraitee,depX,depY);
}
