//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// Forme.h
//-----------------------------------

#ifndef FORME_H
#define FORME_H

using namespace std;

class Forme
{
	public:
		Forme (){}
        virtual ~Forme(){}
        virtual void deplacer(int dx, int dy){}
};

#endif
