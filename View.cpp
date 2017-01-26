#include <iostream>
#include "View.h"

using namespace std;

View::View(){	//default constructor setting up grid parameters
	size = 11;
	scale = 2.0;
	origin = Cart_Point();
}
void View::clear(){	//assigns field of dots for grid
	for (int x = 0; x < size; x++){
		for (int y = 0; y < size; y++){
			grid[x][y][0] = '.';
			grid[x][y][1] = ' ';
		}
	}

}
bool View::get_subscripts(int& ix, int& iy, Cart_Point location){	//determines coordinates for objects
	ix = (int)(location.x - origin.x) / scale;
	iy = (int)(location.y - origin.y) / scale;

	if (ix <= (size * scale) && iy <= (size * scale))	//returns true if within grid bounds
		return true;
	else{
		cout << "An object is outside the display" << endl;
		return false;
	}
}
void View::plot(Game_Object* ptr){
	int ix, iy = 0;
	if (get_subscripts(ix, iy, ptr -> get_location())){	//getting location for objects
		if (grid[iy][ix][0] == '.')
			ptr -> drawself(grid[iy][ix]); //assigning pointer to grid array if empty
		else{
			grid[iy][ix][0] = '*';	//showing asterisk if more than one object on point
			grid[iy][ix][1] = ' ';
		}
	}

}
void View::draw(){
	int asize = (int)(size) / 2; //calculating number of axis labels minues the zero
	int axnum = (int)(size * scale/ asize); //determining number spacing between the points
	int axis [asize + 1];	//initializing array for axis labels
	for (int i = 0; i < (asize + 1); i++) //adding axis labels into array
		axis[i] = axnum * i;

	for(int i = size - 1; i >= 0; i--){ //y axis counter
			if (i % 2 == 0){	//tests if line is good for an axis label
				if (axis[i/2] >= 10)
					cout << axis[i/2];
				else
					cout << axis[i/2] << ' ';
			}
			else
				cout << "  ";
		for (int k = 0; k < size; k++){	//outputs points from grid array
			cout << grid[i][k][0];
			cout << grid[i][k][1];
		}
		cout << "\n";
	}
	cout << "  ";
	for (int i = 0; i < asize + 1; i++){	//output lower x axis labels
		if(axis[i] >= 10)
			cout << axis[i];
		else
			cout << axis[i] << ' ';
		cout << "  ";
	}
	cout << endl;
}