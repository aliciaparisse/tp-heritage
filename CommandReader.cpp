//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
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

// Fonction renvoyant un booléen vrai si la ligne de commande entrée dans le constructeur de la classe est correcte.
// Renvoie également la liste des éléments composant la ligne de commande par référence sous forme d'une liste de strings.
bool CommandReader::readCommand (list<string> & listArgument)
{
	bool testArgument(true);
	int nbrArgument;
	list<string> argumentListTest;

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
		
		// On vérifie si le nombre de coordonnées fournies est bien paire (un X associé à un Y)
        if (correctArgument%2 == 0)
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
	else if (cmdName.compare("OA") == 0)
	{
        cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
		
		// Agrégat composé d'au minimum 2 formes, en plus du nom de l'agrégat, compter 3 arguments.
        if (nbrArgument >= 3)
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
	else if (cmdName.compare("DELETE") == 0)
	{
        cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        if (nbrArgument != 0)
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
	else if (cmdName.compare("MOVE")==0)
	{
        cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        if (nbrArgument == 3)
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
	else if (cmdName.compare("LOAD") == 0)
	{
		cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        if (nbrArgument == 1)
        {
            // Seulement les fichiers .txt pourront être chargés.
			list<string>::iterator it;
			it = argumentListTest.begin();
			string nomFichier (*it);
			string extension;
			extension = nomFichier.substr(nomFichier.size()-4,3);
			if (extension.compare("txt") == 0)
			{			
				listArgument = argumentListTest;
				listArgument.push_front(cmdName);
				testArgument = true;
				return testArgument;
			}
			else
			{
				testArgument = false;
				cerr << endl << "R: ERR" << endl << "R: /#Parametre invalide, fichier.txt attendu" << endl;
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
	else if (cmdName.compare("SAVE") == 0)
	{
		cmd.erase(0, cmd.find(' ',0));
        argumentListTest=getInfos (cmd,nbrArgument);
        if (nbrArgument == 1)
        {
            // Seulement les fichiers .txt pourront être chargés.
			list<string>::iterator it;
			it = argumentListTest.begin();
			string nomFichier (*it);
			string extension;
			extension = nomFichier.substr(nomFichier.size()-4,3);
			if (extension.compare("txt") == 0)
			{			
				listArgument = argumentListTest;
				listArgument.push_front(cmdName);
				testArgument = true;
				return testArgument;
			}
			else
			{
				testArgument = false;
				cerr << endl << "R: ERR" << endl << "R: /#Parametre invalide, fichier.txt attendu" << endl;
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
	else
    {
        cerr << endl << "R: ERR" << endl << "R: /#Commande inconnue" << endl;
		testArgument = false;
		return testArgument;
	}

}

// Fonction décomposant les éléments du string cmdLine entrée en paramètre et les renvoyant dans une liste de string.
// Compte également le nombre d'éléments composant cmdLine et le renvoie par référence.
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
