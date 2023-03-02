#ifndef SUBS_H
#define SUBS_H
#include <iostream>
#include "LinkedList.h"
#include "Movie.h"
#include "rentedMovies.h"
using namespace std;
//BARTU MUMCU SEC:2 22103523
class Subscriber{
    public:

    LinkedList<rentedMovies> rentedmovies;

    bool operator<(Subscriber s);
    Subscriber& operator=(Subscriber& s);
    
    Subscriber( int id);
    Subscriber();
    ~Subscriber();

    const int getID() const ;

    private:

    int id;
    

};
#endif