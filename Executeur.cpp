//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Executeur.cpp
//-----------------------------------

#include "Executeur.h"

Executeur(Controleur unControleur, CommandReader unLecteur)
	: leControleur(unControleur), leLecteur(unLecteur)
{
}

Executeur::~Executeur()
{
}
void executer(list<string> args)
{
	
	list<string>:: const_iterator it = args.begin()++;

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
			Forme cercle = new Cercle(x,y,r);

			//On crée une formeEtId qu'on insère dans la liste
			formeEtId nouvelleForme;
			nouvelleForme.laForme(&cercle);
			nouvelleForme.id=leControleur.getDernierId;
			leControleur.ajouteLaForme(nouvelleForme);
			
			//On insère le nom dans la map
			noms.insert(pair<int,string>(dernierId,nom));
			dernierId++;
		}
		else
		{
			cout << "Le nom de ce rond est déjà utilisé" << endl;
		}
	}
	/*
	// CAS DU RECTANGLE OU DE LA LIGNE
	if ((strcmp(*it, "R") == 0) || (strcmp(*it, "L")==0))
	{
		// Si le nom n'existe pas déjà, on crée la forme en question
		if (existe==false)
		{
			it=args.begin();
			string nom=++it;
			++it;
			int x1=atoi(it);
			++it;
			int y1=atoi(it);
			++it;
			int x2=atoi(it);
			++it;
			int y2=atoi(it);
			++it;
			

			//On crée une formeEtId
			if (strcmp(*it,"R")==0)
			{
				Rectangle rectangle = new Rectangle(x1, y1, x2, y2);
				formeEtId nouvelleForme;
				nouvelleForme.laForme=rectangle;
				nouvelleForme.id=dernierId;

			}
			else if (strcmp(*it, "L")==0)
			{
			Ligne ligne = new Ligne(x1, y1, x2, y2);
			formeEtId nouvelleForme;
			nouvelleForme.laForme=ligne;
			nouvelleForme.id=dernierId;
			}

			//On insère la nouvelle forme dans formes
			formes.push_back(nouvelleForme);
			
			//On insère le nom dans la map
			noms.insert(pair<int,string>(dernierId,nom));
			dernierId++;
		}
		else
		{
			if(strcmp(*it, "R")==0)
			{
				cout << "Le nom de ce rectangle est déjà utilisé" << endl;
			}
			else if (strcmp(*it, "L")==0)
			{
				cout << "Le nom de cette ligne est déjà utilisé" << endl;
			}
		}

	}

	// CAS DE LA POLYLIGNE
	if (strcmp(*it, "PL") == 0)
	{
		// Si le nom n'existe pas déjà, on crée la forme en question
		if (existe==false)
		{
			it=args.begin();
			string nom=++it;
			++it;
			list<Point> uneListe;
			while(it!=args.end())
			{
				int x= atoi(it);
				++it;
				int y= atoi(it);
				++it;		
				Point point = new Point(x,y);
				uneListe.push_back(point);

			}
			Polyligne polyligne = new Polyligne(uneListe);
			//On crée une formeEtId qu'on insère dans la liste
			formeEtId nouvelleForme;
			nouvelleForme.laForme=polyligne;
			nouvelleForme.id=dernierId;
			formes.push_back(nouvelleForme);
			
			//On insère le nom dans la map
			noms.insert(pair<int,string>(dernierId,nom));
			dernierId++;
		}
		else
		{
			cout << "Le nom de cette polyligne est déjà utilisé" << endl;
		}
	}

	// CAS DE L'AGREGAT
	if (strcmp(*it, "OA") == 0)
	{
		// Si le nom n'existe pas déjà, on crée la forme en question
		if (existe==false)
		{
			it=args.begin();
			string nom=++it;
			++it;

			// On crée une liste de pointeurs de formes qu'on remplit en parcourant args et en vérifiant que les formes existent bien
			list <Forme*> laListe;
			while (it != args.end())
			{
				bool trouve = false;
				for (map <int,string>::const_iterator it2=noms.begin(); it2!=noms.end(); ++it2)
				{
					if (strcmp(*it, *it2->second) == 0)//DEMANDER AURELIEN !!
					{
						//Ici je veux affecter un pointeur à la forme dont je teste le nom
						Forme* pteur = *formes.at(it2->first)->laForme;
						laListe.push_back(pteur);
						trouve = true;
					}
				}
				if (trouve = false)
				{
					cout << "La forme" << it << "n'existe pas, elle ne peut pas être intégrée à l'agrégat" << endl;
				}
				++it;
			}

			Agregat agregat = new Agregat(laListe);

			//On crée une formeEtId qu'on insère dans la liste
			formeEtId nouvelleForme;
			nouvelleForme.laForme=agregat;
			nouvelleForme.id=dernierId;
			formes.push_back(nouvelleForme);
			
			//On insère le nom dans la map
			noms.insert(pair<int,string>(dernierId,nom));
			dernierId++;
		}
		else
		{
			cout << "Le nom de cet agrégat est déjà utilisé" << endl;
		}
	}
	
}
*/
}

bool Executeur::nomExiste(string leNom)
{
		// On vérifie que le nom de la forme que l'on désire insérer n'existe pas déjà dans la map noms
	bool existe = false;
	for (map<int,string>::iterator it=noms.begin(); it != noms.end(); ++it)
	{
		// La partie it-> string est fausse, je dois trouver comment la modifier
		string unNom = it->second;
		if((leNom.compare(unNom)) == 0)
		{
			existe = true; 
		}
	}
	return existe;

}



