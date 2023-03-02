#include <iostream>
#include "MovieRentalSystem.h"
#include <string>
#include <fstream>
using namespace std;
//BARTU MUMCU SEC:2 22103523

MovieRentalSystem::MovieRentalSystem( const string movieInfoFileName,const string subscriberInfoFileName ){


int number,count;
ifstream inputFile;
bool check=true;


inputFile.open( movieInfoFileName.c_str(), ios_base::in );
if(!inputFile.is_open()){
    cout<<"Input file "<<movieInfoFileName<<" does not exist"<<endl;
    return ;
}
else{
inputFile >> number;

while ( inputFile.eof() == false ) {
    
    inputFile>>number;
    inputFile>>count;
    for(int i=1;i<=movies.itemCount;i++){
        if(movies.getNode(i)->item.getID()==number){
            check=false;
            
        }
    }
    if(check){
    Movie m(number,count);
    movies.sortedInsert(movies.headPtr,m);
    }
    check=true;
}


inputFile.close();
}
    
inputFile.open(subscriberInfoFileName,ios_base::in);

if(!inputFile.is_open()){
    cout<<"Input file "<<subscriberInfoFileName<<" does not exist"<<endl;
    return;
}
else{
inputFile>>number;
while(inputFile.eof()== false){
    inputFile>>number;

    for(int i=1;i<=subs.itemCount;i++){
        if(subs.getNode(i)->item.getID()==number){
            check=false;
            
        }
    }
    if(check){
    Subscriber s(number);
    subs.sortedInsert(subs.headPtr,s);
    }
    check=true;
    
}
inputFile.close();
}

cout<<subs.itemCount<<" subscribers and "<<movies.itemCount<<" movies have been loaded"<<endl;
}

MovieRentalSystem::~MovieRentalSystem(){
    movies.clear();
    subs.clear();
}

 void MovieRentalSystem::removeMovie( const int movieId ){
    bool movieFound=false;
    int movieIndex;
    for(int i=1;i<=movies.itemCount;i++){
        if(movies.getNode(i)->item.getID()==movieId){
            movieFound=true;
            movieIndex=i;
            
        }
    }
    if(!movieFound){
        cout<<"Movie "<<movieId<<" does not exist"<<endl; 
        return;
    }

    for(int i=1;i<=subs.itemCount;i++){
        for(int j=1;j<=subs.getNode(i)->item.rentedmovies.itemCount;j++){
            if(subs.getNode(i)->item.rentedmovies.getNode(j)->item.movieID==movieId){
             if(!subs.getNode(i)->item.rentedmovies.getNode(j)->item.isReturned){
                cout<<"Movie "<< movieId<<" cannot be removed -- at least one copy has not been returned"<<endl;
                return;
             }
                
            }
        }
    }
    movies.remove(movieIndex);
    cout<<"Movie "<<movieId<<" has been removed" <<endl;

 }



 void MovieRentalSystem::addMovie( const int movieId, const int numCopies ){

    for(int i=0;i<movies.itemCount;i++){
        if(movies.getNode(i)->item.getID()==movieId){
            cout<<"Movie "<<movieId<<" already exists"<<endl;
            return;
        }
    }
    Movie m(movieId,numCopies);
    movies.sortedInsert(movies.headPtr,m);
    cout<<"Movie "<<movieId<<" has been added"<<endl;
}

 void MovieRentalSystem::removeSubscriber( const int subscriberId ){
    bool subFound=false;
    int subIndex;
    
    for(int i=1;i<=subs.itemCount;i++){
        if(subs.getNode(i)->item.getID()==subscriberId){
            subFound=true;
            subIndex=i;
            }
        }

        if(!subFound){
            cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
            return;
        }
    
        for(int j=1;j<=subs.getNode(subIndex)->item.rentedmovies.itemCount;j++){
            if(!subs.getNode(subIndex)->item.rentedmovies.getNode(j)->item.isReturned){
               cout<<"Subscriber "<<subscriberId<<" cannot be removed -- at least one movie has not been returned"<<endl;
               return; 
        }   
    }
        subs.getNode(subIndex)->item.rentedmovies.clear();
        subs.remove(subIndex);
        cout<<"Subscriber "<<subscriberId<<" has been removed"<<endl;

 }

 void MovieRentalSystem::rentMovie( const int subscriberId, const int movieId ){
    bool movieFound=false;
    bool subFound=false;
    int movieIndex;
    int subIndex;

    for(int i=1;i<=movies.itemCount;i++){
        
        if(movies.getNode(i)->item.getID()==movieId){
            movieFound=true;
            movieIndex=i;
            
        }
    }
    
    for(int i=1;i<=subs.itemCount;i++){
        if(subs.getNode(i)->item.getID()==subscriberId){
            subFound=true;
            subIndex=i;
            }
        }


    if(!movieFound&&subFound){
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
        return;
    }
    else if(!subFound&&movieFound){
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
        return;
        }
    else if(!subFound&&!movieFound){
        cout<<"Subscriber "<<subscriberId<<" and movie "<<movieId<<" do not exist"<<endl;
        return;
    }
             
    if(movies.getNode(movieIndex)->item.getCurCopyNo()==0){
         cout<<"Movie "<<movies.getNode(movieIndex)->item.getID()<<" has no available copy for renting"<<endl;   
       return;
    }

    movies.getNode(movieIndex)->item.setCurCopyNo(movies.getNode(movieIndex)->item.getCurCopyNo()-1);
    rentedMovies rented(movieId);
    subs.getNode(subIndex)->item.rentedmovies.sortedInsert(subs.getNode(subIndex)->item.rentedmovies.headPtr,rented);
   cout<<  "Movie "<< movieId<<" has been rented by subscriber "<< subscriberId<<endl; 
        

}
 

 void MovieRentalSystem::returnMovie( const int subscriberId, const int movieId ){
    bool movieFound=false;
    bool subFound=false;
    bool didRentalOccur=false;
    int movieIndex;
    int subIndex;

    for(int i=1;i<=movies.itemCount;i++){
        
        if(movies.getNode(i)->item.getID()==movieId){
            movieFound=true;
            movieIndex=i;
            
        }
    }
    
    for(int i=1;i<=subs.itemCount;i++){
        if(subs.getNode(i)->item.getID()==subscriberId){
            subFound=true;
            subIndex=i;
            }
        }


    if(!movieFound&&subFound){
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
        return;
    }
    else if(!subFound&&movieFound){
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
        return;
        }
    else if(!subFound&&!movieFound){
        cout<<"Subscriber "<<subscriberId<<" and movie "<<movieId<<" do not exist"<<endl;
        return;
    }
             
    for(int i=1;i<=subs.getNode(subIndex)->item.rentedmovies.itemCount;i++){
        if(subs.getNode(subIndex)->item.rentedmovies.getNode(i)->item.movieID==movieId){
            didRentalOccur=true;
            if(!subs.getNode(subIndex)->item.rentedmovies.getNode(i)->item.isReturned){
                subs.getNode(subIndex)->item.rentedmovies.getNode(i)->item.isReturned=true;
                movies.getNode(movieIndex)->item.setCurCopyNo(movies.getNode(movieIndex)->item.getCurCopyNo()+1);
                cout<<"Movie "<< movieId<<" has been returned by subscriber "<<subscriberId<<endl;
                return;
            }
        }
    }
    if(!didRentalOccur){
        cout<<"No rental transaction for subscriber "<<subscriberId<<" and movie "<<movieId<<endl;
        return;
    }
    cout<<"No rental transaction for subscriber "<<subscriberId<<" and movie "<<movieId<<endl;

 }




 void MovieRentalSystem::showMoviesRentedBy( const int subscriberId ) const{
    bool subFound=false;
    int subIndex;
    for(int i=1;i<=subs.itemCount;i++){
        if(subs.getNode(i)->item.getID()==subscriberId){
            subFound=true;
            subIndex=i;
            break;
            }
        }
        if(!subFound){
            cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
            return;
        }
    
    if(subs.getNode(subIndex)->item.rentedmovies.itemCount==0){
        cout<<"Subscriber "<<subscriberId<<" has not rented any movies"<<endl;
        return;
    }
    cout<<"Subscriber "<<subscriberId<<" has rented the following movies:"<<endl;
    for(int i=1;i<=subs.getNode(subIndex)->item.rentedmovies.itemCount;i++){
        cout<<subs.getNode(subIndex)->item.rentedmovies.getNode(i)->item.movieID;
        if(subs.getNode(subIndex)->item.rentedmovies.getNode(i)->item.isReturned)
        cout<<" returned"<<endl;
        else if(!subs.getNode(subIndex)->item.rentedmovies.getNode(i)->item.isReturned)
        cout<<" not returned"<<endl;
    }
 }




 void MovieRentalSystem::showSubscribersWhoRentedMovie( const int movieId ) const{
    bool movieFound=false;
    int movieIndex;
    int count=0;
    for(int i=1;i<=movies.itemCount;i++){
        if(movies.getNode(i)->item.getID()==movieId){
            movieFound=true;
            movieIndex=i;
            
        }
    }
    if(!movieFound){
        cout<<"Movie "<<movieId<<" does not exist"<<endl; 
        return;
    }

for(int i=1;i<=subs.itemCount;i++){
        for(int j=1;j<=subs.getNode(i)->item.rentedmovies.itemCount;j++){
            if(subs.getNode(i)->item.rentedmovies.getNode(j)->item.movieID==movieId){
                count++;
            }
        }
    }
    if(count==0){
        cout<<"Movie "<<movieId<<" has not been rented by any subscriber"<<endl;
        return;
    }

    cout<<"Movie "<<movieId<<" has been rented by the following subscribers:"<<endl;
    for(int i=1;i<=subs.itemCount;i++){
        for(int j=1;j<=subs.getNode(i)->item.rentedmovies.itemCount;j++){
            if(subs.getNode(i)->item.rentedmovies.getNode(j)->item.movieID==movieId){
                cout<<subs.getNode(i)->item.getID();
                if(subs.getNode(i)->item.rentedmovies.getNode(j)->item.isReturned)
                cout<<" returned"<<endl;
                else if(!subs.getNode(i)->item.rentedmovies.getNode(j)->item.isReturned)
                cout<<" not returned"<<endl;
            }
        }
    }
 }
    

 void MovieRentalSystem::showAllMovies() const{
    cout<<"Movies in the movie rental system:"<<endl;
    for(int i=1;i<=movies.itemCount;i++){
        cout<<movies.getNode(i)->item.getID()<<" "<<movies.getNode(i)->item.getInitialCopyNo()<<endl;
    }
 }

 void MovieRentalSystem::showAllSubscribers() const{
    cout<<"Subscribers in the movie rental system:"<<endl;
    for(int i=1;i<=subs.itemCount;i++){
        cout<<subs.getNode(i)->item.getID()<<endl;
    }
 }
