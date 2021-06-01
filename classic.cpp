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
    return this->title;
}

string Classic::getDirector() const {
    return this->director;
}

int Classic::getStock() const {
    return this->stock;
}

int Classic::getReleaseYear() const {
    return year;
}

bool Classic::addStock(int) {

}

bool Classic::subStock(int) {

}

void Classic::addSameMovies(Movie*&) {

}

void Classic::setData(string movieData) {
    
}

bool Classic::operator==(const otherMovie&) const {
    return (director == otherMovie.getDirector() && title == otherMovie.getTitle());
}

bool Classic::operator!=(const otherMovie&) const {
    return !(this == &otherMovie)   
}

bool Classic::operator>(const otherMovie&) const {

}

bool Classic::operator<(const otherMovie&) const {
    
}

#endif