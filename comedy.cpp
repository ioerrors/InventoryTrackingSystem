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

Comedy::Comedy() {

}

Comedy::~Comedy() {

}

char Comedy::getGenre() const {
	return 'F';
}

void Comedy::setData(string movieData) {

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
		return true;

	} else {
		if(year > otherMovie.getReleaseYear()) {
			return true;
		}
	}

	return false;
}

bool Comedy::operator<(const Movie& otherMovie) const {
    if (this == &otherMovie) return false;
	if (this > &otherMovie) return false;
	return true;
}
