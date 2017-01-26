#include <iostream>
#include "Cart_Vector.h"

using namespace std;

Cart_Vector::Cart_Vector(){	//default contructor
	this -> x = 0;
	this -> y = 0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy){ //contructor that takes 2 inputs
	this -> x = inputx;
	this -> y = inputy;
}

ostream &operator << (ostream &output, Cart_Vector v1){ //overloaded contructor that adds vector notation
	output << "<" << v1.x << ", " << v1.y << ">";
	return output;
}

Cart_Vector operator * (Cart_Vector v1, double d){	//overloaded operator that multiplies a vector by a scaler
	Cart_Vector v2 = Cart_Vector((v1.x * d), (v1.y * d));

	return v2;
}

Cart_Vector operator / (Cart_Vector v1, double d){	//overloaded operator that divides a vector by a scaler
	if (d == 0)
		return v1;

	Cart_Vector v2 = Cart_Vector((v1.x / d), (v1.y / d));

	return v2;
}