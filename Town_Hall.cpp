//
//  Town_Hall.cpp
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include "Town_Hall.h"

Town_Hall::~Town_Hall(){
    cout<<"Town_Hall destructed." << endl;
}

Town_Hall::Town_Hall():Game_Object('t'){
    amount=0;
    cout << "Town_Hall default constructed." << endl;
}

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc):Game_Object('t',inputId, inputLoc){
    amount=0;
    cout << "    Town_Hall constructed." << endl;
}


void Town_Hall::deposit_gold(double deposit_amount){
    amount=amount+deposit_amount;
}

bool Town_Hall::update(){
    if (amount>=50 && state !='u'){
        this->state='u';
        Game_Object::display_code='T';
        cout << Game_Object::display_code << get_id() << " has been upgraded." << endl;
        return true;
    }
    else
        return false;
}

void Town_Hall::show_status() {
    if (Game_Object::display_code=='t'){
        cout<< "Town_Hall status: ";
        Game_Object::show_status();
        cout << amount << " of gold." << "   Not yet upgraded" << endl;}
    else if (Game_Object::display_code=='T'){
        cout<< "Town_Hall status:";
        Game_Object::show_status();
        cout<< amount << " of gold." << endl<< "   Upgraded" << endl;}
}

void Town_Hall::save(ofstream& file){
    Game_Object::save(file);
    file<<amount<<endl;
}

void Town_Hall::restore(ifstream& file){
    file >> amount;
}
