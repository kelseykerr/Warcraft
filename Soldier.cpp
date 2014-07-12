//
//  Soldier.cpp
//  PA4
//
//  Created by Kelsey Kerr on 11/22/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include "Soldier.h"
#include <math.h>


Soldier::~Soldier(){
    cout<<"Soldier destructed."<<endl;
}
Soldier::Soldier():Person('S'){
    attack_strength=2;
    range=2.0;
    cout<<"Soldier defualt constructed."<<endl;
}

Soldier::Soldier(int in_id,Cart_Point in_loc):Person('S', in_id, in_loc){
    attack_strength=2;
    range=2.0;
    cout<<"    Soldier constructed."<<endl;
}

void Soldier::start_attack(Person * in_target){
    if (Soldier::state == 'x'){
        cout<<Soldier::display_code<<Soldier::id_num;
        cout <<": I am dead. You do not have the ability to summon the undead."<<endl;
    }
    if (Soldier::state!='x'){
    cout<<Soldier::display_code<<Soldier::id_num;
    target=in_target;
    Soldier::state='a';
    cout <<":Attacking." <<endl;
    }
}

bool Soldier::update(){
    switch(state){
        case 'x': return false; break;
        case 's': return false; break;
        case 'm':{
            bool ans=update_location();
            if (ans==true){
                state='s';
                return true;
            }
            else{
                state='m';
                return false;
            }
            break;
            
        }
        case 'a':{
            double distx=(target->location.x-Soldier::location.x);
            double disty=(target->location.y-Soldier::location.y);
            if (fabs(distx) <= range && fabs(disty) <= range && target->is_alive()){
                cout << Soldier::display_code<<Soldier::id_num<<":Take that!"<<endl;
                    target->take_hit(attack_strength, this);
                return false;
            }
            else if(fabs(distx) <= range && fabs(disty) <= range &&!target->is_alive()){
                        cout<<Soldier::display_code<<Soldier::id_num<<":I win."<<endl;
                        state='s';
                        return 1;
                        break;
                    }
            else{
                cout<<Soldier::display_code<<Soldier::id_num<<":Target is out of range."<<endl;
                cout<<Soldier::display_code<<Soldier::id_num<<":Chaaaaarge."<<endl;
                state='s';
                return 1;
            }
        }
             default: return false;
        }
}



void Soldier::show_status(){
    cout<<"Soldier status: ";
    Person::show_status();
}

void Soldier::save(ofstream& file){
    Person::save(file);
    file<<attack_strength<<"\n" <<range<<endl;
    if (target==NULL)
        file<<-1<<endl;
    else
        file << target->get_id()<< endl;
}

void Soldier::restore(ifstream& file){
    Person::restore(file);
    file >> attack_strength>>range>>persontarget;
}

void Soldier::settarget(Person* ptr){
    target=ptr;
}

void Soldier::take_hit(int attack_strength, Person * attacker_ptr){
    int newhealth=Soldier::gethealth()-attack_strength;
    sethealth(newhealth);
    
    if (this->gethealth()<=3){
            Person::display_code='s';
        cout<<Soldier::display_code<<Soldier::id_num<<":Ouch!"<<endl;
    }
    if (Soldier::gethealth()<=0){
        cout<<Soldier::display_code<<Soldier::id_num<<":Ahhhh, I am dying."<<endl;
        Soldier::state='x';
    }
    else if (Soldier::state!='a' || Soldier::target != attacker_ptr){
        Soldier::state='a';
        Soldier::start_attack(attacker_ptr);
    }
}

