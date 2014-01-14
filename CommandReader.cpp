//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// CommandReader.cpp
//-----------------------------------

#include "CommandReader.h"
#include <string>
#include <iostream>
#include <list>
using namespace std;


CommandReader::CommandReader (const char commande [])
{
    cmd = commande;
}

CommandReader::~CommandReader ( )
{

}

bool CommandReader::readCommand ( )
{
	bool testArgument(true);
	string cmdName;
	string cmdstr(cmd);
	int nbrArgument;
	getline (cmd, cmdName, ' ');
	if (cmdName=='C')
   	 {
        	cmdstr.erase(0, cmdstr.find(' '));
        	getInfos (cmdstr,cmdName,nbrArgument)
        	if (nbrArgument==3)
            {
                // Vérifier que les coordonnées sont bien des nombres.
            }
            else
            {
                testArgument = false;
                cerr>> "Commande entrée incorrecte, nombre d'arguments entrés invalides."
                return testArgument;
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

list<string> CommandReader::getInfos (string cmdLine, string cmdName, int& nbrArgument)
{
	list<string> argumentList;
	nbrArgument=0;
    string newArgument;
    for (int i=0;i<sizeof(cmdLine);i=cmdLine.find(' ',0))
    {
        nbrArgument++;
        getline(cmdLine.c_str(),newArgument, ' ');
        argumentList.push_back(newArgument);
    }
    /*if ((typeid(argumentList[1])==typeid(int)) && (typeid(argumentList[3])==typeid(int)))
    {
        return true
    }
    else
    {
        return false
    }*/
    }
    if (cmdName=='R')
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

