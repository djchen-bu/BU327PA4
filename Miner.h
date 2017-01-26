#ifndef MINER_H
#define MINER_H
#include "Person.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

class Miner: public Person{
private:
	double amount;
	Gold_Mine* mine;
	Town_Hall* home;
public:
	Miner();
	Miner(int, Cart_Point);
	~Miner();

	bool update();
	void start_mining(Gold_Mine* inputMine, Town_Hall* inputHome);
	void show_status();
};

#endif