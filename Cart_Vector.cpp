//
//  Cart_Vector.cpp
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include <iostream>
#include "Cart_Vector.h"
using namespace std;

Cart_Vector::Cart_Vector(){
    x=0.0;
    y=0.0;
}
Cart_Vector::Cart_Vector(double inputx, double inputy){
    x=inputx;
    y=inputy;
}

Cart_Vector operator*(const Cart_Vector& v1, double d){
    return Cart_Vector(v1.x*d, v1.y*d);
}

Cart_Vector operator/(const Cart_Vector& v1, double d){
    return Cart_Vector(v1.x/d, v1.y/d);
}

ostream& operator<<(ostream& out, const Cart_Vector& Cart_Vector){
    out<< "<" << Cart_Vector.x << "," << Cart_Vector.y << ">"<< endl;
    return out;
}
