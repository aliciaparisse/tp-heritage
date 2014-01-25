//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// LoadFile.cpp
//-----------------------------------

#include "LoadFile.h"

LoadFile::LoadFile(Controleur &unControleur, )
	:controleur(unControleur), executeur(unExecuteur)
{
}

LoadFile::~LoadFile()
{
}

void LoadFile::Do()
{
	ifstream ficDesc (nomFichier, ios::openmode mode = ios::in)
	Controleur unControleur;
  Executeur* executeur = new Executeur(unControleur);
	while(!ficDesc.eof())
	{
		
		string cmd;
		
		cin >> cmd;
		CommandReader* cmdRd = new CommandReader(cmd);
		bool estValide (true);
		if (cmd.compare("EXIT") != 0)
		{
			list<string> listArgument;
			estValide = cmdRd->readCommand(listArgument);
			if (estValide)
			{
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

