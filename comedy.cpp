#ifndef COMEDY_CPP
#define COMEDY_CPP

#include "comedy.h"

Comedy::Comedy() {

}

Comedy::~Comedy() {

}

char Comedy::getGenre() const {

}

string Comedy::getTitle() const {

}

int Comedy::getStock() const {

}

int Comedy::getReleaseYear() const {

}

bool Comedy::addStock(int) {

}

bool Comedy::subStock(int) {

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
