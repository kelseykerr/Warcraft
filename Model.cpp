//
//  Model.cpp
//  PA4
//
//  Created by Kelsey Kerr on 11/22/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include "Model.h"

Model::Model()
{
    time=0;
    Cart_Point a(5,1);
    Miner* M1=new Miner(1,a);
    object_ptrs.push_back(M1);
    active_ptrs.push_back(M1);
    person_ptrs.push_back(M1);
    Cart_Point b(10,1);
    Miner* M2=new Miner(2,b);
    object_ptrs.push_back(M2);
    active_ptrs.push_back(M2);
    person_ptrs.push_back(M2);
    Cart_Point e(5,15);
    Soldier* S3=new Soldier(3,e);
    object_ptrs.push_back(S3);
    active_ptrs.push_back(S3);
    person_ptrs.push_back(S3);
    Cart_Point f(10,15);
    Soldier* S4=new Soldier(4,f);
    object_ptrs.push_back(S4);
    active_ptrs.push_back(S4);
    person_ptrs.push_back(S4);
    Cart_Point h(5,5);
    Inspector* I5=new Inspector(5,h);
    object_ptrs.push_back(I5);
    active_ptrs.push_back(I5);
    person_ptrs.push_back(I5);
    Cart_Point c(1,20);
    Gold_Mine* G1=new Gold_Mine(1,c);
    object_ptrs.push_back(G1);
    active_ptrs.push_back(G1);
    mine_ptrs.push_back(G1);
    Cart_Point d(10,20);
    Gold_Mine* G2=new Gold_Mine(2,d);
    object_ptrs.push_back(G2);
    active_ptrs.push_back(G2);
    mine_ptrs.push_back(G2);
    Cart_Point g(0,0);
    Town_Hall* t1=new Town_Hall(1,g);
    object_ptrs.push_back(t1);
    active_ptrs.push_back(t1);
    hall_pts.push_back(t1);
    
    
    
    
    cout<< "Model default constructed"<<endl;
}

Model::~Model(){
    hall_pts.clear();
    mine_ptrs.clear();
    person_ptrs.clear();
    active_ptrs.clear();
    object_ptrs.clear();
    
    cout<< "    Model destructed" << endl;
}


Person *Model::get_Person_ptr(int id){
    for (list<Person*>::iterator i=person_ptrs.begin();i!=person_ptrs.end();i++){
        if ((*i)->id_num == id)
            return *i;
    }
    return 0;
}



Gold_Mine *Model::get_Gold_Mine_ptr(int id){
    for (list<Gold_Mine*>::iterator i=mine_ptrs.begin();i!=mine_ptrs.end();i++){
        if ((*i)->id_num == id)
            return *i;
    }
    return 0;
}

Town_Hall *Model::get_Town_Hall_ptr(int id){
    for (list<Town_Hall*>::iterator i=hall_pts.begin();i!=hall_pts.end();i++){
        if ((*i)->id_num == id)
            return *i;
    }
    return 0;
}

bool Model::update(){
    bool answer;
    int count=0;
    time=time+1;
    
    for (list<Game_Object*>::iterator i=active_ptrs.begin();i!=active_ptrs.end();i++){
        answer=(*i)->update();
        if ((*i)->state == 'x'){
           i= active_ptrs.erase(i);
            cout << "Dead object removed" <<endl;
        }
        if (answer==true)
            count++;
    }
    if (count>0)
        return true;
    return false;
}

void Model::display(View & view){
    view.clear();
    for (list<Game_Object*>::iterator i=active_ptrs.begin();i!=active_ptrs.end();i++){
        view.plot((*i));
    }
    view.draw();
}

void Model::show_status(){
    cout<< "Time: " << time<<endl;;
    for (list<Game_Object*>::const_iterator iterator = object_ptrs.begin(), end = object_ptrs.end(); iterator != end; ++iterator){
        (*iterator)->show_status();
    }
}

void Model::handle_new_command(char type, double idnum, double one, double two){
    Cart_Point a(one, two);
    if (type=='g'){
        Gold_Mine* G_one=new Gold_Mine(idnum,a);
        object_ptrs.push_back(G_one);
        active_ptrs.push_back(G_one);
        mine_ptrs.push_back(G_one);
    }
    else if (type=='t'){
        Town_Hall* T_one=new Town_Hall(idnum,a);
        object_ptrs.push_back(T_one);
        active_ptrs.push_back(T_one);
        hall_pts.push_back(T_one);
    }
    else if (type=='s'){
        Soldier* S_one=new Soldier(idnum,a);
        object_ptrs.push_back(S_one);
        active_ptrs.push_back(S_one);
        person_ptrs.push_back(S_one);
    }
    else if (type=='m'){
        Miner* M_one=new Miner(idnum,a);
        object_ptrs.push_back(M_one);
        active_ptrs.push_back(M_one);
        person_ptrs.push_back(M_one);
    }
    else if (type=='i'){
        Inspector* I_one=new Inspector(idnum,a);
        object_ptrs.push_back(I_one);
        active_ptrs.push_back(I_one);
        person_ptrs.push_back(I_one);
    }
}

list<Gold_Mine *> Model::get_Gold_Mine_list(){
    return mine_ptrs;
}

void Model::save(ofstream& file){
    file<<time<< "\n" << object_ptrs.size() << endl;
    for (list<Game_Object*>::const_iterator i = active_ptrs.begin(), end = active_ptrs.end(); i != end; i++){
        file<<(*i)->display_code<< (*i)->id_num<<endl;
    }
    for (list<Game_Object*>::const_iterator i = active_ptrs.begin(), end = active_ptrs.end(); i != end; i++){
        (*i)->save(file);
    }
}

void Model::restore(ifstream& file){
    int numobjects;
    char code;
    file >> time>>numobjects;
    for (int line_num=0;line_num<(numobjects*2);line_num++){
        file>>code;
    }
    while(!file.eof()){
        codefunction(file);
    }
    
    
}

void Model::codefunction(ifstream& file){
    char code='x';
    int id;
    double locX;
    double locY;
    char code2;
        file>>code>>id>>locX>>locY>>code2;
        Cart_Point a(locX, locY);
        if (code=='M' || code=='m'){
            Miner* M1=new Miner(id,a);
            M1->state=code2;
            M1->display_code=code;
            M1->restore(file);
            object_ptrs.push_back(M1);
            active_ptrs.push_back(M1);
            person_ptrs.push_back(M1);
            miner_ptrs.push_back(M1);
           
        }
        else if (code =='S'||code=='s'){
            Soldier* S1=new Soldier(id,a);
            S1->state=code2;
            S1->display_code=code;
            S1->restore(file);
            object_ptrs.push_back(S1);
            active_ptrs.push_back(S1);
            person_ptrs.push_back(S1);
            soldier_ptrs.push_back(S1);
          
        }
        else if (code=='I' || code=='i'){
            Inspector* I1=new Inspector(id,a);
            I1->state=code2;
            I1->display_code=code;
            I1->restore(file);
            object_ptrs.push_back(I1);
            active_ptrs.push_back(I1);
            person_ptrs.push_back(I1);
            inspector_ptrs.push_back(I1);
         
        }
        
        else if (code=='G' || code=='g'){
            Gold_Mine* G1=new Gold_Mine(id,a);
            G1->state=code2;
            G1->display_code=code;
            G1->restore(file);
            object_ptrs.push_back(G1);
            active_ptrs.push_back(G1);
            mine_ptrs.push_back(G1);
           
        }
        else if (code=='T'||code=='t'){
            Town_Hall* T1=new Town_Hall(id,a);
            T1->state=code2;
            T1->display_code=code;
            T1->restore(file);
            object_ptrs.push_back(T1);
            active_ptrs.push_back(T1);
            hall_pts.push_back(T1);
            
        }
}




