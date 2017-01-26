#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "View.h"
#include "Model.h"
#include "Game_Command.h"
#include "Input_Handling.h"

using namespace std;

int main(){

	cout << "EC327: Programming Assignment 4 -- Fall 2016" << endl;
	Model model;	//initializes model class
	View view;		//initiallizes view class

	bool loop = true;
	do_list_command(model, &view);	//shows show status of all objects and time

	while(true){	//loops until quit command
		char input;
		cout << "\nEnter command: ";
		cin >> input;
		try{
			switch(input){
				case 'm':	//starts move command
					int mID;
					double x, y;

					cin >> mID;
					if (cin.fail()){
						cin.clear();
						cin.ignore();
						throw Invalid_Input("not an integer");
					}
					cin >> x >> y;
					if (cin.fail()){
						cin.clear();
						cin.ignore();
						throw Invalid_Input("not a double");
					}
					try{
						do_move_command(model, mID, x, y, &view);
					}
					catch(int id){
						throw Invalid_Input("not a valid ID");
					}
					catch(double x){
						throw Invalid_Input("not a valid location");
					}
					break;
				case 'w':	//code starts work command
					int ID1, ID2, ID3;

					if(!(cin >> ID1 >> ID2 >> ID3)){
						cin.clear();
						cin.ignore();
						throw Invalid_Input("not an integer");
					}
					try{
						do_work_command(model, ID1, ID2, ID3, &view);
					}
					catch(int id){
						throw Invalid_Input("not a valid ID");
					}
					break;
				case 's':	//code stops object movement
					int sID;

					if(!(cin >> sID)){
						cin.clear();
						cin.ignore();
						throw Invalid_Input("not an integer");
					}
					try{
						do_stop_command(model, sID, &view);
					}
					catch(int id){
						throw Invalid_Input("not a valid ID");
					}
					break;
				case 'a':
					int aID1, aID2;

					if(!(cin >> aID1 >> aID2)){ //error checking for valid ID numbers
						cin.clear();
						cin.ignore();
						throw Invalid_Input("not an integer");
					}
					try{
						do_attack_command(model, aID1, aID2, &view);
					}
					catch(int id){
						throw Invalid_Input("not a valid ID");
					}
					break;
				case 'n': //new object creation command
					char type;
					int nID;
					double nx, ny;

					if(!(cin >> type)){
						cin.clear();
						cin.ignore();
						throw Invalid_Input("not a character");
					}
					if(!(cin >> nID)){
						cin.clear();
						cin.ignore();
						throw Invalid_Input("not an integer");
					}
					if(!(cin >> nx >> ny)){
						cin.clear();
						cin.ignore();
						throw Invalid_Input("not a double");
					}
					try{
						do_new_command(model, type, nID, nx, ny, &view);
					}
					catch(char type){
						throw Invalid_Input("not a valid type");
					}
					catch(int nID){
						throw Invalid_Input("ID already taken or invalid");
					}
					catch(double nx){
						throw Invalid_Input("not a valid location");
					}
					break;
				case 'g':	//code advances one tick in time
					do_go_command(model, &view);
					break;
				case 'r': //runs command until event change
					do_run_command(model, &view);
					break;
				case 'l': //command shows show status command for all objects
					do_list_command(model, &view);
					break;
				case 'q':	//quitting program
					cout << "Terminating program." << endl;
					return false;
					break;
				default:
					throw Invalid_Input("not a valid command");
					break;
			}
		}
		catch (Invalid_Input& except){
			cout << "Invalid input - " << except.msg_ptr << endl; // actions to be taken if the input is wrong
		}
	}
	return 0;
}