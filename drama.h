////////////////////////////////drama.h file  /////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a drama class which is a type of movie 
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

class Drama : public Movie {
public:
    
    Drama(char genre, char mediaType, string title, string director,
          int stock, int yearRelease);      // constructor
    ~Drama();                               // destructor
    
    // Overloaded operators
    virtual bool operator==(const Movie& otherMovie) const;   // check if movies are equal
    virtual bool operator != (const Movie& otherMovie) const; // check if movies are not equal
    virtual bool operator > (const Movie& otherMovie) const;  // check if this movie is greater than rhs movie
    virtual bool operator < (const Movie& otherMovie) const;  // check if this movie is less than rhs movie
};