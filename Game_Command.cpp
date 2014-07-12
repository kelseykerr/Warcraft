//
//  command_functions.cpp
//  PA4
//
//  Created by Kelsey Kerr on 11/22/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include "Game_Command.h"

void do_move_command(Model& model, int id, double one, double two){
    Cart_Point dest(one, two);
    Person * ptr=model.get_Person_ptr(id);
    if (ptr==0)
        cout << "Not a valid id"<<endl;
    else
        ptr->start_moving(dest);
}

void start_mining(Model& model, int id, double one, double two)
{
    Cart_Point dest(one, two);
    Person * ptr1=model.get_Person_ptr(id);
    Gold_Mine * ptr2=model.get_Gold_Mine_ptr(one);
    Town_Hall * ptr3=model.get_Town_Hall_ptr(two);
    if (ptr1==0)
        cout << "Not a valid id"<<endl;
    else if (ptr2==0)
        cout <<"Not a valid Gold_Mine"<<endl;
    else if (ptr3==0)
        cout<<"Not a valid Town_Hall"<<endl;
    else if (ptr1 != 0 && ptr2 != 0 && ptr3 != 0)
        ptr1->start_mining(ptr2, ptr3);
}
void stop_command(Model& model, int id)
{
    Person * ptr=model.get_Person_ptr(id);
    if (ptr==0)
        cout<<"Invalid command"<<endl;
    else
        ptr->stop();
}
void go_command(Model& model){
    cout << "Advancing one tick." << endl;
    bool ans=model.update();
}
void run_command(Model& model){
    bool istrue=false;
    cout<< "Advancing to next event." << endl;
    for (int i=0;i<5;i++){
        if (istrue==false)
            istrue=model.update();
    }
}

void list_command(Model& model){
    model.show_status();
}

void attack_command(Model& model, int id, int one){
    Person * ptr1=model.get_Person_ptr(id);
    Person * ptr2=model.get_Person_ptr(one);
    if (ptr1==0||ptr2==0){
        cout << "Not a valid command."<<endl;
    }
    else
        ptr1->start_attack(ptr2);
}



void inspect_command(Model& model, int id){
    list<Gold_Mine *> mine_list=model.get_Gold_Mine_list();
    Person * ptr1=model.get_Person_ptr(id);
    ptr1->start_inspecting(mine_list);
}

void save_command(Model& model, string filename){
    ofstream file;
    file.open(filename.c_str());
    model.save(file);
    file.close();
}

void restore_command(Model& model, string filename){
    ifstream file;
    file.open(filename.c_str());
    try{
        if (file.fail())
            throw Invalid_Input("File does not exist.");
        else{
            model.~Model();
            cout<<"All objects are destoryed on DOOMS DAY!!" <<endl;
            model.restore(file);
            for (list<Miner*>::iterator i=model.miner_ptrs.begin();i!=model.miner_ptrs.end();i++){
                if((*i)->goldminepoint != -1){
                    Gold_Mine* ptr=model.get_Gold_Mine_ptr((*i)->goldminepoint);
                    if (ptr != 0){
                        (*i)->setmine(ptr);
                    }
                }
                if((*i)->townhallpoint != -1){
                    Town_Hall* ptr=model.get_Town_Hall_ptr((*i)->townhallpoint);
                    if (ptr != 0)
                        (*i)->sethall(ptr);
                }
            }
            for (list<Soldier*>::iterator i=model.soldier_ptrs.begin(); i != model.soldier_ptrs.end(); i++){
                if((*i)->persontarget != -1){
                    Person* ptr=model.get_Person_ptr((*i)->persontarget);
                    if (ptr != 0)
                        (*i)->settarget(ptr);
                }
            }
            for (list<Inspector*>:: iterator i=model.inspector_ptrs.begin();i!=model.inspector_ptrs.end();i++){
                for (int j=0;j<4;j++){
                    if((*i)->mList2[j] != j){
                        Gold_Mine* ptr=model.get_Gold_Mine_ptr((*i)->mList2[j]);
                        if (ptr != 0)
                            (*i)->minelist2.push_back(ptr);
                    }}
            }}
        file.close();
        cout << "Epic Game Restored" <<endl;
    }
    catch (Invalid_Input& except){
        cout << except.msg_ptr << endl;}
}

