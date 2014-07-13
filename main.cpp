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
    View view;
    char command, idnew, id;
    string mystr, file;
    double x, y, z;
    bool input2=true;
    
    while (command != 'q' ){
        model.show_status();
        model.display(view);
        command = 'E';
        
        while (command !='r' && command != 'g'){
            try{
                cout << "Enter command: ";
                getline (cin, mystr);
                stringstream stream(mystr);
                stream >> command;
                if (command != 'm' && command != 'w' && command != 's' && command != 'g' && command != 'r' && command != 'q' && command != 'a' && command != 'l' && command != 'n' && command != 'S' && command != 'R' && command != 'i'){
                    cin.clear();
                    throw Invalid_Input ("ERROR: Please enter a valid command!");
                    
                }
                switch (command){
                    case 'm': //move
                        stream >> id >> x >> y;
                        if (id){
                            do_move_command(model, id, x, y);
                            model.display(view);
                        } else {
                            throw Invalid_Input("Was expecting an integer");
                        }
                        break;
                    case 'w': //work (i.e. mine)
                        stream >> id >> x >> y;
                        if (id){
                            start_mining(model, id, x, y);
                            model.display(view);
                        } else {
                            throw Invalid_Input("Was expecting an integer");
                        }
                        break;
                    case 's': //stop
                        stop_command(model, idnew);
                        model.display(view);
                        break;
                    case 'r': //move forward 5 ticks or until next event
                        run_command(model);
                        break;
                    case 'g': //move forward 1 time tick
                        go_command(model);
                        break;
                    case 'l':
                        list_command(model); //show all status'
                        break;
                    case'a': //attack target
                        stream >> id >> x;
                        if (id){
                            attack_command(model, id, x);
                            model.display(view);
                        } else {
                            throw Invalid_Input("Was expecting an integer");
                        }
                        break;
                    case 'i': //inspect
                        int id;
                        stream >> id;
                        if (id){
                            Person* ptr=model.get_Person_ptr(id);
                            if (ptr==0){
                                throw Invalid_Input("That id does not exist");
                            }else{
                                inspect_command( model, id);
                                model.display(view);
                            }
                        } else {
                            throw Invalid_Input("Was expecting an integer");
                        }
                        break;
                    case 'S':{ //save game
                        cin >>file;
                        save_command(model, file);
                        cout << "Epic game saved!"<<endl;
                        model.display(view);
                        break;
                    }
                    case 'R':{ //restore game
                        cin >>file;
                        restore_command(model, file);
                        model.display(view);
                        break;
                    }
                    case 'n': //create new object
                        cin >> idnew >> x >> y >> z;
                        if (idnew!='g' && idnew!='t' && idnew!='m' && idnew!='s' && idnew!='i')
                            throw Invalid_Input("Was expecting 'g', 't', 'm', 'i', or 's'");
                        if (id=='g'){
                            Gold_Mine * ptr=model.get_Gold_Mine_ptr(x);
                            if (ptr!=0){
                                throw Invalid_Input("that id already exists");
                            } else {
                                model.handle_new_command('g',x,y,z);
                            }
                            model.display(view);
                        } else if (id=='t'){
                            Town_Hall* ptr=model.get_Town_Hall_ptr(x);
                            if (ptr!=0){
                                throw Invalid_Input("that id already exists");
                            } else {
                                model.handle_new_command('t', x, y, z);
                                model.display(view);
                            }
                        } else if (id=='s'||id=='m'||id=='i'){
                            Person* ptr=model.get_Person_ptr(x);
                            if (ptr!=0){
                                throw Invalid_Input("that id already exists");
                            } else {
                                model.handle_new_command(id,x,y,z);
                                model.display(view);
                            }
                        } else {
                            throw Invalid_Input(&command);
                        }
                        break;
                    case 'q': //quit
                        cout << "Terminating program." << endl;
                        exit(0);
                }
            } catch (Invalid_Input& except){
                cout << "Invalid input - " << except.msg_ptr << endl;
            }
        }
    }
}