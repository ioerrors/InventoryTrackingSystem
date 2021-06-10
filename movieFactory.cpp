///////////////////////////////MovieFactory.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to build the movie objects
//-----------------------------------------------------------------------------

#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "movie.h"
#include "movieFactory.h"

//-----------------------------------------------------------------------------
// MovieFactory CONSTRUCTOR
// Description: creates an empty Movie
// PRE: memory is available for Movie
// POST: empty Movie is created
MovieFactory::MovieFactory() {}

//-----------------------------------------------------------------------------
// Customer DESTRUCTOR
// Description: deallocates all memory allocated for Customer
// PRE: Movie exists
// POST: all Movie memory is freed
MovieFactory::~MovieFactory() {}

//-----------------------------------------------------------------------------
// getMovie()
// Description: returns constructor based on movie type
// PRE: Movie type and constructor for type C, F, D exists
// POST: a movie constructor is returned if the movie type given is valid
Movie *MovieFactory::getMovie(string type) {
  if (type == "C," || type == "C") {
    return new Classic();
  }
  if (type == "F," || type == "F") {
    return new Comedy();
  }
  if (type == "D," || type == "D") {
    return new Drama();
  } else {
    cout << "Invalid movie genre: " << type << endl << endl;
    return nullptr;
  }
}
