#ifndef SOLDIER_H
#define SOLDIER_H
#include "Person.h"
#include "Cart_Point.h"

class Soldier: public Person{
private:
	int attack_strength;
	double range;
	Person* target;
public:
	Soldier();
	Soldier(int, Cart_Point);
	~Soldier();

	void start_attack(Person*);
	bool update();
	void show_status();
};
#endif