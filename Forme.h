#ifndef FORME_H
#define FORME_H


using namesapce std;

class Forme :
{
	public:
		Forme ();
		virtual ~Forme();
		virtual void deplace(int dx, int dy)=0;
	protected:
		int nbElem;
}

#endif