#include <iostream>
#include <cmath>
#include "Person.h"

using namespace std;

Person::Person() : Game_Object('M', 0){ //defualt contructor that sets speed to 5 and makes game object initialize to M
	this -> speed = 5.0;
	this -> health = 5;
	cout << "Person default constructed" << endl;
}
Person::Person(char in_code) : Game_Object(in_code, 0){ //constructor that takes an incode
	this -> speed = 5.0;
	this -> health = 5;
	cout << "Person default constructed" << endl;
}
Person::Person(char in_code, int in_id, Cart_Point in_loc) : Game_Object(in_code, in_id, in_loc){ //constructor that sets the display code, id number and location of person object
	this -> speed = 5.0;
	this -> health = 5;
	cout << "Person constructed" << endl;
}
Person::~Person(){
	cout << "Person destructed" << endl;
}
bool Person::update_location(){ //determines if person is less than or equal to one step away from the destination
	double dx = destination.x - location.x;	//separates x and y components of the destination subtracted by the location
	double dy = destination.y - location.y;
	if ((fabs(dx) <= delta.x) && (fabs(dy) <= delta.y)){ //comparing x and y values of the difference with the delta
		this -> location = this -> destination;
		cout << this -> display_code << this -> get_id() << ": I'm there!" << endl;
		return true;	//returns true if it is within one step
	}
	else{
		this -> location = this -> location + this -> delta;	//return false and adds another stop if it is not within one step
		cout << this -> display_code << this -> get_id() << ": step..." << endl;
		return false;
	}

}
void Person::setup_destination(Cart_Point dest){ //sets destination and calculates step size
	this -> destination = dest;
	this -> delta = (dest - location) * (speed / cart_distance(dest, location));
}
void Person::start_moving(Cart_Point dest){ //calls the setup_destination function and sets state to 'm' which is moving
	if(is_alive()){
		setup_destination(dest);
		this -> state = 'm';
		cout << "Moving " << this -> get_id() << " to " << destination << "." << endl;
		cout << this -> display_code << this -> get_id() << ": On my way." << endl;
	}
	else
		cout << "I am dead!" << endl;
}
void Person::start_mining(){
	if (is_alive())
		cout << "Sorry, I can't work a mine." << endl;
	else 
		cout << "I am dead!" << endl;
}
void Person::stop(){	//tells person to stop
	this -> state = 's';
	cout << "Stopping " << get_id() << endl;
	cout << display_code << get_id() << ": All right." << endl;
}
void Person::show_status(){	//shows status of person related states
	switch(state){
		case 's':
			cout << "stopped." << endl;
			break;
		case 'm':
			cout << "moving at speed " << speed << " to " << destination << " at each step of " << delta << endl;
			break;
		case 'a':
			cout << "alive with health: " << this -> health << endl;
			break;
		case 'x':
			cout << "dead." << endl;
			break;
	}
}
bool Person::is_alive(){
	if(this -> state == 'x')
		return false;
	else
		return true;
}
void Person::take_hit(int attack_strength){
	this -> health -= attack_strength; //calculates health
	if(this -> health <= 0){	
		cout << "Arrggh!" << endl;
		this -> state = 'x'; //sets state to x if dead
	}
	else
		cout << "Ouch!" << endl;	//message when hit but not dead
}
void Person::start_attack(Person* target){
	if(is_alive()){
		cout << "I can't attack." << endl;
	}
	else
		cout << "I am dead!" << endl;
}







