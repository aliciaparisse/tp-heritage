//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
//-----------------------------------



#include "Cercle.h"


Cercle::Cercle (int unX, int unY, int unRayon)
	: Point(unX, unY), rayon (unRayon)
{
	// Je suis pas sure que la ligne au dessus fonctionne, sinon on peu faire comme ça :
	// centre = new Point(unX, unY), à l'intérieur du bloc
	// A FAIRE ! Trouver comment incrémenter la variable nbElem de la classe Forme !
}	

Cercle::~Cercle ()
{
}

Cercle::deplacer(int dx, int dy)
{
	this->centre.deplacer();
}
