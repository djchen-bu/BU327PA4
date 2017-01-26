#ifndef TOWN_HALL_H
#define TOWN_HALL_H

#include "Game_Object.h"
#include "Cart_Point.h"

class Town_Hall: public Game_Object{
private:
	double amount;
public:
	Town_Hall();
	Town_Hall(int, Cart_Point);
	~Town_Hall();

	void deposit_gold(double);
	bool update();
//	Cart_Point get_location();
	void show_status();
};


#endif