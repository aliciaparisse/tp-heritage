//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// LoadFile.cpp
//-----------------------------------

#include "LoadFile.h"

LoadFile::LoadFile(Controleur* unControleur, string &unNomFichier)
	:controleur(unControleur), nomFichier(unNomFichier)
{
}

LoadFile::~LoadFile()
{
}

void LoadFile::Do()
{
	ifstream ficDesc (nomFichier, std::ifstream::in);
	Executeur* executeur = new Executeur(controleur);
	while(!ficDesc.eof())
	{
		
		string cmd;
		getline(ficDesc, cmd);
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
		}
	}

}

void LoadFile::Undo()
{

}

