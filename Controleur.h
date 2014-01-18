//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Controleur.h
//-----------------------------------

#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "Command.h"
#include "ajoutForme.h"
#include "delForme.h"
#include "deplacerForme.h"
#include "Modele.h"
#include  <vector>


using namespace std; 

class Controleur
{
	private: 
		vector <Command*> commandes;
		Modele monModele;
		int commandeCourante;

	public: 
		Controleur();
		virtual ~Controleur();
		void ajouterLaForme(formeEtId formeAjoutee);
		void supprimerLaForme(formeEtId formeSupprimee); 
		void deplacerLaForme(formeEtId formeDeplacee, int dx, int dy);
		void chargerUnFichier(string nomFichier);	
		void Undo();
		void Redo(); 

};
#endif
