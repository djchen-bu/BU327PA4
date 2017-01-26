#include <iostream>
#include "Miner.h"

using namespace std;

Miner::Miner() : Person('M'){ //default constructor
	this -> amount = 0.0;
	this -> mine = NULL;
	this -> home = NULL;
	cout << "Miner default constructed" << endl;
}

Miner::Miner(int in_id, Cart_Point in_loc) : Person('M', in_id, in_loc){//constructor that takes id and location
	this -> amount = 0.0;
	this -> mine = 0;
	this -> home = 0;
	cout << "Miner constructed" << endl;
}
Miner::~Miner(){ //destructor message
	cout << "Miner destructed" << endl;
}
bool Miner::update(){	
	switch(state){
		case 'm': //changes state from moving to stop if it arrrives to location
			if (update_location()){
				this -> state = 's';
				return true;
			}
			else
				return false;
			break;
		case 'o':	//outgoing state to gold mine
			if (update_location()){
				this -> state = 'g';
				return true;
			}
			else
				return false;
			break;
		case 'g':	//state at gold mine. return true after mining
			this -> amount = mine -> dig_gold();
			cout << this -> display_code << get_id() << ": Got " << this -> amount << " gold." << endl;
			setup_destination(home -> get_location()); //sets destination to townhall
			this -> state = 'i';
			return true;
			break;
		case 'i': //state for inbound gold to town hall
			if (update_location()){
				this -> state = 'd';
				return true;
			}
			else
				return false;
			break;
		case 'd':	//deposits gold into town halland sets up destination back to mine
			cout << this -> display_code << get_id() << ": Deposit " << this -> amount << " of gold." << endl;
			home -> deposit_gold(this -> amount);
			this -> amount = 0;
			if (mine -> is_empty()) {	//displays message if no more gold in mine
				this -> state = 's';
				cout << this -> display_code << get_id() << ": More work?" << endl;
				return true;
			}
			else{
				setup_destination(mine -> get_location());
				this -> state = 'o';
				cout << this -> display_code << get_id() << ": Going back for more." << endl;
				return true;
			}
			break;
	}
	return false;
}

void Miner::show_status(){ //status message for different states
	cout << "Miner status: ";
	Game_Object::show_status();
	cout << " is ";
	switch(state){
		case 's':
			cout << "stopped." << endl;
			break;
		case 'm':
			cout << "Moving at speed " << speed << " to " << destination << " at each step of " << delta << endl;
			break;
		case 'o':
			cout << "Outbound to a mine" << endl;
			break;
		case 'g':
			cout << "Getting gold from mine." << endl;
			break;
		case 'i':
			cout << "Inbound to home with load: " << amount << endl;
			break;
		case 'd':
			cout << "Depositing gold" << endl;
			break;
	}
}

void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome){
	if(is_alive()){
		mine = inputMine; //sets mine pointer
		home = inputHome; //sets home pointer
		setup_destination(mine -> get_location()); //sets up to send miner to mine again
		this -> state = 'o';
		cout << "Miner " << get_id() << " mining at Gold_Mine " << mine -> get_id() << " and despositing at Town_Hall " << home -> get_id() << "." << endl;
		cout << this -> display_code << get_id() << ": Yes, my lord." << endl;
	}
	else
		cout << "I am dead!" << endl;
}











