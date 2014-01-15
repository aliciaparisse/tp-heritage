//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// CommandReader.cpp
//-----------------------------------

#include "CommandReader.h"
#include <string>
#include <iostream>
#include <list>
using namespace std;


CommandReader::CommandReader (char* commande [])
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
	list<string> argumentListTest;
	getline (cmd, cmdName, ' ');
	if (cmdName=='C')
   	{
        	cmdstr.erase(0, cmdstr.find(' '));
        	argumentListTest=getInfos (cmdstr,nbrArgument);
        	if (nbrArgument==4)
            	{
                	list<string>::iterator it
			int = correctArgument(0);
			for (it=argumentListTest.begin()+1;it=argumentListTest.end();it++)
			{
				testInt = strtol(it, NULL, 0);
				if (testInt != 0L)
				{
					correctArgument++;
				}
				else
				{
					testArgument = false
					cerr>> "Commande entree incorrecte, type d'arguments entre non valide.";
					return testArgument;
				}

			}
			if (correctArgument==3)
			{
				testArgument = true;
				return testArgument;
			}
            	}
            	else
            	{
                	testArgument = false;
                	cerr>> "Commande entree incorrecte, nombre d'arguments entre invalides.";
                	return testArgument;
            	}
    	}
    	/*else if (cmdName=='R')
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
        	cerr<<"Instuction envoyee incorrecte";
        	//Pourra etre modifiee en une autre instruction en fonction du type de retour de la fonction.
	}*/

}

list<string> CommandReader::getInfos (string cmdLine, int& nbrArgument)
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
	return argumentList;
}

/*bool operator== (const string a, const char b [])
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
*/
