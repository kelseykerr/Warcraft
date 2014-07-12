//
//  Gold_Mine.h
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//


#ifndef PA3_Gold_Mine_h
#define PA3_Gold_Mine_h
#include "Cart_Point.h"
#include "Game_Object.h"
#include <fstream>





class Gold_Mine:public Game_Object
{
    friend class Inspector;
    
private:
    double amount;
  
    
public:
    Gold_Mine();//no arg constructor
    Gold_Mine(int inputId, Cart_Point inputLoc);//constructor
    ~Gold_Mine();
    bool is_empty();
    double dig_gold(double amount_to_dig=35.0);
    bool update();
    void show_status();
    void save(ofstream& file);
    void restore(ifstream& file);
     
    
    
};


#endif

