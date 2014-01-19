//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// heritage.cpp
//-----------------------------------


#include <iostream>
#include <list>
#include "CommandReader.h"
#include "Executeur.h"
#include "Controleur.h"
using namespace std;

int main (int arc, const char **argv)
{
	bool continuer (true);
	while (continuer)
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
	return 0;
}
