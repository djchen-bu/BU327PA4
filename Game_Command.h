#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H
#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Game_Object.h"
#include "Person.h"
#include "View.h"
#include "Model.h"

void do_move_command(Model&, int, double, double ,View* view);
void do_work_command(Model&, int, int, int, View*);
void do_stop_command(Model&, int ,View* );
void do_go_command(Model&, View*);
void do_run_command(Model&, View*);
void do_list_command(Model&, View*);
void do_attack_command(Model&, int, int, View*);
void do_new_command(Model&, char, int, double, double, View*);

#endif