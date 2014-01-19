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


CommandReader::CommandReader (string commande) : cmd(commande)
{

}

CommandReader::~CommandReader ( )
{

}

// Fonction renvoyant un booléen vrai si la ligne de commande entrée dans le constructeur de la classe est correcte.
// Renvoie également la liste des éléments composant la ligne de commande par référence sous forme d'une liste de strings.
bool CommandReader::readCommand (list<string> & listArgument)
{
	bool testArgument(true);
	int nbrArgument (0);
	list<string> argumentListTest;

	size_t tailleCmdName = cmd.find(' ',0);
	string cmdName;
	if (tailleCmdName != string::npos)
    {
        cmdName = cmd.substr (0,tailleCmdName);
        cmd.erase(0,tailleCmdName+1);
        argumentListTest=getInfos (cmd,nbrArgument);
    }
    else
    {
        cmdName = cmd;
    }

    if (cmdName.compare("C") == 0)
   	{
        if (nbrArgument==4)
        {
            list<string>::iterator it;
            int correctArgument(0);
            for (it=++argumentListTest.begin();it!=argumentListTest.end();it++)
            {
                string strTest (*it);
                bool intAble = testInteger (strTest);
                if (intAble)
                {
                    ++correctArgument;
                }
                else
                {
                    testArgument = false;
                    cerr << "R: ERR" << endl << "R: #Type des parametres non valides" << endl << endl;
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
            else
            {
                testArgument = false;
                cerr << "R: ERR" << endl << "R: #Parametres incorrects" << endl << endl;
                return testArgument;
            }
        }
        else
        {
            testArgument = false;
            cerr << "R: ERR" << endl << "R: #Nombre de parametre incorrect" << endl << endl;
            return testArgument;
        }
    }
    else if ((cmdName.compare("R") == 0) || (cmdName.compare("L") == 0))
    {
        if (nbrArgument==5)
        {
            list<string>::iterator it;
            int correctArgument(0);
            for (it=++argumentListTest.begin();it!=argumentListTest.end();it++)
            {
                string strTest (*it);
                bool intAble = testInteger (strTest);
                if (intAble)
                {
                    correctArgument++;
                }
                else
                {
                    testArgument = false;
                    cerr << "R: ERR" << endl << "R: #Parametres non valides" << endl << endl;
                    return testArgument;
                }
            }
            if (correctArgument==4)
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
            cerr << "R: ERR" << endl << "R: #Nombre de parametre incorrect" << endl << endl;
            return testArgument;
        }
    }
	else if (cmdName.compare("PL") == 0)
	{
        list<string>::iterator it;
        int correctArgument(0);
        for (it=++argumentListTest.begin();it!=argumentListTest.end();it++)
        {
            string strTest (*it);
            bool intAble = testInteger (strTest);
            if (intAble)
            {
                correctArgument++;
            }
            else
            {
                testArgument = false;
                cerr << "R: ERR" << endl << "R: #Parametres non valides" << endl << endl;
                return testArgument;
            }
        }

		// On vérifie si le nombre de coordonnées fournies est bien pair (un X associé à un Y)
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
            cerr << "R: ERR" << endl << "R: #Nombre de parametre incorrect" << endl << endl;
            return testArgument;
        }
	}
	else if (cmdName.compare("OA") == 0)
	{
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
            cerr << "R: ERR" << endl << "R: #Nombre de parametre insuffisant" << endl << endl;
            return testArgument;
        }
	}
	else if (cmdName.compare("DELETE") == 0)
	{
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
            cerr << "R: ERR" << endl << "R: #Nombre de parametre incorrect" << endl << endl;
            return testArgument;
        }
	}
	else if (cmdName.compare("MOVE")==0)
	{
        if (nbrArgument == 3)
        {
            list<string>::iterator it;
            int correctArgument(0);
            for (it=++argumentListTest.begin();it!=argumentListTest.end();it++)
            {
                string strTest (*it);
                bool intAble = testInteger (strTest);
                if (intAble)
                {
                    correctArgument++;
                }
                else
                {
                    testArgument = false;
                    cerr << "R: ERR" << endl << "R: #Parametres non valides" << endl << endl;
                    return testArgument;
                }
            }
            if (correctArgument == 2)
            {
            listArgument = argumentListTest;
            listArgument.push_front(cmdName);
            testArgument = true;
            return testArgument;
            }
            else
            {
                testArgument = false;
                cerr << "R: ERR" << endl << "R: #Nombre de parametre incorrect" << endl << endl;
                return testArgument;
            }
        }
        else
        {
            testArgument = false;
            cerr << "R: ERR" << endl << "R: #Nombre de parametre incorrect" << endl << endl;
            return testArgument;
        }
	}
	else if ((cmdName.compare("LIST") == 0) || (cmdName.compare("UNDO") == 0) || (cmdName.compare("REDO") == 0) || (cmdName.compare("CLEAR") == 0))
	{
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
            cerr << "R: ERR" << endl << "R: #Aucun parametre n'est attendu ici" << endl << endl;
            return testArgument;
        }
	}
	else if (cmdName.compare("LOAD") == 0)
	{
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
				cerr << "R: ERR" << endl << "R: #Parametre invalide, fichier.txt attendu" << endl << endl;
				return testArgument;
			}
        }
        else
        {
            testArgument = false;
            cerr << "R: ERR" << endl << "R: #Nombre de parametre incorrect" << endl << endl;
            return testArgument;
        }
	}
	else if (cmdName.compare("SAVE") == 0)
	{
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
				cerr << "R: ERR" << endl << "R: #Parametre invalide, fichier.txt attendu" << endl << endl;
				return testArgument;
			}
        }
        else
        {
            testArgument = false;
            cerr << "R: ERR" << endl << "R: #Nombre de parametre incorrect" << endl << endl;
            return testArgument;
        }
	}
	else
    {
        cerr << "R: ERR" << endl << "R: #Commande inconnue" << endl << endl;
		testArgument = false;
		return testArgument;
	}

}

// Fonction décomposant les éléments du string cmdLine entrée en paramètre et les renvoyant dans une liste de string.
// Compte également le nombre d'éléments composant cmdLine et le renvoie par référence.
list<string> CommandReader::getInfos (string cmdLine, int& nbrArgument)
{
	list<string> argumentList;
	int tailleCmdLine = cmdLine.size();
	int i (0);
	bool finLigne (false);
    while (!finLigne)
    {
        nbrArgument++;
        size_t tailleArgument = cmdLine.find(' ',i);
        string newArgument;
        if (tailleArgument != string::npos)
        {
            newArgument = cmdLine.substr(i,tailleArgument-i);
            argumentList.push_back(newArgument);
            i=tailleArgument+1;
        }
        else
        {
            finLigne = true;
            newArgument = cmdLine.substr(i,tailleCmdLine-i);
            argumentList.push_back(newArgument);
        }
    }
	return argumentList;
}

bool CommandReader::testInteger (string& str)
{
    int strInt = strtol(str.c_str(),NULL,10);
    if (strInt != 0)
    {
        cout << "1" << endl;
        return true;
    }
    else
    {
        if (str.compare("0") == 0)
        {
            cout << "2" << endl;
            return true;
        }
        else
        {
            cout << "3" << endl;
            return false;
        }
    }
}
