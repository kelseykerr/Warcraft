//
//  Soldier.h
//  PA4
//
//  Created by Kelsey Kerr on 11/22/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#ifndef __PA4__Soldier__
#define __PA4__Soldier__

#include <iostream>
#include "Person.h"
#include <math.h>



class Soldier:public Person
{
public:
    ~Soldier();
    void start_attack(Person * in_target);
    bool update();
    void show_status();
    Soldier();
    Soldier(int in_id,Cart_Point in_loc);
    void save(ofstream& file);
    void restore(ifstream& file);
    int persontarget;
    void settarget(Person* ptr);
    void take_hit(int attack_strength, Person * attacker_ptr);
    
private:
    int attack_strength;
    double range;
    Person * target;
    
};
#endif /* defined(__PA4__Soldier__) */
