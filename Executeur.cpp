//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Executeur.cpp
//-----------------------------------

#include <iostream>
#include <string>
#include "Executeur.h"
#include "stdlib.h"
using namespace std;

Executeur::Executeur(Controleur unControleur) : leControleur(unControleur)
{
}

Executeur::~Executeur()
{
}
void Executeur::executer(list<string>& args)
{

	list<string>:: const_iterator it = ++args.begin();

	int idNomForme (0);
	bool existe = nomExiste(*it,idNomForme);
	it=args.begin();
	string cmdName = *it;

	// CAS DU CERCLE
	if(cmdName.compare("C") == 0)
	{
		// Si le nom n'existe pas déjà, on crée la forme en question
		if (!existe)
		{
			++it;
			string nom=*it;
			++it;
			string X = *it;
			int x=atoi(X.c_str());
			++it;
			string Y = *it;
			int y=atoi(Y.c_str());
			++it;
			string R = *it;
			int r=atoi(R.c_str());
			Forme* cercle = new Cercle(x,y,r);

			//On crée une formeEtId qu'on insère dans la liste
			formeEtId nouvelleForme;
			int dernierId (0);
			dernierId = leControleur.getDernierId();
			nouvelleForme.laForme= cercle;
			nouvelleForme.id=dernierId;
			leControleur.ajouterLaForme(nouvelleForme);

			//On insère le nom dans la map
			noms.insert(pair<int,string>(dernierId,nom));
			cout << "R: OK" << endl << "R: #Nouvel objet: " << nom << endl << endl;
		}
		else
		{
			cerr << "R: ERR" << endl << "R: #Nom deja existant" << endl << endl;
		}
	}

	// CAS DU RECTANGLE OU DE LA LIGNE
	if ((cmdName.compare("R") == 0) || (cmdName.compare("L")==0))
	{
		// Si le nom n'existe pas déjà, on crée la forme en question
		if (!existe)
		{
			++it;
			string nom=*it;
			++it;
			string X1 = *it;
			int x1=atoi(X1.c_str());
			++it;
			string X2 = *it;
			int y1=atoi(X2.c_str());
			++it;
			string X3 = *it;
			int x2=atoi(X3.c_str());
			++it;
			string X4 = *it;
			int y2=atoi(X4.c_str());

			//On crée une formeEtId
			formeEtId nouvelleForme;
			int dernierId;
			dernierId = leControleur.getDernierId();
			if (cmdName.compare("R")==0)
			{
				Rectangle* rectangle = new Rectangle(x1, y1, x2, y2);
				nouvelleForme.laForme=rectangle;
				nouvelleForme.id=dernierId;

			}
			else if (cmdName.compare("L")==0)
			{
                Ligne* ligne = new Ligne(x1, y1, x2, y2);
                nouvelleForme.laForme=ligne;
                nouvelleForme.id=dernierId;
			}

			//On insère la nouvelle forme dans formes
			leControleur.ajouterLaForme(nouvelleForme);

			//On insère le nom dans la map
			noms.insert(pair<int,string>(dernierId,nom));
			cout << "R: OK" << endl << "R: #Nouvel objet: " << nom << endl << endl;
		}
		else
		{
			cerr << "R: ERR" << endl << "R: #Nom deja existant" << endl << endl;
		}

	}

	// CAS DE LA POLYLIGNE
	if (cmdName.compare("PL") == 0)
	{
		// Si le nom n'existe pas déjà, on crée la forme en question
		if (!existe)
		{
			++it;
			string nom=*it;
			++it;
			list<Point*> uneListe;
			while(it!=args.end())
			{
				string X = *it;
				int x= atoi(X.c_str());
				++it;
				string Y = *it;
				int y= atoi(Y.c_str());
				++it;
				Point* point = new Point(x,y);
				uneListe.push_back(point);

			}

			Polyligne* polyligne = new Polyligne(uneListe);
			//On crée une formeEtId qu'on insère dans la liste
			formeEtId nouvelleForme;
			int dernierId = leControleur.getDernierId();
			nouvelleForme.laForme=polyligne;
			nouvelleForme.id=dernierId;
			leControleur.ajouterLaForme(nouvelleForme);

			//On insère le nom dans la map
			noms.insert(pair<int,string>(dernierId,nom));
			cout << "R: OK" << endl << "R: #Nouvel objet: " << nom << endl << endl;
		}
		else
		{
			cerr << "R: ERR" << endl << "R: #Nom deja existant" << endl << endl;
		}
	}

	// CAS DE L'AGREGAT
	if (cmdName.compare("OA") == 0)
	{
		// Si le nom n'existe pas déjà, on crée la forme en question
		if (!existe)
		{
			++it;
			string nom=*it;
			++it;

			// On crée une liste de pointeurs de formes qu'on remplit en parcourant args et en vérifiant que les formes existent bien
			list <Forme*> laListe;
			bool nomExistant = true;
			while (it != args.end() && nomExistant)
			{
				string nomAnalyse = *it;
				bool nomTrouve (false);
				map<int,string>::iterator it2 = noms.begin();
				while (it2 != noms.end() && !nomTrouve)
				{
					string nomUtilise = it2->second;
					cout << nomUtilise << endl;
					if (nomAnalyse.compare(nomUtilise) == 0)
					{
						/*//Ici je veux affecter un pointeur à la forme dont je teste le nom
						Forme* pteur = *formes.at(it2->first)->laForme;
						laListe.push_back(pteur);*/
						cout << "if " << endl;
						nomTrouve = true;
						nomExistant = true;
					}
					else
                    {
                        nomExistant = false;
						cout << "else " << endl;
                    }
				}
				++it;
			}
			if (!nomExistant)
			{
				cerr << "R: ERR" << endl << "R: #Parametres incorrects" << endl << endl;
			}
			else
			{
				Agregat* agregat = new Agregat(laListe);

				//On crée une formeEtId qu'on insère dans la liste
				formeEtId nouvelleForme;
				int dernierId = leControleur.getDernierId();
				nouvelleForme.laForme=agregat;
				nouvelleForme.id=dernierId;
				leControleur.ajouterLaForme(nouvelleForme);

				//On insère le nom dans la map
				noms.insert(pair<int,string>(dernierId,nom));
				cout << "R: OK" << endl << "R: #Nouvel objet: " << nom << endl << endl;
			}

        }
		else
		{
			cerr << "R: ERR" << endl << "R: #Nom deja existant" << endl << endl;
		}
	}

	// CAS DU DELETE
	if (cmdName.compare("DELETE") == 0)
    {
        bool nomDeleteExiste (true);
        while (nomDeleteExiste)
        {
            for (it=++args.begin(); it!=args.end();it++)
            {
                string nomDelete (*it);
                int idNomDelete (0);
                nomDeleteExiste = nomExiste(nomDelete, idNomDelete);
                if (nomDeleteExiste)
                {
                    // On ne peut récupérer que l'id de la forme, mais on ne sait pas à quelle forme elle est associée
                    //Modifier méthode de suppression et déplacement pour qu'elles ne prennent que des id au lieu des formes.
                    //leControleur.supprimerLaForme(idNomDelete);
                }
                else
                {
                    cerr << "R: ERR" << endl << "R: #Aucune forme en memoire ne porte ce nom" << endl << endl;
                }
            }
        }
    }

    // CAS DU MOVE
	if (cmdName.compare("MOVE") == 0)
    {
        if (existe)
        {
            ++it;
			string nomMove=*it;
			++it;
			string X = *it;
			int dx=atoi(X.c_str());
			++it;
			string Y = *it;
			int dy=atoi(Y.c_str());
			//même remarque pour l'id connue et la forme manquante
			//leControleur.deplacerLaForme(idNomForme,dx,dy);
        }
        else
        {
            cerr << "R: ERR" << endl << "R: #Aucune forme en memoire ne porte ce nom" << endl << endl;
        }
    }

    // CAS DU LIST
	if (cmdName.compare("LIST") == 0)
    {
        map<int,string>::iterator itMap;
        while (itMap != noms.end())
        {
            int idFormeList = itMap->first;
            //Récupérer forme dans Modele à partir de Id

        }
    }

}

bool Executeur::nomExiste(string leNom, int& idNom)
{
		// On vérifie que le nom de la forme que l'on désire insérer n'existe pas déjà dans la map noms
	bool existe (false);
	if (noms.size() >= 1)
    {
        bool nomTrouve (false);
        map<int,string>::iterator it = noms.begin();
        while (it != noms.end() && !nomTrouve)
        {
            string unNom = it->second;
            if((leNom.compare(unNom)) == 0)
            {
                existe = true;
                idNom = it->first;
            }
		it++;
        }
    }
    else
    {
        existe = false;
    }
	return existe;
}
