///////////////////////////////MovieFactory.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to build the movie objects
//-----------------------------------------------------------------------------
#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "classic.h"
#include "comedy.h"
#include "drama.h"

class MovieFactory {
public:
  //---------------------------------------------------------------------------
  // MovieFactory CONSTRUCTOR
  // Description: creates an empty Movie
  // PRE: memory is available for Movie
  // POST: empty Movie is created
  MovieFactory();  // constructor

  //---------------------------------------------------------------------------
  // Customer DESTRUCTOR
  // Description: deallocates all memory allocated for Customer
  // PRE: Movie exists
  // POST: all Movie memory is freed
  ~MovieFactory(); // destructor

  //---------------------------------------------------------------------------
  // getMovie()
  // Description: returns constructor based on movie type
  // PRE: Movie type and constructor for type C, F, D exists
  // POST: a movie constructor is returned if the movie type given is valid
  Movie *getMovie(string type);
};
#endif
