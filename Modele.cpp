//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Modele.cpp
//-----------------------------------

#include "Modele.h"

Modele::Modele()
{
    nbFormes =0;
}

Modele::~Modele()
{
}

void Modele::ajoutForme(string& nom, infoFormes& uneForme)
{
	formes.insert(pair<string,infoFormes>(nom,uneForme));
	++nbFormes;
}

void Modele::supprForme(string& nom)
{
	formes.erase(nom);
	--nbFormes;
}

void Modele::deplacerForme(string& nom, int& unDx, int& unDy)
{
    map<string,infoFormes>::iterator itMap = formes.find(nom);
    Forme* deplaceForme = (itMap->second).laForme;
    deplaceForme->deplacer(unDx,unDy);
}

string Modele::afficherElements (string& nom)
{
    map<string,infoFormes>::iterator itMap = formes.find(nom);
    string cmdName = (itMap->second).codeForme;
    Forme* coordForme = (itMap->second).laForme;
    string coord = coordForme->afficherCoord();
    string listElements = cmdName;
    listElements += " ";
    listElements += nom;
    listElements += " ";
    listElements += coord;
    return listElements;
}

int Modele::getNbFormes()
{
	return nbFormes;
}

infoFormes Modele::getInfoFormes(string& nom)
{
    map<string,infoFormes>::iterator itMap = formes.find(nom);
    return itMap->second;
}

void Modele::modifVectExecuteur(string& nom, int& expediteur)
{
    infosUndo.nomFormeUndo = nom;
    if (expediteur == 1)
    {
        infosUndo.actionUndo = "undoAjout";
    }
    else if (expediteur == 2)
    {
        infosUndo.actionUndo = "undoSuppr";
    }
}

infoUndo Modele::getInfoUndo()
{
    return infosUndo;
}
