//
//  Person.cpp
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include "Person.h"

Person::~Person(){
    cout<<"Person destructed." << endl;
}
Person::Person():Game_Object(){
    speed=5;
    health=5;
    cout << "Person default constructed." << endl;
}
Person::Person(char in_code):Game_Object(in_code){
    speed=5;
    health=5;
    cout << "    Person constructed." << endl;

}

Person::Person(char in_code, int in_id, Cart_Point in_loc):Game_Object(in_code,in_id,in_loc){
    health=5;
    speed=5;
    cout << "    Person constructed." << endl;
    
}

void Person::start_moving(Cart_Point dest) {
    if (Person::state =='x'){
        cout<<Person::display_code<<Person::id_num<<": I am dead. I may move but you just cannot see me."<<endl;
    }
    
    if (Person::state!='x'){
        state='m';
    cout << "Moving " << get_id() << " to " << dest<< endl;
    cout << display_code << get_id()<< ": On my way." << endl;
        setup_destination(dest);
    }
}

void Person::stop(){
    state='s';
    cout << "Stopping (" << get_id() << ")."<< endl;
    cout << "(" << display_code << ")(" << get_id() << "): All right." << endl;
}

void Person::show_status(){
    Game_Object::show_status();
    if (state=='m'){
        cout << " moving at speed of "<< speed << " towards " << destination << " at each step of " << delta;
    }
    if (health>0){
        switch (state){
        case 's': cout << endl; cout <<"   Stopped." << endl;break;
        case 'm': cout << "    Moving at speed." << endl;break;
        case 'o': cout << "\n"<<"    Outbound to a mine."<< endl; break;
        case 'g': cout << "\n"<<"    Geting gold from mine." << endl; break;
        case 'i': cout <<"\n"<<"    Inbound to home with load: ";break;
        case 'd': cout << "\n"<<"    Depositing gold."<< endl;break;
        case 'a': cout<<"\n"<<"    Attacking."<<endl;break;
        case 'k': cout<< "\n" << "    Outbound Inspecting" <<endl;break;
        case 'c': cout << "\n" << "    Doing outbound inspection" <<endl;break;
        case 'l': cout << "\n"<<"    Doing inbound inspection"<<endl;break;
        case 'j': cout << "\n" <<"    Inbound Inspecting"<<endl;break;
        }}
    else{
        cout << " is dead."<< endl;
    }
}

bool Person::update_location(){
    double ans1= fabs(destination.x-location.x);
    double ans2=fabs(destination.y-location.y);
    if (ans1<= fabs(delta.x) && ans2<= fabs(delta.y)){
        location=destination;
        cout<< display_code<< get_id()<< ": I'm there!" << endl;
        return true;
    }
    else{
        location=location+delta;
        cout << display_code << get_id()<<": step..." << endl;
        return false;
    }
}

void Person::setup_destination(Cart_Point dest){
    destination=dest;
    delta=(destination-location)*(speed/cart_distance(destination,location));
    
}

void Person::setstate(char state){
    this->state=state;
}

void Person::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome){
    cout<<Person::display_code<<Person::id_num<<":Sorry, I can't work a mine."<<endl;
}

bool Person::is_alive(){
    if(Person::state=='x')
        return false;
    else
        return true;
}

void Person::take_hit(int attack_strength, Person * attacker_ptr){
    Person::health=Person::health-attack_strength;
    if (Person::health<=3){
        if (Person::display_code=='M')
            Person::display_code='m';
        else if (Person::display_code=='I')
            Person::display_code='i';
    }
    if (Person::health<=0){
        cout<<Person::display_code<<Person::id_num<<":Ahhhh, I am dying."<<endl;
        Person::state='x';
    }
    else{
        cout<< Person::display_code<< Person::id_num<<":Ouch!"<<endl;
        cout<< Person::display_code<< Person::id_num<<":I don't wanna fight!"<<endl;
        Cart_Point loc(Person::location.x-(attacker_ptr->location.x), Person::location.y-(attacker_ptr->location.y));
        Cart_Point newloc((loc.x*1.5+Person::location.x), (loc.y*1.5+Person::location.y));
        Person::start_moving(newloc);
    }
}

void Person::start_attack(Person *target){
    cout<<Person::display_code<<Person::id_num<<":";
    cout << "I can't attack."<<endl;
}

void Person::start_inspecting(list <Gold_Mine*> minelist){
    cout <<"Sorry, I can't inspect"<<endl;
}

void Person::save(ofstream& file){
    Game_Object::save(file);
    file << speed << "\n" << destination.x << "\n" << destination.y << "\n" << delta.x << "\n" << delta.y << "\n" << health << endl;
}

void Person::restore(ifstream& file){
    file>>speed>>destination.x>>destination.y>>delta.x>>delta.y>>health;
}

int Person::gethealth(){
    return health;
}

void Person::sethealth(int newhealth){
    this->health=newhealth;
}



