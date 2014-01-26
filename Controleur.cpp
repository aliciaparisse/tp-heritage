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
	deplacer->Do();
	commandeCourante++;
}

//Le controleur charge le fichier nomFichier et ajoute les formes correspondants aux commandes
void Controleur::chargerUnFichier(string& nomFichier)
{
	LoadFile* load = new LoadFile(this, nomFichier);
	load->Do();
	commandeCourante++;
}

//Le Controleur revient sur la dernière commande exécutée et l'annule
void Controleur::Undo()
{
	commandeCourante--;
	listCommandUndo.push_back(commandeCourante);
	(commandes.at(commandeCourante))->Undo();

}

//Le controleur annule le UNDO précédent en exécutant à nouveau la commande
void Controleur::Redo()
{
	(commandes.at(commandeCourante))->Do();
    commandeCourante++;
}

//Récupère les élements composant une forme à partir de son nom
string Controleur::afficherElements (string& nom)
{
    return monModele->afficherElements (nom);
}

//Récupère le nombre des formes "actives"
int Controleur::getNbFormes()
{
	return monModele->getNbFormes();
}

//Repère où on se trouve actuellement dans la liste des commandes effectuées
int Controleur::getCommandeCourante()
{
    return commandeCourante;
}

//Vérifie si la commande précédent le REDO était bien un UNDO
bool Controleur::enableRedo()
{
    int nbDernierUndo = listCommandUndo.back();
    if (commandeCourante == nbDernierUndo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

infoUndo Controleur::getModifVectExecuteur ()
{
    return monModele->getInfoUndo();
}
