//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// CommandReader.cpp
//-----------------------------------

#include "CommandReader.h"
#include <string>
#include <iostream>
#include <list>
#include "stdlib.h"
using namespace std;


CommandReader::CommandReader (string commande)
{
    cmd = commande;
}

CommandReader::~CommandReader ( )
{

}

bool CommandReader::readCommand (list<string> & listArgument)
{
	bool testArgument(true);
	int nbrArgument;
	list<string> argumentListTest;
	list<string> nomForme;

	char* cmdNameTemp;
	size_t tailleCmdName = cmd.find(' ',0);
	cmd.copy(cmdNameTemp,tailleCmdName,0);
    string cmdName (cmdNameTemp);

	if (cmdName.compare("C") == 0)
   	{
        cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        if (nbrArgument==4)
        {
            list<string>::iterator it;
            int correctArgument(0);
            for (it=argumentListTest.begin()++;it!=argumentListTest.end();it++)
            {
                int testInt(0);
                string strTest (*it);
                testInt = strtol(strTest.c_str(), NULL, 0);
                if (testInt != 0L)
                {
                    correctArgument++;
                }
                else
                {
                    testArgument = false;
                    cerr << endl << "R: ERR" << endl << "R: /#Parametres non valides" << endl;
                    return testArgument;
                }

            }
            if (correctArgument==3)
            {
                listArgument = argumentListTest;
                listArgument.push_front(cmdName);
                testArgument = true;
                list<string>::iterator temp;
                temp = listArgument.begin();
                temp++;
                nomForme.push_back (*temp);
                return testArgument;
            }
        }
        else
        {
            testArgument = false;
            cerr << endl << "R: ERR" << endl << "R: /#Nombre de parametre incorrect" << endl;
            return testArgument;
        }
    }
    else if ((cmdName.compare("R") == 0) || (cmdName.compare("L") == 0))
    {
        cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        if (nbrArgument==5)
        {
            list<string>::iterator it;
            int correctArgument(0);
            for (it=argumentListTest.begin()++;it!=argumentListTest.end();it++)
            {
                int testInt(0);
                string strTest (*it);
                testInt = strtol(strTest.c_str(), NULL, 0);
                if (testInt != 0L)
                {
                    correctArgument++;
                }
                else
                {
                    testArgument = false;
                    cerr << endl << "R: ERR" << endl << "R: /#Parametres non valides" << endl;
                    return testArgument;
                }
            }
            if (correctArgument==3)
            {
                listArgument = argumentListTest;
                listArgument.push_front(cmdName);
                testArgument = true;
                list<string>::iterator temp;
                temp = listArgument.begin();
                temp++;
                nomForme.push_back (*temp);
                return testArgument;
            }
        }
        else
        {
            testArgument = false;
            cerr << endl << "R: ERR" << endl << "R: /#Nombre de parametre incorrect" << endl;
            return testArgument;
        }
    }
	else if (cmdName.compare("PL") == 0)
	{
        cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        list<string>::iterator it;
        int correctArgument(0);
        for (it=argumentListTest.begin()++;it!=argumentListTest.end();it++)
        {
            int testInt(0);
            string strTest (*it);
            testInt = strtol(strTest.c_str(), NULL, 0);
            if (testInt != 0L)
            {
                correctArgument++;
            }
            else
            {
                testArgument = false;
                cerr << endl << "R: ERR" << endl << "R: /#Parametres non valides" << endl;
                return testArgument;
            }
        }
        if (correctArgument%2 == 0)
        {
            listArgument = argumentListTest;
            listArgument.push_front(cmdName);
            testArgument = true;
            list<string>::iterator temp;
            temp = listArgument.begin();
            temp++;
            nomForme.push_back (*temp);
            return testArgument;
        }
        else
        {
            testArgument = false;
            cerr << endl << "R: ERR" << endl << "R: /#Nombre de parametre incorrect" << endl;
            return testArgument;
        }
	}
	else if (cmdName.compare("OA") == 0)
	{
        cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        if (nbrArgument >= 4)
        {
            list<string>::iterator it;
            int i =0;
            for (it=argumentListTest.begin()++;it!=argumentListTest.end();it++)
            {
                list<string>::iterator itNom;
                itNom = nomForme.begin();
                while (*it != *itNom || itNom != nomForme.end())
                {
                    itNom++;
                };
                if (itNom == nomForme.end())
                {
                    testArgument = false;
                    cerr << endl << "R: ERR" << endl << "R: /#Parametres invalides" << endl;
                    return testArgument;
                }
                else
                {
                    i++;
                }
            }
            if (i==(nbrArgument-1))
            {
                listArgument = argumentListTest;
                listArgument.push_front(cmdName);
                testArgument = true;
                list<string>::iterator temp;
                temp = listArgument.begin();
                temp++;
                nomForme.push_back (*temp);
                return testArgument;
            }
        }
        else
        {
            testArgument = false;
            cerr << endl << "R: ERR" << endl << "R: /#Nombre de parametre incorrect" << endl;
            return testArgument;
        }
	}
	else if (cmdName.compare("DELETE") == 0)
	{
        cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        if (nbrArgument != 0)
        {
            list<string>::iterator it;
            int i =0;
            for (it=argumentListTest.begin()++;it!=argumentListTest.end();it++)
            {
                list<string>::iterator itNom;
                itNom = nomForme.begin();
                while (*it != *itNom || itNom != nomForme.end())
                {
                    itNom++;
                };
                if (itNom == nomForme.end())
                {
                    testArgument = false;
                    cerr << endl << "R: ERR" << endl << "R: /#Parametres invalides" << endl;
                    return testArgument;
                }
                else
                {
                    i++;
                }
            }
            if (i==nbrArgument)
            {
                listArgument = argumentListTest;
                listArgument.push_front(cmdName);
                testArgument = true;
                return testArgument;
            }
        }
        else
        {
            testArgument = false;
            cerr << endl << "R: ERR" << endl << "R: /#Nombre de parametre incorrect" << endl;
            return testArgument;
        }
	}
	else if (cmdName.compare("MOVE")==0)
	{
        cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        if (nbrArgument == 3)
        {
            list<string>::iterator it;
            it = argumentListTest.begin();
            list<string>::iterator itNom;
            itNom = nomForme.begin();
            while (*it != *itNom || itNom != nomForme.end())
            {
                itNom++;
            };
            if (itNom == nomForme.end())
            {
                testArgument = false;
                cerr << endl << "R: ERR" << endl << "R: /#Parametres invalides" << endl;
                return testArgument;
            }
            else
            {

            }
            /*if (i==nbrArgument)
            {
                listArgument = argumentListTest;
                listArgument.push_front(cmdName);
                testArgument = true;
                return testArgument;
            }*/
        }
        else
        {
            testArgument = false;
            cerr << endl << "R: ERR" << endl << "R: /#Nombre de parametre incorrect" << endl;
            return testArgument;
        }
	}
	else if ((cmdName.compare("LIST") == 0) || (cmdName.compare("UNDO") == 0) || (cmdName.compare("REDO") == 0) || (cmdName.compare("CLEAR") == 0))
	{
        cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        if (nbrArgument == 0)
        {
            listArgument = argumentListTest;
            listArgument.push_front(cmdName);
            testArgument = true;
            return testArgument;
        }
        else
        {
            testArgument = false;
            cerr << endl << "R: ERR" << endl << "R: /#Nombre de parametre incorrect" << endl;
            return testArgument;
        }
	}
	/*else if (cmdName=="LOAD")
	{
    		cmdstr.erase(0, cmdstr.find(' '));
		testArgument = argumentNumber (cmdstr);
	}
	else if (cmdName=="SAVE")
	{
    		cmdstr.erase(0, cmdstr.find(' '));
		testArgument = argumentNumber (cmdstr);
	}*/
	else
    {
        cerr << endl << "R: ERR" << endl << "R: /#Commande inconnue" << endl;
		testArgument = false;
		return testArgument;
	}

}

list<string> CommandReader::getInfos (string cmdLine, int& nbrArgument)
{
	list<string> argumentList;
	nbrArgument=0;
    	for (int i=0;i<sizeof(cmdLine);i=cmdLine.find(' ',0))
    	{
        	nbrArgument++;
        	size_t tailleArgument = cmdLine.find(' ',i);
        	char* newArgumentTemp;
        	cmdLine.copy(newArgumentTemp,tailleArgument-i,i);
            string newArgument (newArgumentTemp);
        	argumentList.push_back(newArgument);
    	}
	return argumentList;
}
