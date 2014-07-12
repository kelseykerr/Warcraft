//
//  command_functions.h
//  PA4
//
//  Created by Kelsey Kerr on 11/22/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#ifndef __PA4__command_functions__
#define __PA4__command_functions__

#include <iostream>
#include "Model.h"
#include "Cart_Point.h"
#include "Miner.h"
#include "Input_Handling.h"
#include <list>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <string>

void do_move_command(Model& model, int, double, double);

void start_mining(Model& model, int, double, double);
void stop_command(Model& model, int);
void go_command(Model& model);
void run_command(Model& model);
void list_command(Model& model);
void attack_command(Model& model, int id, int one);
void inspect_command(Model& model, int id);
void save_command(Model& model, string file);
void restore_command(Model& model, string file);

#endif /* defined(__PA4__command_functions__) */
