//-----------------------------------
// TP C++ 3 : TP H�ritage et Entr�es/Sorties
// R�alis� par : B3222 - Jean MARCHAL et Alicia PARISSE
// Point.h
//-----------------------------------


#ifndef POINT_H
#define POINT_H

#include <string>


using namespace std;

class Point
{

	public:
		Point(int& unX, int& unY);
		virtual ~Point();

		void deplacer(int& dx, int& dy);
		string getCoord ();


	private:
		int x;
		int y;


};

#endif
