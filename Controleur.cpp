//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Controleur.cpp
//-----------------------------------

#include "Controleur.h"

//Contructeur de la classe
Controleur::Controleur()
	: commandeCourante(0)
{
}

//Destructeur de la classe
Controleur::~Controleur()
{
}

//Le controleur ajoute La Forme formeAjoutee à son Modèle
void Controleur::ajouterLaForme(formeEtId formeAjoutee)
{
	Command commandeAjout = new ajoutForme(formeAjoutee, monModele);
	commandes.push_back(commandeAjout);
	commandeAjout.Do();
 	commandeCourante++;	
}

//Le controleur supprime la forme formeSupprimee de son Modèle
void Controleur::supprimerLaForme(formeEtId formeSupprimee)
{
	Command commandeSuppr = new delForme(formeSupprimee, monModele);
	commandes.push_back(*commandeSuppr);
	(*commandeSuppr).Do();
	commandeCourante++;
}

//Le controleur déplace la forme formeDeplacee dans son Modèle
void Controleur::deplacerLaForme(formeEtId formeDeplacee, int dx, int dy)
{
	Command commandeDepl = new deplacerForme(formeDeplacee, monModele, dx, dy);
	commandes.push_back(*commandeDepl);
	(*commandeDepl).Do();
	commandeCourante++;
}


void Controleur::chargerUnFichier(string nomFichier)
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

