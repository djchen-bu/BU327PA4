#include <iostream>
#include "Game_Command.h"
#include "Input_Handling.h"

using namespace std;

void do_move_command(Model& model, int ID, double x, double y, View* view){ //starts moving person object towards location
	Cart_Point cmove(x, y);
	try{
		(model.get_Person_ptr(ID)) -> start_moving(cmove);
	}
	catch(int ID){
		throw ID;
	}
	model.display(*view);
}
void do_work_command(Model& model, int ID1, int ID2, int ID3, View* view){ //starts mining at mine and sets destination to townhall pointer
	try{
		Person* pminer = model.get_Person_ptr(ID1);

		static_cast <Miner*>(pminer) -> start_mining((model.get_Gold_Mine_ptr(ID2)), (model.get_Town_Hall_ptr(ID3)));
	}
	catch(int ID){
		throw ID;
	}
	model.display(*view);
}
void do_stop_command(Model& model, int ID, View* view ){ //stops command
	try{
		(model.get_Person_ptr(ID)) -> stop();
	}
	catch(int ID){
		throw ID;
	}
	model.display(*view);
}
void do_go_command(Model& model, View* view){//advances time one tick
	cout << "Advancing one tick." << endl;
	model.update();
	model.show_status();
	model.display(*view);
}
void do_run_command(Model& model, View* view){ //advances time until an event happens
	cout << "Advancing to next event" << endl;
	int i = 0;
	while(!model.update() && i < 5){
		i++;
	}
	model.show_status();
	model.display(*view);
}
void do_list_command(Model& model, View* view){	 //shows show_status command for all objects
	model.show_status();
	model.display(*view);
}
void do_attack_command(Model& model, int ID1, int ID2, View* view){
	try{
		model.get_Person_ptr(ID1) -> start_attack(model.get_Person_ptr(ID2));
	}
	catch(int ID){
		throw ID;
	}
	model.update();
	model.display(*view);
}
void do_new_command(Model& model, char type, int ID, double x, double y, View* view){
	try{
		model.handle_new_command(type, ID, x, y);
	}
	catch(char type){
		throw type;
	}
	catch(int ID){
		throw ID;
	}

	model.update();
	model.display(*view);
}


























