//
//  Cart_Vector.h
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include <iostream>
#ifndef Cart_Vector_H
#define Cart_Vector_H
using namespace std;

class Cart_Vector
{
public:
    double x,y;
    Cart_Vector(); //default constructor
    Cart_Vector(double inputx, double inputy); // constructor
};

Cart_Vector operator*(const Cart_Vector& v1, double d);
Cart_Vector operator/(const Cart_Vector& v1, double d);
ostream& operator<<(ostream& out, const Cart_Vector& Cart_Vector);

#endif
