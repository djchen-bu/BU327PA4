#include <iostream>
#include "Gold_Mine.h"
#include "Cart_Point.h"

using namespace std;

Gold_Mine::Gold_Mine() : Game_Object('G', 0){ //default contructor that initilizes game object with code 'G' and a full mine of 100
	this -> state = 'f';
	this -> amount = 100;
	cout << "Gold_Mine default constructed" << endl;
}
Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc) : Game_Object('G', inputId, inputLoc){ //contructor that takes input for Id number and location of mine
	this -> state = 'f';
	this -> amount = 100;
	cout << "Gold_Mine constructed" << endl;
}
Gold_Mine::~Gold_Mine(){
	cout << "Gold_Mine destructed" << endl;
}

bool Gold_Mine::is_empty(){ //returns false if mine is not empty and true if it is empty
	if(this -> amount)
		return false;
	else
		return true;
}

double Gold_Mine::dig_gold(double amount_to_dig){ //takes amount as parameter with default value of 35
	if (this -> amount >= amount_to_dig){
		this -> amount -= amount_to_dig;
	}
	else{
		amount_to_dig = this -> amount; //if amount to dig is larger than amount in the mine, it makes the gold mine mount to zero and makes the amount to dig equal to the amount before it was set to zero
		this -> amount = 0;
	}
	return amount_to_dig;
}
bool Gold_Mine::update(){ //checks if gold mine has been depleted and returns true if it has been the first time it has been depleted and false otherwise
	if (this -> amount == 0 && state != 'e'){
		this -> state = 'e';
		this -> display_code = 'g';
		cout << "Gold_Mine " << get_id() << " has been depleted." << endl;
		return true;
	}
	else
		return false;
}
void Gold_Mine::show_status(){ //shows display code, id number, location and amount of gold in mine
	cout << "Gold Mine status: "<< this -> display_code << this -> get_id() << " at location " << Game_Object::get_location() << " Contains " << this -> amount << "." << endl;
}