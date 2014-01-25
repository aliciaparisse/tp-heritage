//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// delForme.cpp
//-----------------------------------
#include "delForme.h"

delForme::delForme(string& unNom, Modele* unModele)
	: nom(unNom), modeleUtilise(unModele)
{
}

delForme::~delForme()
{
}

void delForme::Do()
{
	modeleUtilise->supprForme(nom);
}
void delForme::Undo()
{
	infoFormes rajoutForme = modeleUtilise->getInfoFormes(nom);
	modeleUtilise->ajoutForme(nom,rajoutForme);
}


