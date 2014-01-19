//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// LoadFile.cpp
//-----------------------------------

#include "LoadFile.h"

LoadFile::LoadFile(formeEtId &uneForme, Modele &unModele)
	:formeTraitee(uneForme), modeleUtilise(unModele)
{
}

LoadFile::~LoadFile()
{
}

void LoadFile::Do()
{
	ifstream ficDesc (nomFichier, ios::openmode mode = ios::in)
	while(!ficDesc.eof())
	{
		string cmd;
		cout << endl << "C: ";
		cin >> cmd;
		CommandReader* cmdRd = new CommandReader(cmd);
		bool estValide (true);
		if (cmd.compare("EXIT") != 0)
		{
			list<string> listArgument;
			estValide = cmdRd->readCommand(listArgument);
			if (estValide)
			{
                Controleur unControleur;
                Executeur* executeur = new Executeur(unControleur);
                executeur->executer(listArgument);
			}
		}
		else
		{
			cout << endl << "R: " << endl;
			continuer = false;
		}
	}

}

void LoadFile::Undo()
{
}

