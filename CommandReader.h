#if ! defined (COMMANDREADER_H)
#define COMMANDREADER_H

#include <string>
using namespace std;

enum typeCommand :string
{
	C,
	R,
	L,
	PL,
	OA,
	DELETE,
	MOVE,
	LIST,
	UNDO,
	REDO,
	LOAD,
	SAVE,
	CLEAR,
	EXIT,
};

class CommandReader
{
	public:
		CommandReader ( );
		virtual ~CommandReader ( );

		// fonction qui lit la ligne de commande rentrée en paramètre (const char []).
		void readCommand (const char cmd []);

		// Fonction qui prend en paramètre la ligne de commande entrée et l'instruction géométrique.
		// Si la ligne de commande est correcte, renvoie les coordonnées de la forme géométrique.
		void defineCoordonnee (string cmd, typeCommand & cmdName);

		// Compte les arguments de la ligne de commande en paramètre et teste leur type.
		// Si la ligne de commande renvoyée est correcte, renvoie true.
		bool argumentNumber (string cmdLine);

	protected:


};

#endif
