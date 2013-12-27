#if ! defined (COMMANDREADER_H)
#define COMMANDREADER_H

#include <string>
using namespace std;

class CommandReader
{
	public:
		CommandReader ( );
		virtual ~CommandReader ( );

		// fonction qui lit la ligne de commande rentr�e en param�tre (const char []).
		void readCommand (const char cmd []);

		// Fonction qui prend en param�tre la ligne de commande entr�e et l'instruction g�om�trique.
		// Si la ligne de commande est correcte, renvoie les coordonn�es de la forme g�om�trique.
		void defineCoordonnee (string cmdLine);

		// Compte les arguments de la ligne de commande en param�tre et teste leur type.
		// Si la ligne de commande renvoy�e est correcte, renvoie true.
		bool argumentNumber (string cmdLine, string cmdName);

		bool operator== (const string a, const char b []);

	protected:


};

#endif
