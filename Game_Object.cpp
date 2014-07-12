//
//  Game_Object.cpp
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include "Game_Object.h"



Game_Object::~Game_Object(){
    cout<<"Game_Object destructed." << endl;
}
Game_Object::Game_Object(){
   display_code=32;
    state='s';
    id_num=0;
    Cart_Point location;
    cout<< "Game_Object default constructed." << endl;
    
}

Game_Object::Game_Object(char in_code){
     display_code=in_code;
    if (display_code=='G')
        state='f';
    else if (display_code=='M')
        state='s';
    else if (display_code=='t')
        state='o';
    else if (display_code=='s' || display_code=='S')
        state='s';
    else if (display_code=='i'||display_code=='I')
        state='s';
    
    id_num=0;
    Cart_Point location;
    cout << "Game_Object constructed." << endl;
}


Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc){
    display_code=in_code;
    Game_Object::id_num=in_id;
    location=in_loc;
    if (display_code=='G')
        state='f';
    else if (display_code=='M')
        state='s';
    else if (display_code=='t')
        state='o';
    else if (display_code=='s' || display_code=='S')
        state='s';
    else if (display_code=='i'||display_code=='I')
        state='s';
   
    cout << "    Game_Object constructed." << endl;
}

Cart_Point Game_Object::get_location(){
    return location;
}


int Game_Object::get_id(){
    return id_num;
}

void Game_Object::show_status(){
    if (display_code=='M'|| display_code =='m'){
        cout << display_code << id_num << " at " << location;
    }
    else if (display_code=='G'||display_code=='g'){
        cout << "Gold_Mine "<<Game_Object::id_num<< " at location " << location;
    }
    else if (display_code=='t' || display_code=='T'){
        cout<<display_code<<id_num<< " at " << location << " contains ";
    }
    else if (display_code =='S'||display_code=='s'){
        cout<<display_code<<id_num<< " at " << location;
    }
    else if (display_code=='I' || display_code=='i'){
        cout << display_code << id_num << " at " << location;
    }
   
}

void Game_Object::drawself(char * ptr){
    if (ptr[0]=='.' || ptr[0]==' '){
        ptr[0]=Game_Object::display_code;
        int num=Game_Object::get_id();
        char numchar = (char)(((int)'0')+num);
        ptr[1]=numchar;
    }
    else{
        ptr[0]='*';
        ptr[1]=' ';
    }
}

void Game_Object::save(ofstream& file){
    file<< display_code<<"\n"<<id_num<<"\n" <<location.x << "\n" <<location.y<<"\n" << state<<endl;
}



