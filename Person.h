#ifndef PERSON_H
#define PERSON_H
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

class Person: public Game_Object{ //class person is derived from game object
friend class Miner;
private:
	double speed;
	Cart_Point destination;
	Cart_Vector delta;
	int health;
protected:
	bool update_location();
	void setup_destination(Cart_Point);
public:
	Person();
	Person(char);
	Person(char, int, Cart_Point);
	virtual ~Person();

	void start_moving(Cart_Point);
	void stop();
	void show_status();
	virtual void start_mining();
	bool is_alive();
	void take_hit(int);
	virtual void start_attack(Person*);
	
};

#endif