#include <iostream>
#include "Town_Hall.h"
#include "Cart_Point.h"

using namespace std;

Town_Hall::Town_Hall() : Game_Object('t', 0){ //defualt constructor 
	this -> state = 'o';
	this -> amount = 0;
	cout << "Town_Hall default constructed" << endl;
}
Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc) : Game_Object('t', inputId, inputLoc){ //constructor that takes id and location
	this -> state = 'o';
	this -> amount = 0;
	cout << "Town_Hall constructed" << endl;
}
Town_Hall::~Town_Hall(){
	cout << "Town_Hall destructed" << endl;
}

bool Town_Hall::update(){
	if (amount >= 50 && state != 'u'){	//only outputs upgraded message when it is first upgraded
		state = 'u';
		display_code = 'T';
		cout << "Town_Hall " << this -> get_id() << " has been upgraded" << endl;
		return true;
	}
	else
		return false;
}

void Town_Hall::show_status(){ //shows display and id codes, location and number of gold in town. Also displays if it is upgraded or not
	cout << "Town Hall Status: " << display_code << this -> get_id() << " at " << Game_Object::get_location() << " contains " << amount << " of gold.";
	if(state == 'u')
		cout << " Upgraded." << endl;
	else
		cout << " Not yet upgraded." << endl;
}

void Town_Hall::deposit_gold(double deposit_amount){ //adds gold to town hall amount
	this -> amount += deposit_amount;
}