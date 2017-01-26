#include <iostream>
#include "Soldier.h"

using namespace std;

Soldier::Soldier() : Person('S'){ //default constructor
	this -> attack_strength = 2;
	this -> range = 2.0;
	cout << "Soldier default constructed" << endl;
}

Soldier::Soldier(int in_id, Cart_Point in_loc) : Person('S', in_id, in_loc){//constructor that takes id and location
	this -> attack_strength = 2;
	this -> range = 2.0;
	cout << "Soldier constructed" << endl;
}
Soldier::~Soldier(){
	cout << "Soldier destructed" << endl;
}
void Soldier::start_attack(Person* in_target){
	if(is_alive()){
		if(cart_distance(in_target -> get_location(),this -> get_location()) <= range){
			cout << "Clang!" << endl;
			this -> state = 'a';
			this -> target = in_target;
		}
		else
			cout << "Target is out of range" << endl;
	}
	else
		cout << "I am dead!" << endl;
}
bool Soldier::update(){
	switch(state){
		case 'x':
		case 's':
			return false;
			break;
		case 'm': //changes state from moving to stop if it arrrives to location
			if (update_location()){
				this -> state = 's';
				return true;
			}
			else
				return false;
			break;
		case 'a':
			if(cart_distance(target -> get_location(),this -> get_location()) <= range){
				if(target -> is_alive()){
					cout << "Clang!" << endl;
					this -> target -> take_hit(attack_strength);
					return false;
				}
				else{
					cout << "I triumph!" << endl;
					this -> state = 's';
					return true;
				}
			}
			else{
				cout << "Target is out of range" << endl;
				this -> state = 's';
				return true;
			}
			break;
	}
	return false;
}
void Soldier::show_status(){
	cout << "Soldier status: ";
	Game_Object::show_status();
	cout << " is ";
	Person::show_status();
}