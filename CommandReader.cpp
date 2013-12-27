#include "CommandReader.h"
#include <string>
#include <iostream>
#include <deque>
using namespace std;


CommandReader::CommandReader ( )
{

}

CommandReader::~CommandReader ( )
{

}

void CommandReader::readCommand (const char cmd []) //D�cider si on met en param�tre un const char [] ou un istream (plus pratique le char
{
	string cmdName;
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
            //Probl�me pour la r�cup�ration des coordonn�es
            //Sans doute : d�claration des variables au pr�alable et remplacement des valeurs via cette fonction
            //Probl�mes lorsque le nombre de coordonn�es est inconnu
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
        cerr<<"Instuction envoy�e incorrecte";
        //Pourra �tre modifi�e en une autre instruction en fonction du type de retour de la fonction.
	}

}

void CommandReader::defineCoordonnee (string cmdLine)
{

}

bool CommandReader::argumentNumber (string cmdLine, string cmdName)
{
    if (cmdName == 'C')
    {
        deque<string> argumentList (3, ' ');
        int nbrArgument = 0;
        string newArgument;
        for (int i=0;i<sizeof(cmdLine);i++)
        {
            nbrArgument++;
            getline(cmdLine.c_str(),newArgument, ' ');
            argumentList[i] = newArgument;
        }
        if ((typeid(argumentList[1])==typeid(int)) && (typeid(argumentList[3])==typeid(int)))
        {
            return true
        }
        else
        {
            return false
        }
    }
    if (cmdName=='R')
}

int CoordonneeNumber (string cmdLine)
{

}

bool operator== (const string a, const char b [])
{
    bool egal (true);
    int i=0;
    while ((i<a.size()) && (b[i] != '\0') && egal)
    {
        egal = (a[i] == b[i]);
        i++;
    }
    return egal;
}

