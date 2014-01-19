//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Controleur.cpp
//-----------------------------------

#include "Controleur.h"

int Controleur::commandeCourante = 0;

//Contructeur de la classe
Controleur::Controleur()
{
}

//Destructeur de la classe
Controleur::~Controleur()
{
}

//Le controleur ajoute La Forme formeAjoutee à son Modèle
void Controleur::ajouterLaForme(formeEtId& formeAjoutee)
{
	ajoutForme* ajout= new ajoutForme(formeAjoutee, monModele);
	commandes.push_back(ajout);
	ajout->Do();
 	commandeCourante++;
}

//Le controleur supprime la forme formeSupprimee de son Modèle
void Controleur::supprimerLaForme(formeEtId& formeSupprimee)
{
	delForme* suppr = new delForme (formeSupprimee, monModele);
	commandes.push_back(suppr);
	suppr->Do();
	commandeCourante++;
}

//Le controleur déplace la forme formeDeplacee dans son Modèle
void Controleur::deplacerLaForme(formeEtId& formeDeplacee, int& dx, int& dy)
{
	deplacerForme* deplacer = new deplacerForme (formeDeplacee, monModele, dx, dy);
	commandes.push_back(deplacer);
	deplacer->Do();
	commandeCourante++;
}

void Controleur::chargerUnFichier(string& nomFichier)
{

}

void Controleur::Undo()
{
	(commandes.at(commandeCourante))->Undo();
	commandeCourante--;
}

void Controleur::Redo()
{
	commandeCourante++;
	(commandes.at(commandeCourante))->Do();
}

int Controleur::getDernierId()
{
	return monModele.getDernierId();
}

