#ifndef POINT_H
#define POINT_H

using namespace std;

class Point
{

	public: 
		Point(int unX, int unY);
		virtual ~Point();

		void deplacer(int dx, int dy);


	private:
		int x;
		int y;


};

#endif
