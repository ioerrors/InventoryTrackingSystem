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

void Classic::addSameMovies(Movie*&) {

}

void Classic::setData(string movieData) {
    // stringstream?
}

bool Classic::operator==(const Movie& otherMovie) const {
    return (director == otherMovie.getDirector() && title == otherMovie.getTitle());
}

bool Classic::operator!=(const Movie& otherMovie) const {
    return !(this == &otherMovie);   
}

bool Classic::operator>(const Movie& otherMovie) const {
    Classic * ptr = dynamic_cast<Classic*>(&otherMovie);
    return  *this > *ptr;
}

bool Classic::operator<(const otherMovie&) const {
    Classic * ptr = dynamic_cast<Classic*>(&otherMovie);
    return  *ptr > *this;
}

#endif