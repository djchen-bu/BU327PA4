#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"

using namespace std;

Game_Object::Game_Object(char in_code, int in_id){	//defualt constructor
	this -> display_code = in_code;
	this -> id_num = in_id;
	this -> state = 's';
	this -> location = Cart_Point(0,0);
	cout << "Game_Object default constructed" << endl;
}
Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc){	//contructor
	this -> display_code = in_code;
	this -> id_num = in_id;
	this -> state = 's';
	this -> location = in_loc;
	cout << "Game_Object constructed" << endl;
}
Game_Object::~Game_Object(){
	cout << "Game_Object destructed" << endl;
}
void Game_Object::show_status(){ //displays status of the object code and number with location
	cout << display_code << id_num << " at " << location;
}
void Game_Object::drawself(char* ptr){
	ptr[0] = display_code;
	if(id_num >= 10)	//checks if id number is larger than 10, in which it replaces the number with '>'
		ptr[1] = (char)(62);
	else
		ptr[1] = (char)(id_num + 48);
}