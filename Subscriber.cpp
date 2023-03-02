#include <iostream>
//BARTU MUMCU SEC:2 22103523
#include "Subscriber.h"
using namespace std;
Subscriber::Subscriber(int id){
    this->id=id;
    
}

Subscriber::~Subscriber(){
    rentedmovies.clear();
}

Subscriber::Subscriber(){
    id=0;
}
const int Subscriber::getID() const{
    return this->id;
}

bool Subscriber::operator<(Subscriber s){
        if(this->getID()<s.getID())
        return true;
        else
        return false;
      }

Subscriber& Subscriber::operator=( Subscriber& s){
    if(this!=&s){
        this->id=s.id;
    }
    return *this ;
}
