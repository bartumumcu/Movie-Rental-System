#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
using namespace std;
//BARTU MUMCU SEC:2 22103523
class Movie{
    public:
    
    bool operator<(Movie m){
        if(this->getID()<m.getID())
        return true;
        else
        return false;
      }
    Movie();
  bool operator<=(Movie m){
        if(this->getID()<=m.getID())
        return true;
        else
        return false;
      }

    Movie& operator=(const Movie&m);
    Movie(int theid,int numcopy);
   
    const int getID() const;
    const int getInitialCopyNo();
    const int getCurCopyNo();
    const void setCurCopyNo(int copy);

    private:
    int id, initialcopyNo,currentcopyno;
    
};
#endif