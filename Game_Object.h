//
//  Game_Object.h
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#ifndef __kelskerr_PA4__Game_Object__
#define __kelskerr_PA4__Game_Object__

#include <iostream>
#include "Cart_Point.h"
#include <fstream>



using namespace std;


class Game_Object


{
    friend class Miner;
    friend class Person;
    friend class View;
    friend class Soldier;
    friend class Model;
    friend class Town_Hall;

public:
    Game_Object();
    Game_Object(char in_code);
    Game_Object(char in_code, int in_id, Cart_Point in_loc);
    Cart_Point get_location();
    int get_id();
    void drawself(char * ptr);
    virtual bool update() =0;
    virtual void show_status();
    virtual ~Game_Object();
    virtual void save(ofstream& file);
    
protected:
    Cart_Point location;
    char display_code;
    char state;
    
private:
    int id_num;

};

#endif /* defined(__kelskerr_PA4__Game_Object__) */
