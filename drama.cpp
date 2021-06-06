////////////////////////////////drama.cpp file  /////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a drama class which is a type of movie 
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

#ifndef DRAMA_CPP
#define DRAMA_CPP

#include "drama.h"


//-----------------------------------------------------------------------------
// Comedy CONSTRUCTOR
// Description: creates an empty Comedy
// PRE: Memory is available for Comedy
// POST: Empty Comedy is created
Drama::Drama() {
  genre = '';                                   
  mediaType = '';                               
  title = "";           
  director = "";                               
  stock = 0;                                      
  year = 0;                                      
  month = 0;   
}


//-----------------------------------------------------------------------------
// Comedy DESTRUCTOR
// Description: deallocates all memory allocated for Comedy
// PRE: Comedy exists
// POST: All Comedy memory is freed
Drama::~Drama() {
  delete genre;                                   
  delete mediaType;                               
  delete title;           
  delete director;                               
  delete stock;                                      
  delete year;                                      
  delete month;
  delete actorsList;  
}

char Drama::getGenre() const {
    return 'D';
}

//-----------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: Drama exists, stock is already set using addStock()
//    input format "Phillippe De Broca, King of Hearts, 1967"    
// POST: all data fields set
void Drama::setData(string movieData) {
  stringstream ss(movieData);
  char delimeter = ',';
  string data;
  
  // get director
  getline(ss, data, ',');
  director = data;
  data = "";

  // get title
  getline(ss, data, ',');
  title = data;

  // get year
  data = "";
  ss >> data;
  year = (int) data;    
}

bool Drama::operator==(const Movie& otherMovie) const {
    return (director == otherMovie.getDirector() && title == otherMovie.getTitle());
}

bool Drama::operator!=(const Movie& otherMovie) const {
    return !(this == &otherMovie)   
}

bool Drama::operator>(const Movie& otherMovie) const {
  if (director > otherMovie.getDirector()) {
    return true; 
  } else if (director == otherMovie.getDirector()) {
    return title > otherMovie.getTitle();
  }
  return false;
}

bool Drama::operator<(const Movie& otherMovie) const {
    if (this == &otherMovie) return false;
  if (this > &otherMovie) return false;
  return true;
}

#endif