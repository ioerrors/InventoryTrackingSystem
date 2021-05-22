////////////////////////////////comedy.h file  ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a comedy class which is a type of movie 
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

class Comedy : public Movie {
public:

    Comedy(char genre, char mediaType, string title, string director,
           int stock, int yearRelease);         // constructor
    ~Comedy();                                  // destructor
    
    // Overloaded operators
    virtual bool operator==(const Movie& otherMovie) const;   // check if movies are equal
    virtual bool operator != (const Movie& otherMovie) const; // check if movies are not equal
    virtual bool operator > (const Movie& otherMovie) const;  // check if this movie is greater than other movie
    virtual bool operator < (const Movie& otherMovie) const;  // check if this movie is less than other movie
};