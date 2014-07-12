//
//  View.cpp
//  PA4
//
//  Created by Kelsey Kerr on 11/21/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include "View.h"

bool View::get_subscripts(int &ix, int &iy, Cart_Point location){
    ix=(location.x-origin.x)/scale;
    iy=(location.y-origin.y)/scale;
    if (ix<=size&& iy<=size){
        return true;
    }
    else{
        cout << "An object is outside the display";
        return false;
    }
}

View::View(){
    size=11;
    scale=2;
    Cart_Point origin(0,0);
}

void View::clear(){
 
    for (int i=0;i<view_maxsize;i++){
        for (int j=0;j<view_maxsize;j++){
            grid[i][j][0]='.';
            grid[i][j][1]=' ';
        }
    }
}


void View::plot(Game_Object * ptr){
    int ix,iy;
    bool answer=get_subscripts(ix, iy, ptr->Game_Object::location);
    if (answer==true)
        ptr->drawself(&grid[ix][iy][0]);
}

void View::draw(){
    for (int i=(size-1);i>=0;i--){
        if (i%2==0){
            if(i<6)
                cout<<(i*scale)<< " ";
            else
                cout << (i*scale);
        }
        else
            cout << "  ";
        for (int j=0;j<size;j++){
            cout<<grid[j][i][0]<<grid[j][i][1];
        }
        cout<<endl;
    }
    
    for (int i=0;i<=size;i++){
        if (i==0)
            cout<<"  ";

        if(i%2==1){
            if(i<6)
                cout<<((i-1)*scale)<<"   ";
            else
                cout << ((i-1)*scale)<<"  ";
        }
    }
    cout << endl;
}


