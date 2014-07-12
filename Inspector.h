//
//  Inspector.h
//  PA5
//
//  Created by Kelsey Kerr on 11/27/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#ifndef PA5_Inspector_h
#define PA5_Inspector_h
#include <iostream>
#include "Person.h"
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>

class Inspector:public Person
{
    friend class Model;
    friend class Person;
    friend class Game_Object;
    

public:
    ~Inspector();
    Inspector();
    Inspector(int in_id, Cart_Point in_loc);
   
    bool update();
  
    void start_inspecting(list <Gold_Mine*> minelist);
    int subscript;
    vector<double> goldin;
    int goldout[4];
    vector<Cart_Point> destinations;
    Gold_Mine * get_Gold_Mine_ptr(Cart_Point loc);
    list <Gold_Mine*> minelist2;
    void show_status();
    void save(ofstream& file);
    void restore(ifstream& file);
    int mList2 [4];
    int getdestinationssize();

};

#endif
