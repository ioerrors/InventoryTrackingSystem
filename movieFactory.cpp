///////////////////////////////MovieFactory.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to build the movie objects
//-----------------------------------------------------------------------------

#include "classic.h"
#include "comedy.h"
#include "drama.h"

#include "movieFactory.h"

MovieFactory::MovieFactory() {}

MovieFactory::~MovieFactory() {}

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
