//
//  Person.h
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#ifndef __kelskerr_PA4__Person__
#define __kelskerr_PA4__Person__

#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include <list>
#include <iterator>
#include <algorithm>
#include <fstream>

class Person: public Game_Object
{
    friend class Model;
    
public:
    Person();
    Person(char in_code);
    Person(char in_code, int in_id, Cart_Point in_loc);
    ~Person();
    void start_moving(Cart_Point dest);
    void stop();
    void show_status();
    void setstate(char state);
    virtual void start_mining(Gold_Mine* inputMine, Town_Hall* inputHome);
    bool is_alive();
    virtual void take_hit(int attack_strenth, Person * attacker_ptr);
    virtual void start_attack(Person * target);
    virtual void start_inspecting(list <Gold_Mine*> minelist);
    Gold_Mine* locationptr(Cart_Point loc);
    Gold_Mine * get_Gold_Mine_ptrs(Cart_Point loc);
    virtual void save(ofstream& file);
    virtual void restore(ifstream& file);
    int gethealth();
    void sethealth(int newhealth);
    
    
protected:
    bool update_location();
    void setup_destination(Cart_Point dest);
private:
    double speed;
    Cart_Point destination;
    Cart_Vector delta;
    int health;
    };

#endif /* defined(__kelskerr_PA4__Person__) */
