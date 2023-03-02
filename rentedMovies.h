#ifndef RENTED_H
#define RENTED_H
#include <iostream>
using namespace std;
//BARTU MUMCU SEC:2 22103523
class rentedMovies{
    public:
    bool isReturned;
    int movieID;
    
    rentedMovies();
    
    rentedMovies(int movieid);

    bool operator < (rentedMovies const &mov) const;

};
#endif