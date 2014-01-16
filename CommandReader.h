//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
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

		// fonction qui lit la ligne de commande rentrée en paramètre
		// et renvoie un booléen vrai si la commande est correcte (commande principale correcte et arguments associés corrects).
		// Renvoie également en paramètre une liste de strings représentant les éléments de la ligne de commande.
		bool readCommand (list<string> & ListArgument);

		// fonction enregistrant les arguments de la ligne de commande en paramètre et les envoyant dans une liste.
		// Renvoie également par référence le nombre d'argument composant la ligne de commande en paramètre.
		list<string>  getInfos (string cmdLine,int& nbrArgument);

	protected:
		string cmd;
};

#endif
