//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Cercle.cpp
//-----------------------------------


#include "Point.h"
#include "Cercle.h"

Cercle::Cercle (string& unNom, int& unX, int& unY, int& unRayon)
	: rayon (unRayon),	centre(unX, unY), nomCercle(unNom)
{
}

Cercle::~Cercle()
{
}

void Cercle::deplacer(int& dx, int& dy)
{
	cout << "appel Cercle" << endl;
	this->centre.deplacer(dx, dy);
	cout << "Cercle deplace de : " << dx << "," << dy << endl;
}

string Cercle::afficherCoord ()
{
    string coord = centre.getCoord();
    ostringstream oss;
    oss << rayon;
    coord += " " + oss.str();
    return coord;
}
