//
//  Town_Hall.h
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//


#ifndef PA3_Town_Hall_h
#define PA3_Town_Hall_h
#include "Cart_Point.h"
#include "Game_Object.h"
#include <fstream>



class Town_Hall:public Game_Object
{
private:
    //char display_code;
    //int id_num;
    //char state;
    double amount;
    //Cart_Point location;
    
public:
    Town_Hall(); //no arg constructor
    Town_Hall(int inputId, Cart_Point inputLoc); //constructor
    ~Town_Hall();
    //Cart_Point get_location(); //returns location since it is private
    //int get_id();//returns id since it is private
    void deposit_gold(double deposit_amount);
    bool update();
    void show_status(); //prints status of town hall
    void save(ofstream& file);
    void restore(ifstream& file);
};


#endif
