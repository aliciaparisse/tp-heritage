//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// CommandReader.h
//-----------------------------------

#if ! defined (COMMANDREADER_H)
#define COMMANDREADER_H

#include <string>
#include <list>
using namespace std;

class CommandReader
{
	public:
		CommandReader (string unCmd);
		virtual ~CommandReader ( );

		// fonction qui lit la ligne de commande rentr�e en param�tre
		// et renvoie un bool�en vrai si la commande est correcte (commande principale correcte et arguments associ�s corrects).
		// Renvoie �galement en param�tre une liste de strings repr�sentant les �l�ments de la ligne de commande.
		bool readCommand (list<string> & ListArgument);

		// fonction enregistrant les arguments de la ligne de commande en param�tre et les envoyant dans une liste.
		// Renvoie �galement par r�f�rence le nombre d'argument composant la ligne de commande en param�tre.
		list<string>  getInfos (string cmdLine,int& nbrArgument);

	protected:
		string cmd;
};

#endif
