////////////////////////////////movie.cpp file  /////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a movie class/interface which stores 
// and allows access to various movie attributes
//-----------------------------------------------------------------------------

#include "movie.h"

Movie::Movie() {
  genre = '';
  mediaType = '';
  title = "";
  director = "";
  stock = 0;
  year = 0;
  month = 0;
}


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


