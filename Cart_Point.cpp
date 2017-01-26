#include <iostream>
#include <cmath>
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;

Cart_Point::Cart_Point(){	//default constructor
	this -> x = 0;
	this -> y = 0;
}

Cart_Point::Cart_Point(double inputx, double inputy){	//contructor for 2 inputs
	this -> x = inputx;
	this -> y = inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2){ //determines distance between two points
	double y1 = pow((p2.y - p1.y), 2);
	double x1 = pow((p2.x - p1.x), 2);
	double result = sqrt(y1 + x1);

	return result;
}

ostream &operator << (ostream &output, Cart_Point p1){	//overloaded << operator to add paranthesis
	output << "(" << p1.x << ", " << p1.y << ")";
	return output;
}

Cart_Point operator + (Cart_Point p1, Cart_Vector v1){ //overloaded operator to add a point to a vector
	Cart_Point p2 = Cart_Point((p1.x + v1.x), (p1.y + v1.y));

	return p2;
}

Cart_Vector operator - (Cart_Point p1, Cart_Point p2){	//subtracts 2 points
	Cart_Vector v1 = Cart_Vector((p1.x - p2.x), (p1.y - p2.y));

	return v1;
}
