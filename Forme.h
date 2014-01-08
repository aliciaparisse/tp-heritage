//-----------------------------------
// TP C++ 3 : TP Héritage et Entrées/Sorties
// Réalisé par : B3222 - Jean MARCHAL et Alicia PARISSE
// Forme.h
//-----------------------------------


#ifndef FORME_H
#define FORME_H


using namespace std;

class Forme :
{
	public:
		Forme ();
		virtual ~Forme();
		virtual void deplace(int dx, int dy)=0;
}

#endif
