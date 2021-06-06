////////////////////////////////classic.cpp file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a Classic class which is a type of Movie 
// child of the Movie class, inheriting from Movie
//-----------------------------------------------------------------------------
// Note on implemenation:
// 
// in the data4movies.txt
// C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
// C, 10, George Cukor, Holiday, Cary Grant 9 1938
// 
// could be built into the movie set as:
// 
// C, 20, George Cukor, Holiday, <Katherine Hepburn, Cary Grant> 9 1938
// 
// OR into the movie set as:
// 
// C, 20, George Cukor, Holiday, Katherine Hepburn 9 1938
// C, 20, George Cukor, Holiday, Cary Grant 9 1938
// 
// These could both be valid based on the design document 
// 
// "In addition, for classical movies, one movie (e.g., Holiday) 
// may have multiple lines so the total stock of this movie 
// will be the sum of all the stocks in the lines about this movie
// (e.g., 20 for Holiday in the above example)."
// 
// We have implemented one object per movie, with a list of actors.
// This requires the addition of one check for title after checking the 
// normal sorting criteria of Release date --> Actor for Classics 
// which if positive will add to the existing actor list 
// rather than return a false negative in comparison operations


#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "classic.h"

//-----------------------------------------------------------------------------
// Classic CONSTRUCTOR
// Description: creates an empty Classic
// PRE: Memory is available for Classic
// POST: Empty Classic is created
Classic::Classic() {
  genre = '';                                   
  mediaType = '';                               
  title = "";           
  director = "";                               
  stock = 0;                                      
  year = 0;                                      
  month = 0;                                      
}

//-----------------------------------------------------------------------------
// Classic DESTRUCTOR
// Description: deallocates all memory allocated for Classic
// PRE: Classic exists
// POST: All Classic memory is freed
Classic::~Classic() {
  delete genre;                                   
  delete mediaType;                               
  delete title;           
  delete director;                               
  delete stock;                                      
  delete year;                                      
  delete month;
  delete actorsList;  
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

int Classic::getMonth() const {
    return this->month;
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

// get the actors of the movie object
set<string> Classic::getActors() const { 
  return actorsList;
}   


//-----------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: classic exists, stock is already set using addStock()
//    input format "Hal Ashby, Harold and Maude, Ruth Gordon 3 1971"    
// POST: all data fields set
bool Classic::setData(string movieData) {

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
  return  true;
}

bool Classic::operator!=(const Movie& otherMovie) {
  return !(this == &otherMovie);   
}


//-----------------------------------------------------------------------------
bool Classic::operator==(const Movie& otherMovie) {
  if(otherMovie.getGenre() != 'C') {
    return false;
  }
  if (month != otherMovie.getMonth()) {
    return false;
  }
  if (year != otherMovie.getReleaseYear()) {
    return false;
  }
  if (actorsList != otherMovie.getActors()) { // check actor
    if (title == otherMovie.getTitle()) { // still same movie, new actor
      //add the other movie's entire list of actors to this movie object
      actorsList.insert(otherMovie.getActors().begin(),
    		  	  	    otherMovie.getActors().end());
      return true;      
    } else {
      return false; //different release date, actors, and different title
    }
  }
  return true; //release date and actors are the same
}



//-----------------------------------------------------------------------------
// this > otherMovie
bool Classic::operator>(const Movie& otherMovie) {
  if(this != otherMovie) { 
    if(otherMovie.getGenre() == 'C') {
      if (year > otherMovie.getReleaseYear()) {
        return true; //this movie release year is greater(more recent)   
      } else if (year == otherMovie.getReleaseYear() 
          && month > otherMovie.getMonth()) {
            return true; //this movie release month is greater (more recent)
        } else if (year == otherMovie.getReleaseYear() 
                  && month == otherMovie.getMonth()) { //same release date
            //alphabetically Last actor in both lists is used as sorting actor
            return actorsList.end() > otherMovie.getActors().end();
        }    
        return false; // this movie is less recent
      } 
      // this classic movie is sorted greater than other movie types
    return true;   
  } 
  return false;   // this movie is the same movie
}



// this < otherMovie
bool Classic::operator<(const Movie& otherMovie) {
  if(this != otherMovie) { 
    return (!(this > otherMovie)); 
  }
  return false; 
}
