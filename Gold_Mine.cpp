//
//  Gold_Mine.cpp
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include "Gold_Mine.h"

Gold_Mine::~Gold_Mine(){
    cout<<"Gold_Mine destructed." << endl;
}
Gold_Mine::Gold_Mine():Game_Object('g'){
    amount=100;
    cout << "Gold_Mine default constructed." << endl;
}

Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc):Game_Object('G',inputId, inputLoc){
    amount=100;
    cout << "    Gold_Mine constructed." << endl;
}

bool Gold_Mine::is_empty(){
    if (amount==0)
        return true;
    else
        return false;
}

double Gold_Mine::dig_gold(double amount_to_dig){
    if (amount>=amount_to_dig){
        amount=amount-amount_to_dig;
        return amount_to_dig;
    }
    else{
        double tempamnt=amount;
        amount=0;
        return tempamnt;
    }
}

bool Gold_Mine::update(){
    if (amount==0 && state != 'e'){
        this->state='e';
        display_code='g';
        cout << "Gold_Mine " << get_id()<< " has been depleted." << endl;
        return true;
    }
    else
        return false;
}

void Gold_Mine::show_status(){
    cout << "Gold Mine status:" ;
    Game_Object::show_status();
    cout<<" Contains " << amount << "." << endl;
}

void Gold_Mine::save(ofstream& file){
    Game_Object::save(file);
    file<<amount<<endl;
}

void Gold_Mine::restore(ifstream& file){
    file>>amount;
    
}


