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

		// fonction qui lit la ligne de commande rentr�e en param�tre (const char [])
		// et renvoie un bool�en vrai si la commande est correcte (commande principale correcte et arguments associ�s corrects).
		bool readCommand (list<string> & ListArgument);

		// fonction enregistrant les arguments de la ligne de commande et les envoyant dans une liste.
		list<string>  getInfos (string cmdLine,int& nbrArgument);

		//bool operator== (const string a, const char b []);

	protected:
		string cmd;
};

#endif
