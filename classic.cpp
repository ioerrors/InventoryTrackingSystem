#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "classic.h"

Classic::Classic() {

}

Classic::~Classic() {

}

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

bool Classic::addStock(int stock) {
    stock++;
    return true;
}

bool Classic::subStock(int stock) {
    if (stock > 0) {
        stock--;
        return true;
    }

    return false;
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