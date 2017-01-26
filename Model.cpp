#include <iostream>
#include <algorithm>
#include <iterator>
#include "Model.h"
#include "Game_Object.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "View.h"
#include "Soldier.h"

using namespace std;

Model::Model(){ //default constructor
	time = 0;	//initializing time to zero

	person_ptrs.push_back(new Miner(1,Cart_Point(5, 1)));
	person_ptrs.push_back(new Miner(2, Cart_Point(10, 1)));
	person_ptrs.push_back(new Soldier(3, Cart_Point(5, 15)));
	person_ptrs.push_back(new Soldier (4, Cart_Point(10, 15)));

	mine_ptrs.push_back(new Gold_Mine(1, Cart_Point(10, 20)));
	mine_ptrs.push_back(new Gold_Mine(2, Cart_Point(1, 20)));

	hall_ptrs.push_back(new Town_Hall(1, Cart_Point(0, 0)));

	for (list<Person*>::iterator i = person_ptrs.begin(); i != person_ptrs.end(); i++) //copying pointer onto object pointer list
		object_ptrs.push_back(*i);
	for (list<Gold_Mine*>::iterator i = mine_ptrs.begin(); i != mine_ptrs.end(); i++)
		object_ptrs.push_back(*i);
	for (list<Town_Hall*>::iterator i = hall_ptrs.begin(); i != hall_ptrs.end(); i++)
		object_ptrs.push_back(*i);

	active_ptrs = object_ptrs; //copying object pointer list to the active pointer list
	cout << "Model default constructed" << endl;
}
Model::~Model(){	//destructor that deallocates space from all objects
	for (list<Game_Object*>::iterator i = object_ptrs.begin(); i != object_ptrs.end(); i++)
		delete *i;
	cout << "Model destructed" << endl;
}
Person* Model::get_Person_ptr(int id){	//checks if person pointer is valid
	if(id > person_ptrs.size() || id < 0)
		throw id;
	list<Person*>::iterator i = person_ptrs.begin();
	advance(i,id - 1);
	return *i;
}
Gold_Mine* Model::get_Gold_Mine_ptr(int id){ //checks if gold mine pointer is valid
	if(id > mine_ptrs.size() || id < 0)
		throw id;
	list<Gold_Mine*>::iterator i = mine_ptrs.begin();
	advance(i,id - 1);
	return *i;
}
Town_Hall* Model::get_Town_Hall_ptr(int id){ //checks if town hall pointer is valid
	if(id > hall_ptrs.size() || id < 0)
		throw id;
	list<Town_Hall*>::iterator i = hall_ptrs.begin();
	advance(i,id - 1);
	return *i;
}
void Model::handle_new_command(char type, int ID, double x, double y){ //makes a new object
	switch(type){
		case 'g':
			for(list<Gold_Mine*>::iterator i = mine_ptrs.begin(); i != mine_ptrs.end(); i++){	//iterates through pointer lists to compare ID numbers
				if((*i) -> get_id() == ID)
					throw ID;
			}
			mine_ptrs.push_back(new Gold_Mine(ID, Cart_Point(x, y)));
			object_ptrs.push_back(mine_ptrs.back());	//puts new object into object, active and the respective pointer lists
			active_ptrs.push_back(mine_ptrs.back());
			break;
		case 't':
		for(list<Town_Hall*>::iterator i = hall_ptrs.begin(); i != hall_ptrs.end(); i++){
				if((*i) -> get_id() == ID)
					throw ID;
			}
			hall_ptrs.push_back(new Town_Hall(ID, Cart_Point(x, y)));
			object_ptrs.push_back(hall_ptrs.back());
			active_ptrs.push_back(hall_ptrs.back());
			break;
		case 'm':
		for(list<Person*>::iterator i = person_ptrs.begin(); i != person_ptrs.end(); i++){
				if((*i) -> get_id() == ID)
					throw ID;
			}
			person_ptrs.push_back(new Miner(ID,Cart_Point(x, y)));
			object_ptrs.push_back(person_ptrs.back());
			active_ptrs.push_back(person_ptrs.back());
			break;
		case 's':
		for(list<Person*>::iterator i = person_ptrs.begin(); i != person_ptrs.end(); i++){
				if((*i) -> get_id() == ID)
					throw ID;
			}
			person_ptrs.push_back(new Soldier(ID, Cart_Point(x, y)));
			object_ptrs.push_back(person_ptrs.back());
			active_ptrs.push_back(person_ptrs.back());
			break;
		default:
			throw type;	//throwing the type if letter doesn't match the rest
			break;	
	}

}
bool Model::update(){	//updates time and returns true if update function from any object returns true
	time++;
	bool check = false;
	for (list<Game_Object*>::iterator i = active_ptrs.begin(); i != active_ptrs.end(); i++){
		if((*i) -> update()){
			cout << "Time: " << time << endl;
			check = true;
		}
	}
	for (list<Game_Object*>::iterator i = active_ptrs.begin(); i != active_ptrs.end(); i++){//checks for dead objects and removes them from active pointer list
		if(!(*i) -> is_alive()){
			i = active_ptrs.erase(i);
			cout << "Dead object removed" << endl;
		}
	}
	return check;
}
void Model::display(View &view){	//clears display and plots points from grid array
	view.clear();

	for(list<Game_Object*>::iterator i = active_ptrs.begin(); i != active_ptrs.end(); i++)	//sets up values
		view.plot(*i);

	view.draw();	//prints grid
}
void Model::show_status(){	//show status and time of objects
	for (list<Game_Object*>::iterator i = object_ptrs.begin(); i != object_ptrs.end(); i++)
		(*i) -> show_status();
}