//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
//-----------------------------------

#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
using namespace std;

class Cercle 
{
	
	public: 
		Cercle(int x, int y,  int rayon);
		virtual	~Cercle();
		deplacer(int dx, int dy);		

	private:
		int rayon;
		Point centre; 

};

#endif


