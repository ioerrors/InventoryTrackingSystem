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

string Drama::getTitle() const {
    return this->title;
}

string Drama::getDirector() const {
    return this->director;
}

int Drama::getStock() const {
    return this->stock;
}

int Drama::getReleaseYear() const {
    return year;
}

bool Drama::addStock(int) {

}

bool Drama::subStock(int) {

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