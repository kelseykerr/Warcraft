//
//  Cart_Point.cpp
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//


#include "Cart_Point.h"


Cart_Point::Cart_Point(){
    x=0.0;
    y=0.0;
}

Cart_Point::Cart_Point(double inputx,double inputy){
    x=inputx;
    y=inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2){
    return sqrt((pow(p2.x-p1.x,2))+(pow(p2.y-p1.y,2)));
}


ostream& operator<<(ostream& out, const Cart_Point& Cart_Point){
    out<< "(" << Cart_Point.x << "," << Cart_Point.y << ")";
    return out;
}

Cart_Point operator+(Cart_Point p1, Cart_Vector v1){
    double x=p1.x+v1.x;
    double y=p1.y+v1.y;
    return Cart_Point(x,y);
}

Cart_Vector operator-(Cart_Point p1, Cart_Point p2) {
    return Cart_Vector(p1.x-p2.x, p1.y-p2.y);
}
