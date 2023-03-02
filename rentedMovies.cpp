#include "rentedMovies.h"
#include <iostream>
using namespace std;
//BARTU MUMCU SEC:2 22103523
    rentedMovies::rentedMovies(){
        isReturned=false;
        
    }
    rentedMovies::rentedMovies(int movieid){
        movieID=movieid;
        isReturned=false;
        
    }

    bool rentedMovies::operator < (rentedMovies const &mov) const{
        if(movieID < mov.movieID){
            return true;
        }else
            return false;
    }


