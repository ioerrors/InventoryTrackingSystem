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

Drama::Drama() {

}

Drama::~Drama() {

}

char Drama::getGenre() const {
    return 'D';
}

void Drama::setData(string movieData) {
    
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

	} else {
		if (title > otherMovie.getTitle()) {
			return true;
		}
	}

	return false;
}

bool Drama::operator<(const Movie& otherMovie) const {
    if (this == &otherMovie) return false;
	if (this > &otherMovie) return false;
	return true;
}

#endif