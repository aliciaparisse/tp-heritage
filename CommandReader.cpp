#include "CommandReader.h"
#include <string>
#include <iostream>
using namespace std;


CommandReader::CommandReader ( )
{

}

CommandReader::~CommandReader ( )
{

}

void CommandReader::readCommand (const char cmd [])
{
	typeCommand cmdName;
	bool testArgument(true);
	string cmdstr(cmd);
	getline (cmd, cmdName, ' ');
	if (cmdName=='C')
    {
        cmdstr.erase(0, cmdstr.find(' '));
        testArgument = argumentNumber (cmdstr);
        int x;
        int y;
        if (testArgument)
        {
            defineCoordonnee (cmdstr,cmdName);
            //Problème pour la récupération des coordonnées
            //Sans doute : déclaration des variables au préalable et remplacement des valeurs via cette fonction
            //Problèmes lorsque le nombre de coordonnées est inconnu
        }
    }
    else if (cmdName=='R')
    {
        cmdstr.erase(0, cmdstr.find(' '));
        testArgument = argumentNumber (cmdstr);
    }
    else if (cmdName=='L')
	{
    	cmdstr.erase(0, cmdstr.find(' '));
        testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="PL")
	{
        cmdstr.erase(0, cmdstr.find(' '));
        testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="OA")
	{
    	cmdstr.erase(0, cmdstr.find(' '));
        testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="DELETE")
	{
    	cmdstr.erase(0, cmdstr.find(' '));
        testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="MOVE")
	{
	    cmdstr.erase(0, cmdstr.find(' '));
        testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="LIST")
	{
    	cmdstr.erase(0, cmdstr.find(' '));
		testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="UNDO")
	{
    	cmdstr.erase(0, cmdstr.find(' '));
        testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="REDO")
	{
    	cmdstr.erase(0, cmdstr.find(' '));
		testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="LOAD")
	{
    	cmdstr.erase(0, cmdstr.find(' '));
		testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="SAVE")
	{
    	cmdstr.erase(0, cmdstr.find(' '));
		testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="CLEAR")
	{
	    cmdstr.erase(0, cmdstr.find(' '));
		testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="EXIST")
	{
	    cmdstr.erase(0, cmdstr.find(' '));
		testArgument = argumentNumber (cmdstr);
	}
	else
    {
        cerr<<"Instuction envoyée incorrecte";
        //Pourra être modifiée en une autre instruction en fonction du type de retour de la fonction.
	}

}

void CommandReader::defineCoordonnee (string cmd, typeCommand & cmdName)
{

}

bool CommandReader::argumentNumber (string cmdLine)
{

}

