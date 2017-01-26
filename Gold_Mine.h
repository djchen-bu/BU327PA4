#ifndef GOLD_MINE_H
#define GOLD_MINE_H
#include "Cart_Point.h"
#include "Game_Object.h"

class Gold_Mine: public Game_Object{ //class gold mine is derived from game object
private:
	double amount;
public:
	Gold_Mine();
	Gold_Mine(int, Cart_Point);
	~Gold_Mine();
	
	bool is_empty();
	double dig_gold(double amount_to_dig = 35.0); //default parameter of 35
	bool update();
	void show_status();
};

#endif