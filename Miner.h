//
//  Miner.h
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#ifndef PA3_Miner_h
#define PA3_Miner_h
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Game_Object.h"
#include <math.h>
#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>



class Miner:public Person
{
    
    friend class Model;
    
public:
    Miner(); //no arg constructor
    Miner(int in_id, Cart_Point in_loc); //constructor
    ~Miner();
    bool update();
    void start_mining(Gold_Mine* inputMine, Town_Hall* inputHome);
    void stop();
    void show_status();
    //void start_moving(Cart_Point dest);
    void save(ofstream& file);
    void restore(ifstream& file);
    int goldminepoint, townhallpoint;
    void setmine(Gold_Mine*ptr);
    void sethall(Town_Hall*ptr);
   
  
  
    
private: //private functions and objects
    double amount;
    Gold_Mine* mine;
    Town_Hall* home;
};

#endif
