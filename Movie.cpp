#include <iostream>
#include "Movie.h"
using namespace std;
//BARTU MUMCU SEC:2 22103523
Movie::Movie(int theid,int numcopy){
    this->initialcopyNo=numcopy;
    this->id=theid;
    this->currentcopyno=numcopy;
}

Movie::Movie(){
      id=0;
      initialcopyNo=0;
      currentcopyno=0;
    }
    
Movie& Movie::operator=(const Movie&m){
    if(this!=&m){
        this->id=m.id;
        this->initialcopyNo=m.initialcopyNo;
        this->currentcopyno=m.currentcopyno;
    }
    return *this ;
}
const int Movie::getID() const{
    return this->id;
}

const int Movie::getInitialCopyNo(){
    return this->initialcopyNo;
}

const int Movie::getCurCopyNo(){
    return this->currentcopyno;
}

const void Movie::setCurCopyNo(int copy){
    this->currentcopyno=copy;
}