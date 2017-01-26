#ifndef MODEL_H
#define MODEL_H
#include "Game_Object.h"
#include "Person.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "View.h"
#include <list>

using namespace std;

class Model{
private:
	int time;
	list <Game_Object*> object_ptrs;
	list <Game_Object*> active_ptrs;
	list <Person*> person_ptrs;
	list <Gold_Mine*> mine_ptrs;
	list <Town_Hall*> hall_ptrs;
public:
	Model();
	~Model();

	Person* get_Person_ptr(int);
	Gold_Mine* get_Gold_Mine_ptr(int);
	Town_Hall* get_Town_Hall_ptr(int);

	void handle_new_command(char, int, double, double);
	bool update();
	void display(View &view);
	void show_status();
};

#endif