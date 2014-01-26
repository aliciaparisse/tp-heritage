//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
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

//Le controleur ajoute La Forme formeAjoutee � son Mod�le
void Controleur::ajouterLaForme(string& nom,infoFormes& formeAjoutee)
{
	ajoutForme* ajout= new ajoutForme(nom, formeAjoutee, monModele);
	commandes.push_back(ajout);
	ajout->Do();
 	commandeCourante++;
}

//Le controleur supprime la forme formeSupprimee de son Mod�le
void Controleur::supprimerLaForme(string& nomFormeSupprimee)
{
	delForme* suppr = new delForme (nomFormeSupprimee, monModele);
	commandes.push_back(suppr);
	suppr->Do();
	commandeCourante++;
}

//Le controleur d�place la forme formeDeplacee dans son Mod�le
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

//Le Controleur revient sur la derni�re commande ex�cut�e et l'annule
void Controleur::Undo()
{
	commandeCourante--;
	listCommandUndo.push_back(commandeCourante);
	(commandes.at(commandeCourante))->Undo();

}

//Le controleur annule le UNDO pr�c�dent en ex�cutant � nouveau la commande
void Controleur::Redo()
{
	(commandes.at(commandeCourante))->Do();
    commandeCourante++;
}

//R�cup�re les �lements composant une forme � partir de son nom
string Controleur::afficherElements (string& nom)
{
    return monModele->afficherElements (nom);
}

//R�cup�re le nombre des formes "actives"
int Controleur::getNbFormes()
{
	return monModele->getNbFormes();
}

//Rep�re o� on se trouve actuellement dans la liste des commandes effectu�es
int Controleur::getCommandeCourante()
{
    return commandeCourante;
}

//V�rifie si la commande pr�c�dent le REDO �tait bien un UNDO
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
