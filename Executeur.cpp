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

Executeur::Executeur(Controleur* unControleur) : leControleur(unControleur)
{
}

Executeur::~Executeur()
{
}
void Executeur::executer(list<string>& args)
{

	list<string>:: const_iterator it = ++args.begin();

	bool existe = nomExiste(*it);
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
			Cercle* cercle = new Cercle(nom,x,y,r);

			infoFormes nouvelleForme;
			nouvelleForme.laForme= cercle;
			nouvelleForme.codeForme=cmdName;
			leControleur->ajouterLaForme(nom,nouvelleForme);

			noms.push_back(nom);
			cout << "R: OK" << endl << "R: #Nouvel objet: " << nom << endl << endl;
		}
		else
		{
			cerr << "R: ERR" << endl << "R: #Nom deja existant" << endl << endl;
		}
	}
/*
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
				Rectangle* rectangle = new Rectangle(nom, x1, y1, x2, y2);
				nouvelleForme.laForme=rectangle;
				nouvelleForme.id=dernierId;

			}
			else if (cmdName.compare("L")==0)
			{
                Ligne* ligne = new Ligne(nom,x1, y1, x2, y2);
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

			Polyligne* polyligne = new Polyligne(nom,uneListe);
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

            list<Forme*> laListe;
			bool nomExistant = true;
			while (it != args.end() && nomExistant)
			{
				string nomAnalyse = *it;
				bool nomTrouve (false);
				map<int,string>::iterator it2 = noms.begin();
				while (it2 != noms.end() && !nomTrouve)
				{
					string nomUtilise = it2->second;
					if (nomAnalyse.compare(nomUtilise) == 0)
					{
						nomTrouve = true;
						nomExistant = true;
					}
					else
                    			{
                        			nomExistant = false;
                    			}
					++it2;
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
	}*/

	// CAS DU DELETE
	if (cmdName.compare("DELETE") == 0)
    {
        bool nomDeleteExiste (true);
        it = ++args.begin();
        while (nomDeleteExiste && it!=args.end())
        {
                string nomDelete (*it);
                it++;
                nomDeleteExiste = nomExiste(nomDelete);
                if (nomDeleteExiste)
                {
                    leControleur->supprimerLaForme(nomDelete);
                    vector<string>::iterator itNoms = noms.begin();
                    while (nomDelete.compare(*itNoms) != 0)
                    {
                        itNoms++;
                    }
                    noms.erase(itNoms);

                    cout << "R: OK" << endl << "R: #Objet: " << nomDelete << " supprime" << endl << endl;
                }
                else
                {
                    cerr << "R: ERR" << endl << "R: #Aucune forme en memoire ne porte ce nom" << endl << endl;
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

			leControleur->deplacerLaForme(nomMove,dx,dy);
			cout << "R: OK" << endl << "R: #Objet: " << nomMove << " deplace" << endl << endl;
        }
        else
        {
            cerr << "R: ERR" << endl << "R: #Aucune forme en memoire ne porte ce nom" << endl << endl;
        }
    }

    // CAS DU LIST
	if (cmdName.compare("LIST") == 0)
    {
        vector<string>::iterator itNom = noms.begin();
        while (itNom != noms.end())
        {
            string listElements = "R: ";
            listElements += leControleur->afficherElements(*itNom);
            cout << listElements << endl;
            itNom++;
        }
        int nbElements = leControleur->getNbFormes();
        cout << "R: #Le modele actuel compte " << nbElements << " objets" << endl << endl;
    }


    // CAS DU LOAD
	if(cmdName.compare("LOAD")==0)
	{
		++it;
		string nomFichierExt=*it;
		int posPt = nomFichierExt.rfind('.');
		string nomFichier=nomFichierExt.substr(0,posPt);
		leControleur->chargerUnFichier(nomFichier);

	}

	// CAS DU UNDO ET REDO
	if ((cmdName.compare("UNDO") == 0) || (cmdName.compare("REDO") == 0))
    {
        infoUndo temp;
        static string nomTemp = "";
        static string actionTemp = "";
        if (cmdName.compare("UNDO") == 0)
        {
            int commandeCourante = leControleur->getCommandeCourante();
            if (commandeCourante>0)
            {
                leControleur->Undo();
                temp = leControleur->getModifVectExecuteur ();
                nomTemp = temp.nomFormeUndo;
                actionTemp = temp.actionUndo;
                if (actionTemp.compare("undoAjout") == 0)
                {
                    vector<string>::iterator itNoms = noms.begin();
                    while (nomTemp.compare(*itNoms) != 0)
                    {
                        itNoms++;
                    }
                    cout << "nom a supprimer : " << *itNoms << endl;
                    noms.erase(itNoms);
                }
                else if (actionTemp.compare("undoSuppr") == 0)
                {
                    cout << "nom a rajouter : " << nomTemp << endl;
                    noms.push_back(nomTemp);
                }
                cout << "R: OK" << endl << endl;
            }
            else
            {
                cerr << "R: ERR" << endl << "R: #Aucune commande disponible pour UNDO" << endl << endl;
            }
        }
        else if (cmdName.compare("REDO") == 0)
        {
            int commandeCourante = leControleur->getCommandeCourante();
            if (commandeCourante>0)
            {
                bool enableRedo = leControleur->enableRedo();
                if (enableRedo)
                {
                    leControleur->Redo();
                    if (actionTemp.compare("undoAjout") == 0)
                    {
                        cout << "Nom a re-rajouter : " << nomTemp << endl;
                        noms.push_back(nomTemp);
                    }
                    else if (actionTemp.compare("undoSuppr") == 0)
                    {
                        vector<string>::iterator itNoms = noms.begin();
                        while (nomTemp.compare(*itNoms) != 0)
                        {
                            itNoms++;
                        }
                        cout << "Nom a re-resupprimer : " << *itNoms << endl;
                        noms.erase(itNoms);
                    }
                    cout << "R: OK" << endl << endl;
                }
                else
                {
                    cerr << "R: ERR" << endl << "R: #Commande UNDO necessaire avant d'executer un REDO" << endl << endl;
                }
            }
            else
            {
                cerr << "R: ERR" << endl << "R: #Aucune commande disponible pour REDO" << endl << endl;
            }
        }

    }
/*
    // CAS DU CLEAR
	if (cmdName.compare("CLEAR") == 0)
    {
        vector<string>::iterator itNom = noms.begin();
        for (itNom;itNom != noms.end();itNom++)
        {
            leControleur->supprimerLaForme(*itNom);
        }
    }
*/
}

//Parcours le vector noms et vérifie si le nom existe déjà
bool Executeur::nomExiste(string leNom)
{
    // On vérifie que le nom de la forme que l'on désire insérer n'existe pas déjà dans le vector noms
	bool existe (false);
	if (!noms.empty())
    {
        bool nomTrouve (false);
        vector<string>::iterator it = noms.begin();
        while (it != noms.end() && !nomTrouve)
        {
            string unNom = *it;
            if((leNom.compare(unNom)) == 0)
            {
                existe = true;
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
