//
//  View.h
//  PA4
//
//  Created by Kelsey Kerr on 11/21/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#ifndef __PA4__View__
#define __PA4__View__

#include <iostream>
#include "Game_Object.h"
#include <iomanip> 
const int view_maxsize=20;
class View
{
public:
    View();
    void clear();
    void plot(Game_Object * ptr);
    void draw();
    
private:
    int size;
    double scale;
    Cart_Point origin;
    char grid[view_maxsize][view_maxsize][2];
    bool get_subscripts(int &ix, int &iy, Cart_Point location);
};

#endif /* defined(__PA4__View__) */
