//
//  Model.h
//  PA4
//
//  Created by Kelsey Kerr on 11/22/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#ifndef __PA4__Model__
#define __PA4__Model__

#include <iostream>
#include "Game_Object.h"
#include "Town_Hall.h"
#include "View.h"
#include "Miner.h"
#include "Soldier.h"
#include "Inspector.h"
#include <list>
#include <iterator>
#include <algorithm>
#include <fstream>


class Model
{
    
    friend class Gold_Mine;
    friend class Person;
    friend class Game_Object;
    friend class Inspector;
    friend class View;
    friend class Soldier;
    friend class Miner;
    friend class Town_Hall;
    
private:
    int time;
    list<Game_Object*> object_ptrs;
    list<Game_Object*> active_ptrs;
    list<Person*> person_ptrs;
    list<Gold_Mine*> mine_ptrs;
    list<Town_Hall*> hall_pts;
    
 
    
public:
    Model();
    ~Model();
    Person * get_Person_ptr(int id);
    Gold_Mine * get_Gold_Mine_ptr(int id);
    Town_Hall * get_Town_Hall_ptr(int id);
    bool update();
    void display(View &view);
    void show_status();
    void handle_new_command(char type, double idnum, double one, double two);
    list<Gold_Mine *> get_Gold_Mine_list();
    virtual void save(ofstream& file);
    virtual void restore(ifstream& file);
    void restoreMiner(ifstream&);
    void restoreSoldier(ifstream&);
    void restoreInspector(ifstream&);
    void restoreGold_Mine(ifstream&);
    void restoreTown_Hall(ifstream&);
    list<Soldier*> soldier_ptrs;
    list<Inspector*> inspector_ptrs;
     list<Miner*> miner_ptrs;
    void codefunction(ifstream&);

};

#endif /* defined(__PA4__Model__) */
