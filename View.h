#ifndef VIEW_H
#define VIEW_H
#include "Cart_Point.h"
#include "Game_Object.h"

const int view_maxsize = 20;

class View{
private:
	int size;	//size of grid on display
	double scale;	//size of each dot on grid
	Cart_Point origin; 
	char grid[view_maxsize][view_maxsize][2];	//3d array
	bool get_subscripts(int& ix, int& iy, Cart_Point location); //getting location of each object
public:
	View();

	void clear();
	void plot(Game_Object* ptr);
	void draw();

};

#endif