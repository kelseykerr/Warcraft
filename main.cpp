//
//  main.cpp
//  PA5
//
//  Created by Kelsey Kerr on 11/27/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Miner.h"
#include <sstream>
#include "Game_Object.h"
#include "Person.h"
#include "View.h"
#include "Game_Command.h"
#include "Model.h"
#include "Input_Handling.h"
#include "Inspector.h"
using namespace std;


int main()
{
    Model model;
    View plot1;
    string mystr;
    char command='y';
    int id=0;
    char idnew;
    double one, two,three;
    string file;
    
    while (command !='q'){
        model.show_status();
        model.display(plot1);
        command='x';
        while (command !='g' && command != 'r'){
            bool input2=true;
            cout << "Enter command: ";
            getline (cin,mystr);
            stringstream stream(mystr);
            stream>> command;
            if (command=='m'||command=='a'||command=='w'){
                stream >> id >> one >> two;
                try {
                    if(!(id)){
                        input2=false;
                        throw Invalid_Input("Was expecting an integer");
                    }
                }
                catch (Invalid_Input& except){
                    cout << "Invalid input - " << except.msg_ptr << endl;}
            }
            else if (command=='S' || command=='R'){
                stream>>file;
            }
            else if (command=='n'){
                stream >> idnew >> one >> two >> three;
                try {
                    if (idnew!='g' && idnew!='t' && idnew!='m' && idnew!='s' && idnew!='i'){
                        input2=false;
                        throw Invalid_Input("Was expecting 'g', 't', 'm', 'i', or 's'");
                    }
                }
                catch (Invalid_Input& except){
                    cout << "Invalid input - " << except.msg_ptr << endl;}
            }
            else if (command=='i'){
                stream >> id;
                try {
                    if (!(id)){
                        input2=false;
                        throw Invalid_Input("Was expecting an integer");
                    }
                }
                catch (Invalid_Input& except){
                    cout<< "Invalid input-" << except.msg_ptr << endl;
                }
            }
            
            try
            {
                if (command=='m'&&input2==true){
                    do_move_command(model, id, one, two);
                    model.display(plot1);
                }
                else if (command=='w'&& input2==true){
                    start_mining(model, id, one, two);
                    model.display(plot1);
                }
                else if (command=='i' && input2==true){
                    Person* ptr=model.get_Person_ptr(id);
                    try{
                        if (ptr==0)
                            throw Invalid_Input("That id does not exist");
                        else{
                            inspect_command( model, id);
                            model.display(plot1);
                        }}
                    catch (Invalid_Input& except){
                        cout << "Invalid input - " << except.msg_ptr << endl;
                    }}
                else if (command=='s'){
                    stop_command(model, idnew);
                    model.display(plot1);
                }
                else if (command=='l')
                    list_command(model);
                else if (command=='a' && input2==true){
                    attack_command(model, id, one);
                    model.display(plot1);
                }
                else if (command=='g')
                    go_command(model);
                else if (command=='r')
                    run_command(model);
                
                else if (command=='q') {
                    cout << "Terminating program." << endl;
                    break;
                }
                else if (command=='S'){
                    save_command(model, file);
                    cout << "Epic game saved!"<<endl;
                    model.display(plot1);
                }
                else if (command=='R'){
                    restore_command(model, file);
                    model.display(plot1);
                }
                else if (command=='n' && input2==true){
                    if (idnew=='g'){
                        Gold_Mine * ptr=model.get_Gold_Mine_ptr(one);
                        if (ptr!=0)
                            throw Invalid_Input("that id already exists");
                        
                        else if (ptr==0){
                            model.handle_new_command('g',one,two,three);
                            model.display(plot1);
                        }
                    }
                    else if (idnew=='t'){
                        Town_Hall* ptr=model.get_Town_Hall_ptr(one);
                        
                        if (ptr!=0)
                             throw Invalid_Input("that id already exists");
                        
                        else if (ptr==0){
                            model.handle_new_command('t',one,two,three);
                            model.display(plot1);
                        }
                    }
                    else if (idnew=='s'||idnew=='m'||idnew=='i'){
                        Person* ptr=model.get_Person_ptr(one);
                      
                        if (ptr!=0)
                             throw Invalid_Input("that id already exists");
                        else if (ptr==0){
                            model.handle_new_command(idnew,one,two,three);
                            model.display(plot1);
                        }
                      
                    }
                    else
                        throw Invalid_Input(&command);
                }}
            catch (Invalid_Input& except){
                cout<< "Invalid input-" << except.msg_ptr << endl;
            }
        }
    }}


