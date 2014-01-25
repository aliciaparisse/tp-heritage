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
    Modele* unModele = new Modele();
    monModele = unModele;
}

//Destructeur de la classe
Controleur::~Controleur()
{
}

//Le controleur ajoute La Forme formeAjoutee à son Modèle
void Controleur::ajouterLaForme(string& nom,infoFormes& formeAjoutee)
{
	ajoutForme* ajout= new ajoutForme(nom, formeAjoutee, monModele);
	commandes.push_back(ajout);
	ajout->Do();
 	commandeCourante++;
}

//Le controleur supprime la forme formeSupprimee de son Modèle
void Controleur::supprimerLaForme(string& nomFormeSupprimee)
{
	delForme* suppr = new delForme (nomFormeSupprimee, monModele);
	commandes.push_back(suppr);
	suppr->Do();
	commandeCourante++;
}

//Le controleur déplace la forme formeDeplacee dans son Modèle
void Controleur::deplacerLaForme(string& nomFormeDeplacee, int& dx, int& dy)
{
	deplacerForme* deplacer = new deplacerForme (nomFormeDeplacee, monModele, dx, dy);
	commandes.push_back(deplacer);
	cout << "appel controleur" << endl;
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

string Controleur::afficherElements (string& nom)
{
    return monModele->afficherElements (nom);
}

int Controleur::getNbFormes()
{
	return monModele->getNbFormes();
}

