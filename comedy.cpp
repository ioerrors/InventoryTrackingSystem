////////////////////////////////comedy.cpp file  ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a comedy class which is a type of movie 
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

#ifndef COMEDY_CPP
#define COMEDY_CPP

#include "comedy.h"


//-----------------------------------------------------------------------------
// Comedy CONSTRUCTOR
// Description: creates an empty Comedy
// PRE: Memory is available for Comedy
// POST: Empty Comedy is created
Comedy::Comedy() {
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
Comedy::~Comedy() {
    char genre;                                     // genre of the movie
    char mediaType;                                 // media type of the movie
    string title;                                   // title of movie
    string director;                                // director of movie
    int stock;                                      // number of movie left in stock
    int year;                                       // year released
    int month;                                      // month released
}

char Comedy::getGenre() const {
	return 'F';
}

//-----------------------------------------------------------------------------
// setData()
// Description: sets data fields
// PRE: Comedy exists, stock is already set using addStock()
//    input format "Rob Reiner, When Harry Met Sally, 1989"    
// POST: all data fields set
void Comedy::setData(string movieData) {
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

bool Comedy::operator==(const Movie& otherMovie) const {
	return (title == otherMovie.getTitle()) && 
	(year == otherMovie.getReleaseYear());
}

bool Comedy::operator!=(const Movie& otherMovie) const {
    return !(this == &otherMovie);
}

bool Comedy::operator>(const Movie& otherMovie) const {
    if (title > otherMovie.getTitle()) {
		return true; // title is greater
	} else (title == otherMovie.getTitle()) {
		if(year > otherMovie.getReleaseYear()) {
			return true; // release is greater(more recent)
		}
		return false; // release is less or same
	}
	return false; // title is less
}

bool Comedy::operator<(const Movie& otherMovie) const {
    if (this == &otherMovie) return false;
	if (this > &otherMovie) return false;
	return true;
}
