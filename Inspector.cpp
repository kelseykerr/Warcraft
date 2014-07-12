//
//  Inspector.cpp
//  PA5
//
//  Created by Kelsey Kerr on 11/27/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#include "Inspector.h"

Inspector::~Inspector(){
    cout << "Inspector destroyed." << endl;
}
Inspector::Inspector():Person('I'){
    cout<< "Inspector default constructed." << endl;
}

Inspector::Inspector(int in_id, Cart_Point in_loc):Person('I', in_id, in_loc){
cout<< "Inspector constructed!" << endl;
}


void Inspector::start_inspecting(list <Gold_Mine*> minelist){
    subscript=0;
    minelist2=minelist;
    Cart_Vector distance;
    double truedistance;
    vector<Cart_Point> locations;
    vector<double> dist;
    vector<double> dist2;
    vector<int> order;
    
    for (vector<double>::iterator i=dist.begin();i!=dist.end(); i++)
        i=dist.erase(i);
    for (vector<double>::iterator i=dist2.begin();i!=dist2.end(); i++)
        i=dist2.erase(i);
    for (vector<int>::iterator i=order.begin();i!=order.end(); i++)
        i=order.erase(i);
    for (vector<Cart_Point>::iterator i=locations.begin();i!=locations.end(); i++)
        i=locations.erase(i);
    for (int i=0;i<5;i++)
        goldout[i]=0;
    for (vector<Cart_Point>::iterator i=destinations.begin();i!=destinations.end(); i++)
        i=destinations.erase(i);
   
    for (list<Gold_Mine*>::iterator i=minelist.begin();i!=minelist.end();i++){
        Cart_Point a((*i)->get_location());
        locations.push_back(a);
        Cart_Vector distance(this->get_location()-a);
        truedistance=sqrt((distance.x*distance.x)+(distance.y*distance.y));
        dist.push_back(truedistance);
    }

    for (int i=0; i<dist.size(); i++){
       dist2.push_back(dist[i]);
    }
     sort(dist.begin(), dist.end());
    
    for (int i=0;i<dist.size();i++){
        for (int j=0; j<dist.size(); j++){
            if (dist[i]==dist2[j]){
                order.push_back(j);
            }
        }
    }
     

    int next=order.front();
    Cart_Point one=locations[next];
    destinations.push_back(one);
    for (int i=0; i<locations.size();i++){
      if (locations[i].x==destinations.back().x && locations[i].y==destinations.back().y){
	locations.erase(locations.begin()+i);
      }
    }
    int count=-1;
 
    while (locations.size()>1){
        count=count+1;
        dist.clear(); 
        dist2.clear();
	  order.clear();
        for (int i=0; i<locations.size();i++){
             Cart_Point distance(destinations[count].x-locations[i].x, destinations[count].y-locations[i].y);
            truedistance=sqrt((distance.x*distance.x)+(distance.y*distance.y));
            dist.push_back(truedistance);
        }
        for (int i=0; i<dist.size(); i++){
            dist2.push_back(dist[i]);
            
        }
        sort(dist.begin(), dist.end());
        for (int i=0;i<dist.size();i++){
            for (int j=0; j<dist.size(); j++){
                if (dist[i]==dist2[j])
                    order.push_back(j);
            }
        }
       
         int next=order.front();
    Cart_Point one=locations[next];
    destinations.push_back(one);
    for (int i=0; i<locations.size();i++){
      if (locations[i].x==destinations.back().x && locations[i].y==destinations.back().y){
	locations.erase(locations.begin()+i);
      }
    }
    }
    if (locations.size()==1)
        destinations.push_back(locations[0]);
    
    setup_destination(destinations[0]);
    setstate('k');
    cout << display_code << get_id() << " starting to inspect!" << endl;
    
    
    
}

bool Inspector::update(){
    switch (state){
        case 'k':{//outbound
            bool ans=update_location();
            if (ans==true){
                state='c';
                return true;
            }
            else
                return false;
            break;
        }
        case 'c':{ //counting gold at mine outbound
            Gold_Mine* ptr1;
            for (list<Gold_Mine*>::iterator i=minelist2.begin();i!=minelist2.end();i++){
                if ((*i)->location.x == this->location.x && (*i)->location.y == this->location.y )
                    ptr1= *i;
            }
            goldout[subscript]=(ptr1->amount);
            cout << "This mine contains " << ptr1->amount << " Gold!" <<endl;
            subscript=subscript+1;
            int truesize=getdestinationssize();
            if (subscript<truesize){
            setup_destination(destinations[subscript]);
            state='k';
            }
            else {//setup new destination
                subscript=(subscript-2);
                setup_destination(destinations[subscript]);
                state='j';
                cout << "Heading Back!"<<endl;
            }
            return false;
            break;
        }
    
        case 'j':{//inbound journey
            bool ans=update_location();
            if (ans==true){
                state='l';
                return true;
            }
            else
                return false;
            break;
        }
        case 'l':{//counting gold at mine inbound
            Gold_Mine* ptr1;
            for (list<Gold_Mine*>::iterator i=minelist2.begin();i!=minelist2.end();i++){
                if ((*i)->location.x == this->location.x && (*i)->location.y == this->location.y )
                    ptr1= *i;
            }
            
            cout << "Amount of gold removed from the mine is " << goldout[subscript]-(ptr1->amount) << " gold!" <<endl;
            if (subscript>0){
                subscript=subscript-1;
                 setup_destination(destinations[subscript]);
                state='j';
            }
            else{
                cout <<"Inspection trip completed!" <<endl;
                state='s';
            }
            return false;
            break;
        }
        case 's':{
            state='s';
            return false;
            break;
        }
        case 'x':{
            return false;
            break;
        }
    }
    return true;
}

void Inspector::show_status(){//print out the status of each miner
    cout << "Inspector status: ";
    Person::show_status();
}

void Inspector::save(ofstream& file){
    Person::save(file);
    file<<subscript<< endl;
    for (int i=0; i<4; i++){
            file<<goldout[i]<<endl;
    }
    for (int i=0; i<4; i++){
        if (i<destinations.size())
            file<<destinations[i].x << "\n" << destinations[i].y<<endl;
        else
            file <<-1 << "\n" << -1 << endl;
    }
    for (list<Gold_Mine*>::iterator i=minelist2.begin();i!=minelist2.end();i++){
        file<<(*i)->get_id()<<"\n";
    }
    for (int i=0; i<(4-minelist2.size()); i++){
        file<<0 <<endl;
    }
}

void Inspector::restore(ifstream& file){
    Person::restore(file);
    int num, num1, num2;
    file>>subscript>>num;
    goldout[0]=num;
    file>>num;
    goldout[1]=num;
    file>>num;
    goldout[2]=num;
    file>>num;
    goldout[3]=num;
    file>>num1>>num2;
    Cart_Point a(num1,num2);
    destinations.push_back(a);
    file>>num1>>num2;
    Cart_Point b(num1,num2);
    destinations.push_back(b);
    file>>num1>>num2;
    Cart_Point c(num1,num2);
    destinations.push_back(c);
    file>>num1>>num2;
    Cart_Point d(num1,num2);
    destinations.push_back(d);
    file>>mList2[0]>>mList2[1]>>mList2[2]>>mList2[3];
}

int Inspector::getdestinationssize(){
    int count=0;
    for(int i=0;i<destinations.size();i++){
        if (destinations[i].x != -1 && destinations[i].y != -1)
            count=count+1;
    }
    return count;
}
