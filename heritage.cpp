//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// heritage.cpp
//-----------------------------------


#include <iostream>
#include <list>
#include "CommandReader.h"

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
				// :qcout << endl << "R: OK" << endl;
				// Executeur exct = new Executeur (cmd);
				// Remplir la suite avec les méthodes de Executeur
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

