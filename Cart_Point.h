//
//  Cart_Point.h
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//
#ifndef Cart_Point_H
#define Cart_Point_H
#include <iostream>
#include "Cart_Vector.h"
#include <math.h>


using namespace std;

class Cart_Point
{
public:
    double x,y;
    Cart_Point();
    Cart_Point(double inputx,double inputy);
    
};

double cart_distance(Cart_Point p1, Cart_Point p2);
ostream& operator<<(ostream& out, const Cart_Point& Cart_Point);
Cart_Point operator+(Cart_Point p1, Cart_Vector v1);
Cart_Vector operator-(Cart_Point p1, Cart_Point p2);

#endif
