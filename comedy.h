////////////////////////////////comedy.h file  ////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a comedy class which is a type of movie 
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:

	//---------------------------------------------------------------------------
	// Comedy CONSTRUCTOR
	// Description: creates an empty Comedy
	// PRE: Memory is available for Comedy
	// POST: Empty Comedy is created
	Comedy();         // constructor

	//-----------------------------------------------------------------------------
	// Comedy DESTRUCTOR
	// Description: deallocates all memory allocated for Comedy
	// PRE: Comedy exists
	// POST: all Comedy memory is freed
	virtual ~Comedy();        // destructor

	//---------------------------------------------------------------------------
	// getGenre()
	// Description: returns the genre type
	// PRE: assumes genre set to return is valid
	// POST: the genre type is returned
	string getGenre() const;

  //---------------------------------------------------------------------------
  // getTitle()
  // Description: returns the title
  // PRE: assumes title exist
  // POST: the title is returned
	string getTitle() const;       

	//---------------------------------------------------------------------------
  // getDirector()
  // Description: returns the director name
  // PRE: assumes director name exist
  // POST: the director name is returned
	string getDirector() const;

	//---------------------------------------------------------------------------
  // getStock()
  // Description: returns the stock amount
  // PRE: assumes stock amount exist
  // POST: the stock amount is returned
	int getStock() const;

	//---------------------------------------------------------------------------
  // getReleaseYear()
  // Description: returns the release year
  // PRE: assumes the release year exist
  // POST: the release year is returned
	int getReleaseYear() const;

 	//---------------------------------------------------------------------------
  // addStock()
  // Description: adds stock when a movie is returned
  // PRE: assumes that the movie exist
  // POST: adds 1 to the stock counter
	bool addStock(int); 

	//---------------------------------------------------------------------------
  // subStock()
  // Description: subs stock when a movie is borrow
  // PRE: assumes that the movie exist
  // POST: subs 1 on the stock counter
	bool subStock(int);

	//---------------------------------------------------------------------------
	// setData()
	// Description: sets data fields
	// PRE: Comedy exists, stock is already set using addStock()
	//    input format "Rob Reiner, When Harry Met Sally, 1989"
	// POST: all data fields set
	bool setData(string movieData);

	// Overloaded operators
	//---------------------------------------------------------------------------
	// operator ==
	// Description: checks if the movies are equal
	// PRE: assumes that the movies exist
	// POST: returns true if the movies are equal
	bool operator==(const Movie& otherMovie) const;   // check if movies are equal
	
	//---------------------------------------------------------------------------
	// operator !=
	// Description: checks if the movies are not equal
	// PRE: assumes that the movies exist
	// POST: returns true if the movies are not equal
	bool operator!=(const Movie& otherMovie) const; // check if movies are not equal
	
	//---------------------------------------------------------------------------
	// operator >
	// Description: checks if the title and release year of LHS is greater
	//              than RHS
	// PRE: assumes that the movies exist
	// POST: returns true if the LHS movie is sorted greater than the
	//       RHS movie
	bool operator>(const Movie& otherMovie) const;  // check if this movie is greater than other movie
	
	//---------------------------------------------------------------------------
	// operator <
	// Description: checks if the title and release year of LHS is less
	//              than RHS
	// PRE: assumes that the movies exist
	// POST: returns true if the LHS movie is sorted lesser than the
	//       RHS movie
	bool operator<(const Movie& otherMovie) const;  // check if this movie is less than other movie
};

#endif
