///////////////////////////////MovieFactory.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to build the movie objects
//-----------------------------------------------------------------------------
#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H


#include "classic.h"
#include "comedy.h"
#include "drama.h"

//#include "transactionFactory.h"


class MovieFactory {
public:


    MovieFactory();              // constructor
    ~MovieFactory();             // destructor

    Movie getMovie(char type) {
        switch (type) {
            case type == 'C':
                return new Classic();
            case type == 'F':
                return new Comedy();
            case type == 'D':
                return new Drama();
            default:
                throw;
        }
    }
};
#endif
