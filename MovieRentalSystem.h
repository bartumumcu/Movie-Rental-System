#ifndef SYSTEM_H
#define SYSTEM_H
#include "Subscriber.h"
#include "Movie.h"
#include "string"
#include "LinkedList.h"
#include <iostream>
//BARTU MUMCU SEC:2 22103523
using namespace std;

class MovieRentalSystem {

public:
LinkedList<Movie> movies;
LinkedList<Subscriber> subs;



MovieRentalSystem( const string movieInfoFileName,const string subscriberInfoFileName );
~MovieRentalSystem();

void removeMovie( const int movieId );
void addMovie( const int movieId, const int numCopies );

void removeSubscriber( const int subscriberId );
void rentMovie( const int subscriberId, const int movieId );
void returnMovie( const int subscriberId, const int movieId );

void showMoviesRentedBy( const int subscriberId ) const;
void showSubscribersWhoRentedMovie( const int movieId ) const;
void showAllMovies() const;
void showAllSubscribers() const;

};

#endif