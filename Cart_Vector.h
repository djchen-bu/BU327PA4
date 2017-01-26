#ifndef CART_VECTOR_H
#define CART_VECTOR_H

class Cart_Vector{
	public:
		double x, y;

		Cart_Vector();
		Cart_Vector(double, double);
};

std::ostream &operator << (std::ostream &, Cart_Vector);
Cart_Vector operator * (Cart_Vector, double);
Cart_Vector operator / (Cart_Vector, double);

#endif