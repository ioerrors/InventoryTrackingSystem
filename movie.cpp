////////////////////////////////movie.cpp file  /////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a movie class/interface which stores 
// and allows access to various movie attributes
//-----------------------------------------------------------------------------

#include "movie.h"
#include <iterator>
#include <set>

using namespace std;




//-----------------------------------------------------------------------------
// Overloaded Operator <<
// Description: prints movie contents to ostream
// PRE: Movie exists
// POST: All contained data fields are printed in order
ostream &operator<<(ostream &os, const Movie& mov) {
  if (mov.getGenre() == 'C') {
    string data = "D ";
    os << data;
    os << mov.getStock() + " ";
    os << mov.getGenre() + " ";
    os << mov.getDirector() + ", ";
    os << mov.getTitle() + ", ";
    std::copy(mov.getActors().begin(), mov.getActors().end(),
              std::ostream_iterator<std::string>(os, ","));
    os << mov.getMonth() + " ";
    os << mov.getReleaseYear();
    os << endl;
  } else {
	string data = "D ";
    os << data;
    os << mov.getStock() + " ";
    os << mov.getGenre() + " ";
    os << mov.getDirector() + ", ";
    os << mov.getTitle() + ", ";
    os << mov.getReleaseYear();
    os << endl;
  }
  return os;
}


Movie::Movie() {
  genre = '`';
  mediaType = 'D';
  title = "";
  director = "";
  stock = 0;
  year = 0;
  month = 0;
}

Movie::~Movie() {}

string Movie::getTitle() const {
    // do we need this?
    return this->title;
}

string Movie::getDirector() const {
    return this->director;
}

int Movie::getStock() const {
    return this->stock;
}

int Movie::getReleaseYear() const {
    return this->year;
}

bool Movie::addStock(int newStock) {
    if (newStock > 0) {
      stock += newStock;
      return true;      
    } else {
      return false;
    }

}

bool Movie::subStock(int removeStock) {
    if (stock > 0) {
      stock -= removeStock;
      return true;
    } else {
      return false;
    }

}


