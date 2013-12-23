#include "CommandReader.h"
#include <string>
#include <iostream>
using namespace std;


commandReader () {};

virtual ~commandReader () {};

void readCommand (const char cmd [])
{
	typeCommand cmdName;
	bool testArgument(true);
	string cmdstr(cmd);
	getline (cmd, cmdName, ' ');
	switch (cmdName)
		case 'C':
			testArgument = argumentNumber (cmd);
			cmdstr.erase(0, cmdstr.find(' '));
			int x;
			int y;
			if (testArgument)
			{
				defineCoordonnee (cmdstr,cmdName);
				//Problème pour la récupération des coordonnées.
			}
			break;
		case 'R':
			testArgument = argumentNumber (cmd);
			break;
		case 'L':
			testArgument = argumentNumber (cmd);
			break;
		case "PL":
			testArgument = argumentNumber (cmd);
			break;
		case "OA":
			testArgument = argumentNumber (cmd);
			break;
		case "DELETE":
			testArgument = argumentNumber (cmd);
			break;
		case "MOVE":
			testArgument = argumentNumber (cmd);
			break;
		case "LIST":
			testArgument = argumentNumber (cmd);
			break;
		case "UNDO":
			testArgument = argumentNumber (cmd);
			break;
		case "REDO":
			testArgument = argumentNumber (cmd);
			break;
		case "LOAD":
			testArgument = argumentNumber (cmd);
			break;
		case "SAVE":
			testArgument = argumentNumber (cmd);
			break;
		case "CLEAR":
			testArgument = argumentNumber (cmd);
			break;
		case "EXIST":		
			testArgument = argumentNumber (cmd);
			break;
	
}
