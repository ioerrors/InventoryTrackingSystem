////////////////////////////////classic.cpp file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a Classic class which is a type of Movie 
// child of the Movie class, inheriting from Movie
//-----------------------------------------------------------------------------


#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "classic.h"

//-----------------------------------------------------------------------------
// Classic CONSTRUCTOR
// Description: creates an empty Classic
// PRE: Memory is available for Classic
// POST: Empty Classic is created
Classic::Classic() {

}

//-----------------------------------------------------------------------------
// Classic DESTRUCTOR
// Description: deallocates all memory allocated for Classic
// PRE: Classic exists
// POST: All Classic memory is freed
Classic::~Classic() {

}

//-----------------------------------------------------------------------------
// Classic 
// Description: 
// PRE: 
// POST: 
char Classic::getGenre() const {
    return 'C';
}

string Classic::getTitle() const {
    // do we need this?
    return this->title;
}

string Classic::getDirector() const {
    return this->director;
}

int Classic::getStock() const {
    return this->stock;
}

int Classic::getReleaseYear() const {
    return this->year;
}

bool Classic::addStock(int newStock) {
    if (newStock > 0) {
      stock += newStock;
      return true;      
    } else {
      return false;
    }

}

bool Classic::subStock(int removeStock) {
    if (stock > 0) {
      stock -= removeStock;
      return true;
    } else {
      return false;
    }

}

//We have BSTree Movies being build in business.cpp
//inside business.cpp we find out if the movie is equal to a movie in the
//Is this node equal to an existing node??
// If yes, then do the below: 
void Classic::addSameMovies(const Movie& otherMovie) {
  //add the stock together
  addStock(otherMovie.getStock());
  

  //add the other movie's entire list of actors
  set<string> otherList = otherMovie.getActorsList();
  actorsList.insert(otherList.begin(), otherList.end());

}

// get the actors of the movie object
set<string> Classic::getActors() const { 
  return actorsList;
}   


//-----------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: classic exists, 
//    assumed format "Hal Ashby, Harold and Maude, Ruth Gordon 3 1971"    
// POST: 
void Classic::setData(string movieData) {

  //usable for any movie:
  stringstream ss(movieData);
  char delimeter = ',';
  string data;
  getline(ss, data, ',');
  director = data;
  data = "";
  getline(ss, data, ',');
  title = data;

  //specific to Classic:
  string first;
  string last;
  ss >> first;
  ss >> last;
  string name = first + " " + last;
  actorsList.insert(name);

  data = "";
  ss >> data;
  month = (int) data;

  //use for any movie:
  data = "";
  ss >> data;
  year = (int) data;
}

bool Classic::operator==(const Movie& otherMovie) const {
    return (director == otherMovie.getDirector() && title == otherMovie.getTitle());
}

bool Classic::operator!=(const Movie& otherMovie) const {
    return !(this == &otherMovie);   
}

bool Classic::operator>(const Movie& otherMovie) const {
    Classic *ptr = dynamic_cast<Classic*>(&otherMovie);
    return  *this > *ptr;
}

bool Classic::operator<(const otherMovie&) const {
    Classic *ptr = dynamic_cast<Classic*>(&otherMovie);
    return  *ptr > *this;
}

#endif