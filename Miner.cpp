//
//  Miner.cpp
//  kelskerr_PA4
//
//  Created by Kelsey Kerr on 11/20/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include "Miner.h"


Miner::~Miner(){
    cout<<"Miner destructed." << endl;
}

Miner::Miner():Person('M'){
    amount=0;
    mine=NULL;
    home=NULL;
    cout<< "Miner default constructed" << endl;
}
Miner::Miner(int in_id, Cart_Point in_loc):Person('M',in_id, in_loc){
    amount=0;
    mine=NULL;
    home=NULL;
    cout<< "    Miner constructed." << endl;
}


bool Miner::update(){
    switch (state){
        case 's':{
            state='s';
            return false;
            break;
        }
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
        case 'o':{
            bool ans=update_location();
            if (ans==true){
                state='g';
                return true;
            }
            else{
                state='o';
                return false;
            }
            break;
        }
        case 'g':{
            amount=mine->dig_gold();
            cout << display_code<< get_id()<< ": Got " << amount << " gold." << endl;
            setup_destination(home->get_location());
            state='i';
            return true;
            break;
        }
        case 'i':{
            bool ans=update_location();
            if (ans==true){
                state='d';
                return true;
            }
            else{
                state='i';
                return false;
            }
            break;
        }
        case 'd':{
            cout << display_code << get_id() << ": Deposit " << amount << " of gold." << endl;
            home->deposit_gold(amount);
            amount=0;//print out deposit amount
            
            if (mine->is_empty()==true){
                state='s';
                cout<< display_code << get_id() << ": More work?" << endl;
                return true;//stop miner and ask for more work
            }
            else{
                setup_destination(mine->get_location());//setup new destination
                state='o';
                cout << display_code<< get_id() << ": Going back for more." << endl;
                return true;
            }
            break;
        }
        case 'x':{
            return false;
        }
        default: return false;
    }
}

void Miner::show_status(){
    cout << "Miner status:";
    Person::show_status();
    if (state=='i')
        cout<<amount<< endl;
}

void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome){
    if (Miner::state == 'x'){
        cout<<Miner::display_code<<Miner::id_num<<": I am dead. Are you kidding me? Ask a zombie to work!?!?"<<endl;
    }
    else{
    mine=inputMine;//set up location
    home=inputHome;
    setup_destination(mine->get_location()); //set up new destination
    setstate('o'); //set new state
    cout<< "Miner " << get_id() << " is mining at Gold_Mine " << inputMine->get_id() << " and depositing at Town_Hall " << inputHome->get_id() << "." << endl;
    cout << display_code << get_id() << ": Yes, my lord."<< endl;
    }
}

void Miner::save(ofstream& file){
    Person::save(file);
    file<< amount<< endl;
    if (mine==NULL)
        file<<-1<<endl;
    else
        file<<mine->get_id() <<endl;
    if (home==NULL)
        file<<-1<<endl;
    else
        file<<home->get_id()<<endl;
}

void Miner::restore(ifstream& file){
    Person::restore(file);
    file >>amount>>goldminepoint>>townhallpoint;
}


void Miner::setmine(Gold_Mine *ptr){
    this->mine=ptr;
}

void Miner::sethall(Town_Hall *ptr){
    this->home=ptr;
}

