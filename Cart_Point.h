#ifndef CART_POINT_H
#define CART_POINT_H

#include "Cart_Vector.h"

class Cart_Point{
	public:
		double x, y;

		Cart_Point();
		Cart_Point(double, double);
};

double cart_distance(Cart_Point, Cart_Point);
std::ostream &operator<< (std::ostream &, Cart_Point);
Cart_Point operator + (Cart_Point, Cart_Vector);
Cart_Vector operator - (Cart_Point, Cart_Point);

#endif