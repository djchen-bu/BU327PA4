#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Cart_Point.h"

class Game_Object{
private:
	int id_num;
protected:
	Cart_Point location;
	char display_code;
	char state;
public:
	Game_Object(char, int);
	Game_Object(char, int, Cart_Point);
	virtual ~Game_Object();
	
	virtual bool is_alive(){return true;}
	virtual bool update() = 0;
	virtual Cart_Point get_location(){return location;}	//getter for location
	virtual int get_id(){return id_num;} //getter for id number
	virtual void show_status(); //virtual function since other derived classes have different show_status
	void drawself(char*);
};

#endif